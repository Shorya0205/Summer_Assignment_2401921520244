class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int>lost_map;
        for(int i=0;i<matches.size();i++){
            lost_map[matches[i][1]]++;
        }

        vector<int>notlost,lost;

        for(int i=0;i<matches.size();i++){
            int winner=matches[i][0];
            int loser=matches[i][1];

            if(lost_map.find(winner)==lost_map.end()){
                notlost.push_back(winner);
                lost_map[winner]=2;
            }
            if(lost_map[loser]==1){
                lost.push_back(loser);
            }
        }

        sort(notlost.begin(),notlost.end());
        sort(lost.begin(),lost.end());

        return{notlost,lost};


    }
};