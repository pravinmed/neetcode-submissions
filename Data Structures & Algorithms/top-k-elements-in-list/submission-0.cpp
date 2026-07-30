class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(k == 0) {return {};}
        std::map<int,int> mp;
        for(auto i: nums){
            if(mp.find(i) == mp.end()){
                mp[i] = 1;
            } else {
                 mp[i] = mp[i] + 1;
            }
        }
        std::vector<int> res;
        for(const auto[num,count]:mp){
            res.push_back(num);
        }

        std::sort(res.begin(),res.end(), [&](int a, int b) {
            return mp[a] > mp[b];
        });
        std::vector<int> res2;
        std::copy_n(res.begin(),k,std::back_inserter(res2));
        return res2;
    }

};
