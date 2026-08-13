class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n=nums.size(),cnt=0;
        int mid=nums[n/2];

        for(int i=0;i<nums.size();i++){
            if(mid==nums[i]){
                cnt++;
            }
        }

        if(cnt==1){
            return true;
        }
        else{
            return false;
        }
    }
};