class Solution {
public:
    bool isValid(string s) {
        stack<char>k;
        int n=s.length();
        for(int i=0;i<n;i++){
           if(s[i] == '(' || s[i] == '{' || s[i] == '['){
             k.push(s[i]);
            }else{
               if(k.empty()){
                    return false;
               }else{
                   
                   if((k.top()=='(' &&s[i]==')')||(k.top()=='[' &&s[i]==']')||               (k.top()=='{'&&s[i]=='}')){
                       k.pop();
                   }else{
                       return false;
                   }
               }
           }

        }
        if(k.empty()){
            return true;
        }
        
        
        return false;
    }
};