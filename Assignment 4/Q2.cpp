class Solution {
public:
    int reverse(int x) {
        long reverse=0;
        while(x!=0){
            int t=x%10;
            reverse = reverse*10+t;
            x=x/10;
        }
        return reverse;
    }
};