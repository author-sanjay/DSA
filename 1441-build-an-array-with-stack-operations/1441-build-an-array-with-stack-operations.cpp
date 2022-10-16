class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> st;
        int i=0;
        int input=1;
        while(i<target.size()){            
            if(input==target[i]){          
                st.push_back("Push");
                i++;
                
            }else{
                st.push_back("Push");
                st.push_back("Pop");
            }
            
            input++;
    
        }
        
        return st;
    }
};