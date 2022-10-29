class Solution {
public:
   
    string longestPalindrome(string s) {
        
        string ans="";
        int len=0;
        for(int i=0;i<s.size();i++){
                int prev=i;
                int end=i;
            while(prev>=0 &&end<s.size() &&s[prev]==s[end]){
                if((end-prev+1)>len){
                    ans=s.substr(prev,end-prev+1);
                    len=end-prev+1;
                }
                prev--;
                end++;
            }
                prev=i;
                end=i+1;
                while(prev>=0 &&end<s.size() &&s[prev]==s[end]){
                    if((end-prev+1)>len){
                        ans=s.substr(prev,end-prev+1);
                        len=end-prev+1;
                    }
                prev--;
                end++;
            
                }
            
                
            
            
            
        }
        return ans;
    }
};