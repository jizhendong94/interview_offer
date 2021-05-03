/*  32  offer

	从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。

	给定二叉树: [3,9,20,null,null,15,7],返回： [3,9,20,15,7]

 */

vector<int> levelOrder(TreeNode* root) {
	vector<int>res;
	if(NULL == root) return res;
	queue<TreeNode*>q;
	q.push(root);
	while(!q.empty()){
		int size = q.size();
		for(int i =0;i<size;i++)
		{
			TreeNode* temp = q.front();
			q.pop();
			res.push_back(temp->val);
			if(temp->left) q.push(temp->left);
			if(temp->right) q.push(temp->right);
		}
	}
	return res;
}

/*
   从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。
   给定二叉树: [3,9,20,null,null,15,7],

   返回：
   [
   [3],
   [9,20],
   [15,7]
   ]
 */

vector<vector<int>> levelOrder(TreeNode* root) {
	vector<vector<int>>res;
	if(NULL == root) return res;
	queue<TreeNode*>q;
	q.push(root);
	while(!q.empty()){
		int size = q.size();
		vector<int>temp;  //每次一行  是新的
		for(int i=0;i<size;i++)
		{
			TreeNode* cur = q.front();
			q.pop();
			temp.push_back(cur->val);
			if(cur->left) q.push(cur->left);
			if(cur->right) q.push(cur->right);
		}
		res.push_back(temp);
	}
	return res;
}

/*
   请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，
   第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。
 */

vector<vector<int>> levelOrder(TreeNode* root) {
	vector<vector<int>>res;
	if(root==NULL) return res;
	queue<TreeNode*>q;
	q.push(root);
	bool reverse = false;
	while(q.size())
	{
		vector<int>v;
		int size=q.size();
		while(size--)
		{
			TreeNode* temp=q.front();
			q.pop();
			v.push_back(temp->val);
			if(temp->left) q.push(temp->left);
			if(temp->right) q.push(temp->right);
		}
		if(reverse)
			res.push_back(vector<int>(v.rbegin(),v.rend()));
		else
			res.push_back(v);
		reverse=!reverse;

	}
	return res;
}











