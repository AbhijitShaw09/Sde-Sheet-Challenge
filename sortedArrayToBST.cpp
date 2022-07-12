/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;
        
        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

TreeNode<int>* sortedArrayToBST(vector<int> &arr, int start, int end)
{
    if(start > end){
        return NULL;
    }
    int mid = (start + end) / 2;
    TreeNode<int>* root = new TreeNode<int>(arr[mid]);

    // Append nodes in left of root
    root->left = sortedArrayToBST(arr, start, mid-1);
    // Append nodes in right of root
    root->right = sortedArrayToBST(arr, mid+1, end);

    return root;
}
TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    // Write your code here.
    TreeNode<int>* root = sortedArrayToBST(arr, 0, arr.size()-1);
    return root;
}
