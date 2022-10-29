class Solution {
public:
    int reverse(int x) {
        long int reverse=0;
        while(x!=0){
            int temp=x%10;
            reverse=reverse*10+temp;
            x=x/10;
        }
        
        if(reverse<INT_MIN || reverse>INT_MAX){
            return 0;
        }
        return reverse;
        
    }
};