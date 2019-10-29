TreeNode * dfsTraverse(TreeNode * root, TreeNode * p , TreeNode * q)
{
    if( root == p || root == q || root == NULL)
        return root;
    TreeNode * parent1 = dfsTraverse(root->left, p, q);
    TreeNode * parent2 = dfsTraverse(root->right, p, q);
    if( parent1 && parent2)//如果待查找的p，q分散在root的左右子树中，返回root
        return root;
    else
        return parent1 ? parent1:parent2;//否则返回对应存在的子树
}
