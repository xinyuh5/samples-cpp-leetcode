class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        return helper(n, "1", 1);
    }
private:
    string helper(int n, string s, int m){
        //std::cout<<"n"<<n<<"s"<<s<<"m"<<m<<std::endl;
        if (m >= n) return s;
        if (m == 1){return helper(n, "11", m+1);}
        int count = 1;
        int l = s.length();
        string next;
        next.push_back(s[l-1]);
        int j = l-2;
        for (int i = l-1; i > 0; i--){
            if(s[i] == s[j]){
                count += 1;
                if (j == 0) next.insert(0, to_string(count));
                j--;
            }else{
                next.insert(0, to_string(count));
                next.insert(0, 1,s[j]);
                if (j==0) next.insert(0, to_string(1));
                j--;
                count = 1;
            }
        }
        return helper(n, next, m+1);
    }
};
