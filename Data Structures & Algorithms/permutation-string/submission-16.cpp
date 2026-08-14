class Solution {
public:
    bool checkInclusion(string s1, string s2) {
      
        std::unordered_map<char,int> mp1;    
       // s2 is bigget
       // s1 is smaller

        for(int j = 0;j < s1.size();j++){
            mp1[s1[j]]++;
        } 
        int tar = mp1.size();
        std::cout << tar << " target " <<std::endl;
        for(int i = 0;i < s2.length();i++)
        {
            std::unordered_map<char,int> mp2;
            std::cout<< " new loop" << std::endl;
            int cur = 0;
            for(int j =i;j < s1.length()+i;j++){
             
                mp2[s2[j]]++;
                if(mp1[s2[j]] < mp2[s2[j]]){
                    break;
                }
                std::cout << mp2.size() << " mp2.size() "<< j << " j index" <<std::endl;
                if(mp1[s2[j]] == mp2[s2[j]]){
                    // found
                    cur++;
                }
                if(cur == tar){
                    return true;
                }
                
            }
        }
        std::cout << " Done " << std::endl;
        return false;
    }
};
