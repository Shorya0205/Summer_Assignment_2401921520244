class Solution {
public:
    int countValidPrefixes(string s) {
        
        int c0=0,c1=0,n=s.length(),res=0;

        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                c0++;
            }
            else{
                c1++;
            }
            int cnt=abs(c0-c1);
            if(cnt<=1){
                res++;
            }
        }
        
        

        return res;
    }
};