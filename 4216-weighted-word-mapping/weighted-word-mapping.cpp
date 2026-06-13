class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int n=words.size();
        int sum=0;
        string res="";

        for(int i=0;i<n;i++){
            sum=0;
            string temp=words[i];
            int n1=temp.length();

            for(int i=0;i<n1;i++){
                char ch=temp[i];
                sum+=weights[ch - 'a'];

            }

            int mod = sum % 26;
            char mp = 'z' - mod;
            res.push_back(mp);

        }

        return res;
        
    }
};