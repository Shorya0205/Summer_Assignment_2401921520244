class Solution {
public:
    int maxDistance(string moves) {
        
        int x=0,y=0,count=0;
        for(int i=0;i<moves.length();i++){
            if(moves[i]=='U'){y++;}
            else if(moves[i]=='D'){y--;}
            else if(moves[i]=='L'){x++;}
            else if(moves[i]=='R'){x--;}

            else{
                count++;
            }

        }

        int el1=max(abs(x),abs(y));
        int el2=min(abs(x),abs(y));

        if(el1>=0){
            el1+=count;
        }
        else{
            el2-=count;
        }
        return abs(el1)+abs(el2);
    }
};