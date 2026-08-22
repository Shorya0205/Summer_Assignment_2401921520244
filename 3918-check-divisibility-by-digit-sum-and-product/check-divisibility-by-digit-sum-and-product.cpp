class Solution {
public:
    bool checkDivisibility(int n) {
        
        int sum=0,prod=1,check=n;
        while(n>0){
            int dig=n%10;
            sum+=dig;
            prod*=dig;
            n=n/10;
        }

        int total=sum+prod;
        if(check%total==0){
            return true;
        }
        return false;
    }
};