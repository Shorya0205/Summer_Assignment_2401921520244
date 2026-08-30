class Solution {
public:

    int atmostk(vector<int>&nums,int k){
        unordered_map<int,int>mp;
        int l=0,r=0,c=0,n=nums.size();

        while(r<n){
            mp[nums[r]]++;

            while(mp.size()>k){
                mp[nums[l]]--;
                if (mp[nums[l]] == 0) {
                    mp.erase(nums[l]);
                }
                l++;
            }
            c+=r-l+1;
            r++;
        }
        return c;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmostk(nums,k)-atmostk(nums,k-1);
        
    }
};