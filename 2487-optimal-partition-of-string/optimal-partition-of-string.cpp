class Solution {
public:
    int partitionString(string s) {
        vector<int>lastseen(26,-1);
        int cnt=0,currstart=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            char ch=s[i];

            if(lastseen[ch-'a'] >= currstart){
                cnt++;
                currstart=i;
            }
            lastseen[ch-'a']=i;
        }
        return cnt+1;
    }
    
};