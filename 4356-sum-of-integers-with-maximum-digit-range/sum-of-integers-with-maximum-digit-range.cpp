class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        
        vector<int>arr(10,0);
        int ans=0;
        int n=nums.size();
        int maxdr=0;

        for(int j=0;j<n;j++){    
            int num=nums[j];
            int maxi=-1,min=INT_MAX;
            while(num>0){
                int dig=num%10;
                num=num/10;

                if(dig>maxi){
                    maxi=dig;
                }
                if(dig<min){
                    min=dig;
                }
            }
            int dr=maxi-min;
            maxdr=max(maxdr,dr);
            int val = nums[j];
            arr[dr] += val;
            arr[dr]+=num;
        }

        for(int i=0;i<arr.size();i++){
            if(arr[i]!=0){
                ans=arr[i];
            }
        }
        return ans;
    }
};