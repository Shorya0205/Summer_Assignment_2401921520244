class Solution {
public:
    string makeGood(string s) {
        string ans="";
        
        for(char &ch:s){
            if(!ans.empty() && 
               (ans.back() + 32 == ch || ans.back() - 32 == ch)){
                ans.pop_back();
            }
            else{
                ans+=ch;
            }
        }

        return ans; 
    }
};