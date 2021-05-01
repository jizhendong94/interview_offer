/*

输入两课二叉树，判断B是不是A的子结构，约定空树不是任意一个树的子结构

B是A的子结构，即A中出现和B相同的结构和节点值
*/
bool dfs(TreeNode* A,TreeNode* B)
{
	if(B==NULL) return true;
	if(A==NULL) return false;
	return (A->val == B->val)&&dfs(A->left,B->left)&&dfs(A->right,B->right);
}

bool isSubStruct(TreeNode* A,TreeNode* B)
{
	if(NULL == A || NULL == B ) return false;
	return dfs(A,B)||isSubStruct(A->left,B)||isSubStruct(A->right,B);
}
