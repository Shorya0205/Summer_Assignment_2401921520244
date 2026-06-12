class Solution {
public:
    char findTheDifference(string s, string t) {
        
        int n=t.length();
        int n1=s.length();
        
        vector<int>mark(26,0);
        for(int i=0;i<n;i++){
            if(i<n1){
            mark[s[i]-'a']--;
            }
            mark[t[i]-'a']++;
        }
        
        for(int i=0;i<26;i++){
            if(mark[i]==1){
                return char(i+'a');
            }
        }
        return ' ';
    }
};