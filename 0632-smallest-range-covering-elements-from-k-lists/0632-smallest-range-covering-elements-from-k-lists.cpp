class node{
    public:
    int data;
    int row;
    int col;
    node(int d,int r, int c){
        data=d;
        row=r;
        col=c;
    }
};

class comp{
    public:
    bool operator()(node* a, node* b){
        return a->data>b->data;
    }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int mini=INT_MAX;
        int maxi=INT_MIN;
        priority_queue<node*,vector<node*>, comp>minheap;
        for( int i=0;i<nums.size();i++)
        {
            int ele=nums[i][0];
            mini=min(mini,ele);
            maxi=max(maxi,ele);
            minheap.push(new node(ele,i,0));
        }

        int start=mini, end=maxi;
        while(!minheap.empty()){
            node* ele=minheap.top();
            minheap.pop();
            mini=ele->data;
            if(maxi-mini <end-start){
                start=mini;
                end=maxi;
            }
            int rows=ele->row;
            int size=nums[rows].size();
            if((ele->col+1)<size){
                maxi=max(maxi,nums[ele->row][ele->col+1]);
                minheap.push(new node(nums[ele->row][ele->col+1],ele->row,ele->col+1));
            }else{
                break;
            }

        }
        return {start,end};
    }
};