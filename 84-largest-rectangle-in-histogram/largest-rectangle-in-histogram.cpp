class Solution {
public:

    vector<int> getNSL(vector<int>& arr, int n) {
        vector<int> res(n);
        stack<int> st;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            res[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return res;
    }

    vector<int> getNSR(vector<int>& arr, int n) {
        vector<int> res(n);
        stack<int> st;
        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            res[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return res;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> NSL=getNSL(heights, n);
        vector<int> NSR=getNSR(heights, n);

        int ans=0;

        for(int i = 0; i < n; i++) {
            int width = NSR[i]-NSL[i]-1;
            int area = heights[i]*width;

            ans = max(ans,area);
        }
        return ans;
    }
};