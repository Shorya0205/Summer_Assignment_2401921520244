class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v=graph.size();
        queue<int>q;
        vector<int>color(v,-1);

        for(int i=0;i<v;i++){
            if(color[i] != -1){continue;}
            color[i] = 0;
            q.push(i);

            while(!q.empty()){
                int node=q.front();
                q.pop();

                for(auto it: graph[node]){
                    if(color[it]==-1){
                        color[it] = !color[node];
                        q.push(it);
                    }
                    else if(color[it] ==color[node]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};