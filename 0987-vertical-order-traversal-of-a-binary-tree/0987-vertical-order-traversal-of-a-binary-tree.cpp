/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int,map<int,vector<int>>> order;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push(make_pair(root,make_pair(0,0)));
        if(root==NULL){
            return ans;
        }
        
        while(!q.empty()){
            pair<TreeNode*, pair<int,int>> temp=q.front();
            q.pop();
            TreeNode* node=temp.first;
            int horizontaldistanc=temp.second.first;
            int levelofnode=temp.second.second;
            
            order[horizontaldistanc][levelofnode].push_back(node->val);
            
            if(node->left){
                q.push(make_pair(node->left,make_pair(horizontaldistanc-1,levelofnode+1)));
            }
            if(node->right){
                q.push(make_pair(node->right,make_pair(horizontaldistanc+1,levelofnode+1)));
            }
        }
        
        for(auto a:order){
            vector<int> som;            
            for(auto b:a.second){

                if(b.second.size()==1){
                    som.push_back(b.second[0]);
                }else{
                    sort(b.second.begin(),b.second.end());
                    for(auto c:b.second){
                        som.push_back(c);
                    }
                }
                
            }
            ans.push_back(som);
        }
        
        return ans;
    }
};