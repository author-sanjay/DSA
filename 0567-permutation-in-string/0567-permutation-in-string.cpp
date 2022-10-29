class Solution {
public:
    
    bool issame(vector<int> p1,vector<int>p2){
        for(int i=0;i<p1.size();i++){
            if(p1[i]!=p2[i]){
                return false;
            }
        }
        
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        
        int i=0;
        int j=s1.size()-1;
        while(j<s2.size()){
            vector<int>first(26,0);
            vector<int>second(26,0);
            for(int p=0;p<s1.size();p++){
                if(first[s1[p]-'a']==0){
                    first[s1[p]-'a']=1;
                }else{
                    first[s1[p]-'a']++;
                };
            }
            int start=i;
            int end=j;
            cout<<start<<" "<<end;
            while(start<=end){
                if(second[s2[start]-'a']==0){
                    second[s2[start]-'a']=1;
                }else{
                    second[s2[start]-'a']++;
                }
                
                start++;
            }
           
            // for(auto a:second){
            //     cout<<a;
            // }
            
            if(issame(first,second)){
                return true;
            }else{
            i++;
            j++;    
            }
            
            
        }
        
        return false;
        
    }
};