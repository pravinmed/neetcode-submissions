class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        std::map<char,int> mp1;
        std::map<char,int> mp2;
        for(auto c:s){
            if(mp1.find(c) == mp1.end()){
                mp1[c] = 1;
            } else {
                mp1[c] = mp1[c] + 1;
            }
        }

        for(auto c:t){
            if(mp2.find(c) == mp2.end()){
                mp2[c] = 1;
            } else {
                mp2[c] = mp2[c] + 1;
            }
        }

        for(auto [c,n]: mp1){
            if(mp2.find(c) == mp2.end()){
                return false;
            }
            if(mp2[c] != n){
                return false;
            }
        }
        return true;
    }
};
