/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
int height(TreeNode<int> *node, int &ans) {
    if(!node)
        return 0;
    int lh = height(node->left, ans);
    int rh = height(node->right, ans);
    ans = max(ans, lh+rh);
    return 1 + max(lh, rh);
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
	// Write Your Code Here.
    int ans = 0;
    height(root, ans);
    return ans;
}
