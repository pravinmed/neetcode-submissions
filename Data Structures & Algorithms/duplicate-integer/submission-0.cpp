class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::map<int,int> hash;
        for(int i =0; i < nums.size();i++){
            if(hash.contains(nums[i])){
                return true;
            }
            hash[nums[i]] = 1;
        }
        return false;
        
    }
};