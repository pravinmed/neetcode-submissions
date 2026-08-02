class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        std::vector<int> res1(nums.size(),1);
        
        for(int i = 1; i < nums.size();i++) {
           res1[i] = nums[i-1]*res1[i-1];
        }

        std::vector<int> res2(nums.size(),1);
        res2 = {1};
        for(int i = nums.size()-2; i >=0;i--) {
           res2[i] = nums[i+1]*res2[i+1];
        }

        std::vector<int> res(nums.size());
        for(int i =0;i < nums.size();i++){
            res[i] = res1[i] * res2[i];
        }
        return res;

    }
};
