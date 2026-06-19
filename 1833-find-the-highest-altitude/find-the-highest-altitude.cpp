class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        
        int max=0,pref=0;
        for(int i=0;i<n;i++){

           pref=pref+gain[i];
            if(pref>max){
                max=pref;
            }

        }
        return max;


    }
};