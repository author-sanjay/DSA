class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>>mp;
        for(auto a:strs){
            string temp=a;
            sort(temp.begin(),temp.end());
             mp[temp].push_back(a);
        }
        
        for(auto s:mp){
            ans.push_back(s.second);
        }
        
        return ans;
    }
};