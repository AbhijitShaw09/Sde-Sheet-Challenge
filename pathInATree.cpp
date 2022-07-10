/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
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
*/

void traverse(TreeNode<int>* node, int x, vector<int>& ans){
    if(!node) return;
    
    ans.push_back(node->data);

    if(node->data == x) return;

    traverse(node->left, x, ans);
    traverse(node->right, x, ans);

    if(ans[ans.size()-1] != x)
        ans.pop_back();
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
    vector<int> ans;
    traverse(root, x, ans);
    return ans;
}
