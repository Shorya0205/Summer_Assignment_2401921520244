class Solution {
public:
    int maximumLengthSubstring(string s) {
        
        int l=0,r=0,len=0,maxlen=0;
        int n=s.length();
        vector<int>hash(26,0);

        while(r<n){
            hash[s[r]-'a']++;
            while(hash[s[r]-'a']>2){
                
                hash[s[l]-'a']--;
                l++;
            }
            len=r-l+1;
            maxlen=max(maxlen,len);
            r++;
        }
        return maxlen;
    }
};