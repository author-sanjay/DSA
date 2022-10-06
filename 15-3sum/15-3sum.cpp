class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> s;
        vector<int>ans;
        vector<vector<int>>ansss;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int low=i+1, high=nums.size()-1;
            while(low<high){
                if(nums[i]+nums[low]+nums[high]==0){
                    ans.push_back(nums[i]);
                    ans.push_back(nums[low]);
                    ans.push_back(nums[high]);
                    s.insert(ans);
                    ans.clear();
                    low++;
                    high--;
                }else if(nums[i]+nums[low]+nums[high]>0){
                    high--;
                }else{
                    low++;
                }
            }
        }
        
        ans.clear();
        
        for(auto it:s){
            ansss.push_back(it);
        }
        
        return ansss;
    }
};