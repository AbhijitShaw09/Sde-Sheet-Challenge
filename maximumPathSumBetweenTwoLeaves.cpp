/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int count;
long long int solve(TreeNode<int> *root, long long int& ans)
{
    if(root == NULL) return 0;
    
    if(root -> left == NULL && root -> right == NULL) count++;
    long long int left = solve(root -> left, ans);
    long long int right = solve(root -> right, ans);
    
    long long int temp = max(left, right) + root -> val;
    
    long long int mx = max(temp, left + right + root -> val);
    ans = max(ans, mx);
    
    return temp;
}
long long int findMaxSumPath(TreeNode<int> *root)
{
    // Write your code here.
    if(root == NULL) return -1;
    count = 0;
    long long int ans = 0;
    solve(root, ans);
   
    if(count == 1) return -1;
    return ans;
}
