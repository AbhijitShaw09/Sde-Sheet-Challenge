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

vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    if(root == NULL)
        return {};

    queue<TreeNode<int>*> q;
    q.push(root);
    vector<int> ans;
    while(!q.empty()){
        int n = q.size();
        for(int i=1; i<=n; i++){
            TreeNode<int>* curr = q.front();
            q.pop();

            if(i == 1)
                ans.push_back(curr->data);
            if(curr->left != NULL)
                q.push(curr->left);
            if(curr->right != NULL)
                q.push(curr->right);
        }
    }
    return ans;
}
