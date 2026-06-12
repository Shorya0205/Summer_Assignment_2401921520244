class Solution {
public:
    int firstUniqChar(string s) {

        int n=s.length();
        vector<int>mark(26,0);
        for(int i=0;i<n;i++){
            mark[s[i]-'a']++;
        }

        for(int i=0;i<n;i++){
            if(mark[s[i]-'a']==1){
                return i;
            }
        }
        return -1;
    }
};