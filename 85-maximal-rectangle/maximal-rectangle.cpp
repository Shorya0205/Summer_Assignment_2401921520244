class Solution {
public:

    int lar_rect(vector<int>heights){
        int n=heights.size();
        vector<int>left(n),right(n);
        stack<int>st;

        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            left[i]=st.empty()? -1:st.top();
            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            right[i]=st.empty()? n:st.top();
            st.push(i);
        }

        int ans=0;
        for(int i=0;i<n;i++){
            int width =right[i]-left[i] - 1;
            int area =heights[i]*width;
            ans = max(ans,area);
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
      int m=matrix.size();
      int n=matrix[0].size();
      vector<vector<int>>heights(m,vector<int>(n,0));

      int ans=0,sum;
      for(int j=0;j<n;j++){
        sum=0;
        for(int i=0;i<m;i++){
            
            if(matrix[i][j]=='1'){
                sum++;
                
            }
            else{
                sum=0;
            }
            heights[i][j]=sum;
        }
        
      }
      int maxArea = 0;

        for(int j = 0; j < m; j++){

            maxArea = max(maxArea, lar_rect(heights[j]));
        }

        return maxArea;

    }
};