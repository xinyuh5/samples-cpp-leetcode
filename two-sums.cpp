class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++){
            int complement = target - nums[i];
            auto it = hash.find(complement);
            if (it != hash.end()) return vector<int>{it->second, i};
            hash[nums[i]] = i;
        }
        return vector<int>();
    }
};
