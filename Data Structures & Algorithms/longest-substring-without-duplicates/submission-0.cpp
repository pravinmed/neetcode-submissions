#include <algorithm>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int len = 0;
        int left = 0;
        std::set<char> mp;
        for(int i= 0;i < s.size();i++){           
            while(mp.find(s[i]) != mp.end()){
                   mp.erase(s[left]);
                   left++;
            }
            
            len = std::max(len,i - left + 1);
            mp.insert(s[i]);
            
        }
        return len;
    }
};
