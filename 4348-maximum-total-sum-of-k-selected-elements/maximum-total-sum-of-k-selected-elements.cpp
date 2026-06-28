class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(),nums.end());

        int n=nums.size();
        long long ts=0;

        for(int i=n-1;i>=n-k;i--){
            if(mul>1){
                ts+=((long long)mul*nums[i]);
                mul--;
            }
            else{
                ts+=nums[i];
                mul--;
            }
        }

        return ts;
    }
};