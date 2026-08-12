class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        
        int i=0,j=0;
        int n=nums.size(),maxl=1;
        
        unordered_map<int,int>mp;

        while(j<n){
            mp[nums[j]]++; 
           while(mp[nums[j]]>k){
            mp[nums[i]]--;
            i++;
           }
           maxl=max(maxl,j-i+1);
             
        j++;
        }

        return maxl;
    }
};