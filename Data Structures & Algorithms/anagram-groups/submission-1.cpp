class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::map<std::string,std::vector<std::string>> sortedMap;
        for(auto str:strs){
            auto s = str;
            std::sort(s.begin(),s.end());
            if(sortedMap.find(s) == sortedMap.end()){
                sortedMap[s] = { str}; 
            } else {
                sortedMap[s].push_back(str);
            }
        }
    
    std::vector<std::vector<string>> res;
    for(const auto[s,v]:sortedMap){
        res.push_back(v);
    }
    return res;
    }
};
