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

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!
    if(root == NULL)
        return {};
    
    vector<int> ans;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    bool ltr = true;
    while(!q.empty()) {
        int sz = q.size();
        vector<int> row(sz);
        for(int i=0; i<sz; i++) {
            BinaryTreeNode<int> *node = q.front();
            q.pop();
            int index = (ltr) ? i : (sz-1-i);
            row[index] = node->data;
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        ltr = !ltr;
        for(auto i : row)
            ans.push_back(i);
    }
    return ans;
}
