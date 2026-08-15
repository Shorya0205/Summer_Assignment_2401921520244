class Solution {
public:

    vector<int> getNSL(vector<int>&arr, int n){
        vector<int>res(n);
        stack<int>st;

        for (int i=0; i<n;i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            res[i] = st.empty()?-1:st.top();
            st.push(i);
        }
        return res;
    }

    vector<int> getNSR(vector<int>& arr, int n) {
        vector<int> res(n);
        stack<int> st;

        for (int i = n-1; i>=0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            res[i] = st.empty() ? n:st.top();
            st.push(i);
        }
        return res;
    }

    vector<int> getNGL(vector<int>& arr, int n) {
        vector<int> res(n);
        stack<int> st;

        for (int i =0;i<n;i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            res[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return res;
    }

    vector<int> getNGR(vector<int>& arr, int n) {
        vector<int>res(n);
        stack<int>st;

        for (int i=n-1; i>= 0;i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            res[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return res;
    }


    long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        vector<int> NSL = getNSL(arr,n);
        vector<int> NSR = getNSR(arr,n);

        long long sum = 0;

        for (int i = 0; i < n; i++) {
            long long l = i - NSL[i];
            long long r = NSR[i] - i;

            sum += l *r*arr[i];
        }
        return sum;
    }

    long long sumSubarrayMaxs(vector<int>& arr) {
        int n = arr.size();

        vector<int> NGL = getNGL(arr, n);
        vector<int> NGR = getNGR(arr, n);

        long long sum = 0;

        for (int i = 0; i < n; i++) {
            long long l = i-NGL[i];
            long long r = NGR[i] -i;
            sum += l*r*arr[i];
        }
        return sum;
    }

    long long subArrayRanges(vector<int>& nums) {

        long long maximumSum = sumSubarrayMaxs(nums);
        long long minimumSum = sumSubarrayMins(nums);

        return maximumSum - minimumSum;
    }

    
};