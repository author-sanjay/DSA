class Solution {
public:
    bool detectCapitalUse(string word) {
        int count=0;
        int size=word.length();
        bool first=(word[0]>=65 && word[0]<=90);
        for(int i=0;i<word.size();i++){
            if(word[i]>=65 && word[i]<=90){
                count++;
            }
        }
        if((count==1 &&first) || count==size||count ==0){
return true;}
        else{
            return false;
        }
    }
};