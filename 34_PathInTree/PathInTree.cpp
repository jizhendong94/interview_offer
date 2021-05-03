/*offer 34 

  输入一棵二叉树和一个整数，打印出二叉树中节点值的和为输入整数的所有路径。
  从树的根节点开始往下一直到叶节点所经过的节点形成一条路径。

回溯算法：
	终止条件： 当前节点 = NULL  直接返回
	递推工作： 1：路径更新，将当前节点值root->val 加入Path
			   2：目标值更新 target = target-root->val;
			   3：记录路径，如果root为叶节点且target=0 将Path加入到res
			   4：递归遍历左/右 子节点
			   5：路径恢复 将当前节点从path中删除。
 */


vector<vector<int>>res;
void backtrack(TreeNode* root,int target,vector<int>& path)
{
	if(root == NULL) return;
	path.push_back(root->val);
	target -= root->val;
	if(target == 0 && root->left==NULL && root->right==NULL)
		res.push_back(path);
	backtrack(root->left,target,path);
	backtrack(root->right,target,path);
	path.pop_back();
}


vector<vector<int>> pathSum(TreeNode* root, int target) {
	vector<int>path;
	backtrack(root,target,path);
	return res;
}












