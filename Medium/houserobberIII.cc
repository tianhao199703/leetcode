    int rob(TreeNode* root) {
        auto [best_with_root, best_without_root] = robmax(root);
        return max(best_with_root, best_without_root);
    }
    pair<int, int> robmax(TreeNode* root){
        if (!root) {
            return {0, 0};
        }
        auto [left_with_node, left_without_node] = robmax(root->left);
        auto [right_with_node, right_without_node] = robmax(root->right);
        
        int max_with_val = root->val + left_without_node + right_without_node;
        int max_without_val = max(left_with_node, left_without_node)
                            + max(right_with_node, right_without_node);
        return {max_with_val, max_without_val};
        
    }
