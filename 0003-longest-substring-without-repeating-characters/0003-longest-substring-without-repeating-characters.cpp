class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0){
            return 0;
        }
        set<char>set;
        int start=0;
        int end=0;
        int maxlen=INT_MIN;;
        while(end<s.size()){
            auto it=set.find(s[end]);
            if(it==set.end()){
                if(maxlen<=(end-start+1)){
                    maxlen=end-start+1;
                    
                }
                set.insert(s[end]);
                end++;
            }else{
                    set.erase(s[start]);
                    start++;
                }
                
            
        }
        return maxlen;
    }
};