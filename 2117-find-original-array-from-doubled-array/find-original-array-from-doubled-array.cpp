class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n=changed.size();
        vector<int>result;
        unordered_map<int,int>mp;

        if(n%2==1){
            return {};
        }
        sort(changed.begin(),changed.end());

        for(auto &it:changed){
            mp[it]++;
        }

        for(auto &it:changed){
            if(mp[it]==0){continue;}

            int twice = it * 2;
            if(mp.find(twice)== mp.end() || mp[twice]==0){
                return {};
            }

            result.push_back(it);
            mp[it]--;
            mp[twice]--;
        }

        return result;
    }
};