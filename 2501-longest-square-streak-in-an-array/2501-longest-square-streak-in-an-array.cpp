class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int ans=0;
        sort(nums.begin(),nums.end());
        
        
        unordered_set<int> s;
        for(auto a:nums){
            s.insert(a);
        }
        
        for(auto a:nums){
            int c=0;
            long long t=a;
            while(s.find(t)!=s.end()){
                c++;
                s.erase(t);
                t=t*t;
            }
            ans=max(ans,c);
        }
        
    return ans>1?ans:-1;

    }
};