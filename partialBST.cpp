/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

bool isBST(BinaryTreeNode<int>* root, BinaryTreeNode<int>* min = NULL, BinaryTreeNode<int>* max = NULL)
{
    if(root == NULL)
        return true;
    
    if(min != NULL && root->data < min->data)
        return false;
    
    if(max != NULL && root->data > max->data)
        return false;
    
    bool leftvalid = isBST(root->left, min, root);
    bool rightvalid = isBST(root->right, root, max);
    return leftvalid and rightvalid;
}
bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    if(isBST(root, NULL, NULL))
        return true;
    else 
        return false;
}
