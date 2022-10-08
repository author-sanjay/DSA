class Solution {
public:
    
    int findsections(int mid, vector<int>nums,int m){
        int count=1;
        int tempsum=0;
        for(int i=0;i<nums.size();i++){
            if(tempsum+nums[i]>mid){
                tempsum=nums[i];
                count++;
            }else{
                tempsum=tempsum+nums[i];
            }
        }
        
        return count;
    }
    int splitArray(vector<int>& nums, int m) {
        int l=nums[0];
        int sum=0, ans=0;
        for(int i=0;i<nums.size();i++){
            l=max(l,nums[i]);
            sum+=nums[i];
        }
        
        while(l<=sum){
            int mid=(l+sum)/2;
            int n=findsections(mid,nums,m);
            if(n>m){
                l=mid+1;
            }else{
                ans=mid;
                sum=mid-1;
            }
        }
        
        return ans;
    }
};