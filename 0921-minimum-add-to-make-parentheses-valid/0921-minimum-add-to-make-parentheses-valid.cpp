class Solution {
public:
    int minAddToMakeValid(string s) {
         stack<char> st;
        int n = s.size();
        int count = 0;
    
    for(int i=0; i<n; i++){
        char ch =s[i];
        
        if(ch == '('){
            st.push(ch);
        }else{
            if(!st.empty()){
                st.pop();
            }else{
                count++;
            }
        }
    }
    
    
    while(!st.empty()){
    count++;
    st.pop();
    }
    cout << count;
    
    return count; 
    }
};