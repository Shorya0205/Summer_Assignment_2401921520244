class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int n=nums.size();

        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]=1;

        }

        for(int i=lower;i<upper+1;i++){
            if(mp.find(i)!=mp.end()){
                
                continue;
            }

            int s=i;

            while(i<=upper && mp.find(i)==mp.end()){
                i++;
            }

            ans.push_back({s,i-1});
        }
        return ans;
        
    }
};