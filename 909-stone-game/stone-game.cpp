class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        sort(piles.begin(),piles.end(),greater<int>());

        int al=0,bob=0;
        for(int i=0;i<piles.size();i++){
            if(i%2==0){
                al+=piles[i];
            }
            else{
                bob+=piles[i];

            }
        }

        if(bob>al){
            return false;
        }
        return true;
    }

};