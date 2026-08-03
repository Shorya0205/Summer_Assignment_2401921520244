class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();

        int hash[256]={-1};
        fill(hash, hash + 256, -1);
        int len=0,maxlen=0;

        int l=0,r=0;
        while(r<n){
            
                if(hash[s[r]] >=l){
                    l=hash[s[r]]+1;
                }
            
           len=r-l+1;
           maxlen=max(maxlen,len);

           hash[s[r]]=r;
           r++;
        }
        return maxlen;
    }
};