class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        
        unordered_map<string,int>freq;

        for (auto &day :responses) {
            unordered_set<string> uniq(day.begin(), day.end());
            for (auto &res :uniq) {
                freq[res]++;
            }
        }

        string ans="";
        int maxFreq=0;

        for (auto &it : freq) {
            string word = it.first;
            int count = it.second;
            if (count > maxFreq||(count == maxFreq && word<ans)) {
                ans=word;
                maxFreq=count;
            }
        }
        return ans;
        
    }
};