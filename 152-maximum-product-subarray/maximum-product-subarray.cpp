class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int pre=1,suff=1,maxe=0,n=nums.size();

        if(n==1){
            return nums[0];
        }
        for(int i=0;i<n;i++){
            if(pre==0){
                pre=1;
            }
            if(suff==0){
                suff=1;
            }
            pre*=nums[i];
            suff*=nums[n-i-1];

            maxe=max(maxe,max(pre,suff));
        }
        return maxe;
    }
};