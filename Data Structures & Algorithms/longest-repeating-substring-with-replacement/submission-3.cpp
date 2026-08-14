class Solution {
public:
    int characterReplacement(string s, int k) {

        std::string scopy = s;
        
        int l= 0,r= 0;
        int res = 0;
        int removed = 0;
        int maxf = 0;
        int j = 0;
        std::map<char,int> mp;
        for(int i = 0; i < s.size();i++)
        {
            if(mp.find(s[i]) != mp.end()){
                mp[s[i]] = mp[s[i]] + 1;
                maxf = std::max(maxf,mp[s[i]]);
            } else {
                mp[s[i]] =  1;
                maxf = std::max(maxf,mp[s[i]]);                
            }
            while((i-j+1)-maxf > k){
                // remove from the right
                mp[s[j]]--;
                j++;
            }
            
            res = std::max(res,i-j+1);

        }
        return res;
        
    }
};
