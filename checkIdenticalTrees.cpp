/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>

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
    };

***********************************************************/

bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    // Write your code here. 	 
    if(root1 == NULL && root2 == NULL)
        return true;
    else if(root1 == NULL || root2 == NULL)
        return false;
    else {
        bool cond1 = root1->data == root2->data;
        bool cond2 = identicalTrees(root1->left, root2->left);
        bool cond3 = identicalTrees(root1->right, root2->right);

        if(cond1 && cond2 && cond3)
            return true;
        return false;
    }
}
