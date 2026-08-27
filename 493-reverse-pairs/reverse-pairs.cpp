class Solution {
public:
    void megr(vector<int>&arr,int l,int m,int h){
        vector<int>temp;
        int left=l;
        int right=m+1;

        while (left <= m && right <= h){
            if (arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
            }
            else{
            temp.push_back(arr[right]);
            right++;
            }
        }
        while(left<= m){
            temp.push_back(arr[left]);
            left++;
        }
        while(right<= h){
            temp.push_back(arr[right]);
            right++;
        }
        for (int i=l; i <= h; i++) {
            arr[i] = temp[i-l];
        }
    }
    
    int countPairs(vector<int> &arr, int low, int mid, int high) {
        int right = mid + 1;
        int cnt = 0;
        for (int i=low; i<= mid;i++){
            while(right <= high && (long long)arr[i] > 2*(long long)arr[right]){
                right++;
            }
            cnt += (right-(mid+1));
        }
        return cnt;
    }
    
    int mgs(vector<int> &arr, int low, int high) {
        int cnt=0;
        if (low>=high) return cnt;
        int mid=(low + high) / 2 ;
        cnt += mgs(arr,low,mid);
        cnt += mgs(arr, mid+1, high);
        cnt += countPairs(arr,low,mid,high);
        megr(arr, low, mid, high);
        return cnt;
    }


    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        return mgs(nums,0,n-1);
    }
};