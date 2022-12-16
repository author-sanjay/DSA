class Solution {
public:
   int subarraySum(vector<int>& nums, int k) {
        int ans=0;
       unordered_map<int,int>mp;
       int sum=0;
       mp[sum]=1;
       for(auto i:nums){
           sum+=i;
           if(mp.find(sum-k)!=mp.end()){
                ans+=mp[sum-k];
           }
           
           mp[sum]++;
           cout<<sum<<" "<<mp[sum]<<endl;
       }
       return ans;
    }
};