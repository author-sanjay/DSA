class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int start=0;
        int end=0;
        while(start<nums.size()){  //{1,2,4,5,6,0,7}
            if(nums[start]!=0){
                swap(nums[end++],nums[start]);
            }
            start++;
        }
    }
};