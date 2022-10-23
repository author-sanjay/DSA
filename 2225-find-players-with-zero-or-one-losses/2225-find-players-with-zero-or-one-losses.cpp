class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        set<int>s;
        unordered_map<int,int> mp;
        
        
        for(auto a:matches){
            s.insert(a[0]);
            s.insert(a[1]);
            mp[a[1]]++;
        }
        vector<vector<int>> ans;
        vector<int> nolouser;
        vector<int> onelooser;
        for(auto a:s){
            if(mp[a]==1){
                onelooser.push_back(a);
            }
            else if(!mp[a]){
                nolouser.push_back(a);
            }
        }
        sort(onelooser.begin(),onelooser.end());
        sort(nolouser.begin(),nolouser.end());
        ans.push_back(nolouser);
        ans.push_back(onelooser);
        
        return ans;
        
    }
};