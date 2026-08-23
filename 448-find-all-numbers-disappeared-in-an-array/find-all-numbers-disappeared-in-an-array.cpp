class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]=1;

        }

        for(int i=1;i<n+1;i++){
            if(mp[i]==1){
                continue;
            }
            else{
                ans.push_back(i);
            }
        }

        return ans;

    }
};