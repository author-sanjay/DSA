class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
     if (!root)
      return {};

    vector<int> res;
    stack<TreeNode*> stack{{root}};

    while (!stack.empty()) {
      root = stack.top(), stack.pop();
      res.push_back(root->val);
        
      if (root->right)
        stack.push(root->right);
        
      if (root->left)
        stack.push(root->left);
    }


    return res;  
    }
};
