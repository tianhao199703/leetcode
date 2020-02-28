vector<TreeNode*> generateTrees(int n) {
        if(n==0) return {};
        return helper(1,n+1);
    }
    vector<TreeNode*> helper(int l,int r){
        vector<TreeNode*> subTree;
        if (l >= r) {//n<=0的情况
            return {nullptr};
        }
        if (l == r - 1) {//n=1的情况
            subTree.push_back(new TreeNode(l));
            return subTree;
        }
        for (int i = l; i < r; ++i) {
        //分别生成左右子树
            vector<TreeNode*> leftSubTree = helper(l, i);
            vector<TreeNode*> rightSubTree = helper(i + 1, r);
            for (int m = 0; m < leftSubTree.size(); ++m) {//合并所有情况
                for (int n = 0; n < rightSubTree.size(); ++n) {
                    TreeNode *root = new TreeNode(i);
                    root->left = leftSubTree[m];
                    root->right = rightSubTree[n];
                    subTree.push_back(root);
                }
            }
        }
        return subTree;
    }
