class Solution {
public:
    bool isvalid(string s,int t){
        stack<char> k;
        for(int i=0;i<t;i++){
            if(s[i]=='('){
                k.push(s[i]);
            }else{
                if(k.empty()){
                    return false;
                }else{
                    if(k.top()=='('&&s[i]==')'){
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
    
    void rec(string st,string combination, int n, vector<string> &list){
         int z=st.length();
        if(combination.length()==2*n){
            if(isvalid(combination,2*n)){
                list.push_back(combination);
            }
        }
        else{
            for(int i=0;i<z;i++){
                string newcomb;
                newcomb= combination + st[i];
                rec(st,newcomb,n,list);
            }
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> list;
        string st="()", check="";
        rec(st,check,n,list);
        return list;
    }
};
