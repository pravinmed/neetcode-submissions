class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        std::set<int> st(nums.begin(),nums.end());
        int maxLen = 1;
        for(int i =0;i < nums.size();i++){
            if(st.find(nums[i]-1) == st.end()){
                int len = 1;
                while(st.find(nums[i]+len) != st.end()){
                    len++;
                }
                maxLen = max(len,maxLen);
            }
        }
        return maxLen;
    }
};
