/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/
#include<bits/stdc++.h>
vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    //    Write your code here.
    map<int, map<int, vector<int>>> nodes;
    queue<pair<TreeNode<int>*, pair<int, int>>> todo;
    if(root == NULL) return {};
    todo.push({root, {0, 0}});
    while(!todo.empty()){
        auto p = todo.front();
        todo.pop();
        TreeNode<int>* node = p.first;
        int x = p.second.first, y = p.second.second;
        nodes[x][y].push_back(node->data);
        if(node->left)
            todo.push({node->left, {x-1, y+1}});
        if(node->right)
            todo.push({node->right, {x+1, y+1}});
    }
    vector<int> ans;
    for(auto p : nodes) {
        for(auto q : p.second)
            for(auto k: q.second)
                ans.push_back(k);
    }
    return ans;
}
