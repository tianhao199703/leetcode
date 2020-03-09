    void recoverTree(TreeNode* root) {
        TreeNode *pre = nullptr;
        TreeNode *first = nullptr, *second = nullptr;
        TreeNode *temp = nullptr;
		while(root != nullptr){
			if(root->left != nullptr){
				temp = root->left;
				while(temp->right!=nullptr && temp->right != root)
					temp = temp->right;
				if(temp->right!=nullptr){
				    if(pre!=nullptr && pre->val > root->val){
				        if(first==nullptr){first = pre;second = root;}
				        else{second = root;}
				    }
				    pre = root;
					temp->right = nullptr;
					root = root->right;
				}
                else{
					temp->right = root;
					root = root->left;
				}
			}
            else{
				if(pre!=nullptr && pre->val > root->val){
				    if(first==nullptr){first = pre;second = root;}
				    else{second = root;}
				}
				pre = root;
				root = root->right;
			}
		}
		// swap two node values;
		swap(first->val,second->val);
    }
