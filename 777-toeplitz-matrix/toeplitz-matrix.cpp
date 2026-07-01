class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        
        int n2=matrix[0].size();
        int n1=matrix.size();
        

        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                if(i>0 && j>0 && matrix[i][j]!=matrix[i-1][j-1]){
                    return false;
                }
            }
        }

        return true;
    }
};