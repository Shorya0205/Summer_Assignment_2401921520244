class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int cnt=INT_MAX;
        vector<int>ct(26,0);
        for(auto it:text){
            ct[it-'a']++;
        }

        ct['o' - 'a']=ct['o' - 'a']/2;
        ct['l' - 'a']=ct['l' - 'a']/2;
        for(int i=0;i<26;i++){
            int ch=i+'a';
            if(ch=='b'|| ch=='a'|| ch=='l'|| ch=='o'|| ch=='n'){
                cnt=min(cnt,ct[i]);
            }
        }

        return cnt;
    }
};