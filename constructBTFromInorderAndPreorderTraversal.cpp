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

#include<bits/stdc++.h>
TreeNode<int> *build(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, map<int, int> &imp)
{
    if(preStart > preEnd || inStart > inEnd)
        return NULL;
    TreeNode<int> *root = new TreeNode<int>(preorder[preStart]);
    int inRoot = imp[root->data];
    int numsLeft = inRoot - inStart;
    root->left = build(preorder, preStart+1, preStart+numsLeft, inorder, inStart, inRoot-1, imp);
    root->right = build(preorder, preStart+numsLeft+1, preEnd, inorder, inRoot+1, inEnd, imp);
    return root;
}
TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	//    Write your code here
    map<int, int> imp;
    for(int i=0; i<inorder.size(); i++)
        imp[inorder[i]] = i;
    TreeNode<int> *root = build(preorder, 0, preorder.size() -1, inorder, 0, inorder.size()-1, imp);
    return root;
}
