class Solution {
public:
    bool judgeSquareSum(int c) {
        long long int start=0;
        long long int end=sqrt(c)+1;
        while(start<=end){
            if(((start*start)+(end*end)==c)){
                return true;
            }
            else if(((start*start)+(end*end)>c)){
                end--;
            } else{
                start++;
            }
        }

        return false;
        
    }
};