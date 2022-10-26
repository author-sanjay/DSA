class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int runningsum=0;
        mp[0]=-1;
        for(int i=0;i<nums.size();i++){
            runningsum+=nums[i];
            if(k!=0){
                runningsum=runningsum%k;
            }
            if(mp.find(runningsum)!=mp.end()){
                if(i-mp[runningsum]>1){
                    return true;
                }
            }else{
                mp[runningsum]=i;
            }
        }
        return false;
    }
};