
/*
请完成一个函数，输入一个二叉树，该函数输出它的镜像。
*/


//递归方式
void mirrorTreecore(TreeNode* root)
{
	if(NULL == root) return;
	if(NULL == root->left && NULL == root->right) return;
	TreeNode* temp = root->left;
	root->left = root->right;
	root->right = temp;
	mirrorTreecore(root->left);
	mirrorTreecore(root->right);
}
TreeNode* mirrorTree(TreeNode* root) {
	mirrorTreecore(root);
	return root;
}


//用队列存储 值
TreeNode* mirrorTree(TreeNode* root)
{
	if(NULL == root) return root;
	queue<TreeNode*>q;
	q.push(root);
	while(!q.empty())
	{
		TreeNode* temp = q.front();
		q.pop();
		swap(temp->left,temp->right);
		if(temp->left) q.push(temp->left);
		if(temp->right) q.push(temp->right);

	}
	return root;
}











