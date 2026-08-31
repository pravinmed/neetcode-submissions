class Solution {
public:
    
    string minWindow(string s,string t){
        //s-string="A DOBE CODEBA NC"
//t-string="ABC"
        if(s.size() < t.size()){
            return "";
        }

        std::map<char,int> window;
        for(int i = 0;i < t.size();i++){
            window[t[i]]++;
        }
        int maxSize = window.size();

        int maxWindow = INT_MAX;
        int l = 0 ;
        std::pair<int,int> p ={0,0};
        std::map<char,int> testWindow;  
        int size = 0;
        for(int r = 0; r < s.size();r++){
            auto chr = s[r];
            testWindow[s[r]]++;
            if(window.find(chr) != window.end() && window[chr] == testWindow[chr]){
                size++;
            }
            while(size == maxSize){
                 if(r-l+1 < maxWindow){
                    maxWindow = r-l+1;
                    p = {l,r};
                 }
                 testWindow[s[l]]--;
                 if (window.find(s[l]) != window.end() && testWindow[s[l]] < window[s[l]]){
                    size--;
                 }
                 l++;
            }

        }
        if(maxWindow == INT_MAX) {
            return "";
        }
        return s.substr(p.first,maxWindow);

    }
    
    string minWindow2(string s, string t) {
        if(t.size() > s.size()){
            return "";
        }
        std::map<char,int> mp1;
        for(int i = 0 ;i < t.size();i++){
            if(mp1.find(t[i])== mp1.end()){
                
                mp1[t[i]] = mp1[t[i]]+1;
            } else {
                mp1[t[i]] = 1;
            }
        }
        int res= 99999;
        std::string resStr;
        
        for(int i =0 ;i < s.size();i++){
            std::map<char,int> mpCp;
            mpCp.insert(mp1.begin(),mp1.end());
            
            if(mpCp.find(s[i]) != mpCp.end()){
                int j = i;
                bool foundSubStr = false;
                for(j = i;j < s.size();j++){
                  
                    if(mpCp.find(s[j]) != mpCp.end()){
                        mpCp[s[j]] = mpCp[s[j]] - 1;
                        //std::cout << " increase " << std::endl;
                        if(mpCp[s[j]] == 0){
                            //std::cout << j <<" j " << " erase " << std::endl;
                            mpCp.erase(s[j]); 
                        }
                    }
                    if(mpCp.size() == 0){
                        //std::cout << "erased i "<< std::endl;
                        foundSubStr = true;
                        break;
                    }
                }
             
                if(foundSubStr && (j-i) < res){
                  std::cout << i << " i val "<<j<< " j val" << std::endl;
                  res = std::min(res,j-i);
                   resStr = s.substr(i, j - i +1);
                }
                
            }
        }
        return resStr;

    }
};
