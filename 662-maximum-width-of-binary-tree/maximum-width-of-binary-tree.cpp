/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL){return 0;}
        long long ans=0;
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});

        while(!q.empty()){
            int size=q.size();
            long long mini=q.front().second;
            long long f,l;

            for(int i=0;i<size;i++){
                long long curid=q.front().second-mini;
                TreeNode* node=q.front().first;
                q.pop();

                if(i==0){
                    f=curid;
                }
                if(i==size-1){
                    l=curid;
                }

                if(node->left !=NULL){
                    q.push({node->left,curid*2+1});
                }
                if(node->right !=NULL){
                    q.push({node->right,curid*2+2});
                }
            }
            ans=max(ans,l-f+1);
        }
        return ans;
    }
};