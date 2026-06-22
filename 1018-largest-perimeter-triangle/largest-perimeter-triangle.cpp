class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        

        sort(nums.begin(),nums.end());
        int n=nums.size();
        int sum=0;
        for(int i=n-3;i>=0;i--){
           if(nums[i+1]+nums[i]>nums[i+2]){
            sum=nums[i+1]+nums[i]+nums[i+2];
            return sum;
           } 
        }

        return sum;
    }
};