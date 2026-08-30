class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        
        int n=nums.size(),maxi=INT_MIN,maxi_ind=0,mini=INT_MAX,mini_ind=0,cnt=0,temp=0;
        for(int i=0;i<n;i++){
            if(maxi<nums[i]){
                maxi=max(maxi,nums[i]);
                maxi_ind=i;
            }

            if(mini>nums[i]){
                mini=min(mini,nums[i]);
                mini_ind=i;
            }
        }

        int l=min(mini_ind,maxi_ind);
        int r=max(mini_ind,maxi_ind);

        int f=r+1;
        int b=n-l;

        int both =(l+1)+(n-r);

        return min({f,b,both});
    }
};