class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val){
                ans.push_back(nums[i]);
            }
        }
        
        nums.resize(ans.size());
        nums=ans;
        int count=0;
        
        return ans.size();
    }
};