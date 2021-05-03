/*剑指offer  26

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

/*572 另一个树的子树
给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树。
s 的一个子树包括 s 的一个节点和这个节点的所有子孙。s 也可以看做它自身的一棵子树。

*/

bool isSame(TreeNode* s,TreeNode* t)
{
	if(NULL==s && NULL == t) return true;
	if(NULL == s|| NULL ==t ) return false;

	return (s->val == t->val)&&isSame(s->left,t->left)&&isSame(s->right,t->right);
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
	if(NULL == root && NULL == subRoot) return true;
	if(NULL == root && NULL!=subRoot) return false;

	return isSame(root,subRoot)||isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot);
}

/*28 剑指28 对称的二叉树
请实现一个函数，用来判断一棵二叉树是不是对称的。
如果一棵二叉树和它的镜像一样，那么它是对称的。
例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
*/
bool isSymmetriccore(TreeNode* A,TreeNode* B)
{
	if(NULL == A && NULL == B) return true;
	if(NULL ==A || NULL == B) return false;
	return (A->val == B->val)&&isSymmetriccore(A->left,B->right)&&isSymmetriccore(A->right,B->left);
}

bool isSymmetric(TreeNode* root)
{
	return isSymmetriccore(root,root);
}























