class Solution {
public:

    void dfs(int r,int c,vector<vector<int>> &ans , vector<vector<int>> &image,int color,int ini){
        ans[r][c]=color;
        int n=image.size();
        int m =image[0].size();

        int delr[]={-1,0,1,0};
        int delc[]={0,1,0,-1};

        for(int i=0;i<4;i++){
            int nr=r+delr[i];
            int nc=c+delc[i];

            if(nr>=0 && nc>=0 && nr<n && nc<m && image[nr][nc]==ini && ans[nr][nc] !=color){
                dfs(nr,nc,ans,image,color,ini);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ini=image[sr][sc];
        vector<vector<int>>ans=image;

        
        dfs(sr,sc,ans,image,color,ini);
        return ans;
    }
};