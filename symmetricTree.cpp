/*****************************************************

    Following is the Binary Tree node structure:
    
    class BinaryTreeNode {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/

bool symmetricHelp(BinaryTreeNode<int>* left, BinaryTreeNode<int>* right) {
    if(left == NULL || right == NULL)
        return left == right;
    if(left->data != right->data)
        return false;
    return symmetricHelp(left->left, right->right) && symmetricHelp(left->right, right->left);
}

bool isSymmetric(BinaryTreeNode<int>* root)
{
    // Write your code here.  
    return (root == NULL || symmetricHelp(root->left, root->right));
}
