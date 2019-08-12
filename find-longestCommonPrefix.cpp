//horizontal 
/*class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        string prefix = strs[0];
        for (int i = 1; i < strs.size(); i++){
            while(strs[i].find(prefix) != 0){
                prefix = prefix.substr(0, prefix.length()-1);
                if (prefix.empty()) return "";
            }
        }
        return prefix;
    }
};*/
//vertical
/*
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        for (int i = 0; i < strs[0].length(); i++){
            char c = strs[0][i];
            for (int j = 0; j < strs.size(); j++){
                if (i == strs[j].length() || strs[j][i] != c){
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};*/
//divide and conquer
/*
class Solution{
public:
    string longestCommonPrefix(vector<string>& strs){
        if (strs.size()==0) return "";
        return longestCommonPrefix(strs, 0, strs.size()-1);
    }
private:
    string longestCommonPrefix(vector<string>& strs, int l, int r){
        std::cout<<'l'<<l<<'r'<<r<<std::endl;
        if (l==r){
            return strs[l];
        }else{
            int mid = (l+r)/2;
            string lcpLeft = longestCommonPrefix(strs, l, mid);
            std::cout << "leftt"<<lcpLeft<<std::endl;
            std::cout<<"afterleft"<<l<<"  "<< r<< std::endl;
            string lcpRight = longestCommonPrefix(strs, mid+1, r);
            std::cout<<"rightt"<<lcpRight<<std::endl;
            return commonPrefix(lcpLeft, lcpRight);
        }
    }
    string commonPrefix(string left, string right){
        std::cout<<"  "<<left<<"  "<<right<<std::endl;
        int mini = min(left.length(), right.length());
        for (int i = 0; i < mini; i++){
            if (left[i] != right[i]){
                return left.substr(0,i);
            }
        }
        std::cout<<"left"<<left.substr(0,mini)<<std::endl;
        return left.substr(0, mini);
    }
};*/
//binrary search
class Solution{
public:
    string longestCommonPrefix(vector<string>& strs){
        if (strs.size()==0) return "";
        int minlen = INT_MAX;
        for (auto str: strs){
            int l = str.length();
            minlen = min(minlen, l);
        }
        int low = 1;
        int high = minlen;
        while (low <= high){
            int middle = (low+high)/2;
            std::cout<<"low"<<low<<"high"<<high<<"middle"<<middle<<std::endl;
            if (isCommonPrefix(strs, middle)){
                low = middle+1;
            }else{
                high = middle-1;
            }
        }
        return strs[0].substr(0, (low+high)/2);
    }
private:
    bool isCommonPrefix(vector<string>& strs, int len){
        string str1 = strs[0].substr(0,len);
        for (int i = 1; i < strs.size(); i++){
            if (strs[i].find(str1) != 0){
                return false;
            }
        }
        return true;
    }
};
