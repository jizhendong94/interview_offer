#include<iostream>
#include<vector>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//已知前序和中序 构造二叉树
TreeNode* buildTreeCore(vector<int>& preorder,vector<int>& inorder,int& pos,int left,int right)
{
	if(pos>=inorder.size()) return NULL;
	int i = left;
	for(i=left;i<=right;i++)
	{
		if(inorder[i] == preorder[pos])
			break;
	}

	TreeNode* root = new TreeNode(preorder[pos]);
	if(left<=i-1) root->left = buildTreeCore(preorder,inorder,++pos,left,i-1);
	if(i+1<=right) root->right = buildTreeCore(preorder,inorder,++pos,i+1,right);
	return root;
}

TreeNode* buildTree(vector<int>& preorder,vector<int>& inorder)
{
	int pos = 0;
	return buildTreeCore(preorder,inorder,pos,0,inorder.size()-1);
}

//已知前序和中序 构造二叉树


//        // 已知中序和后序遍历  构造二叉树  
TreeNode* buildTreeCore(vector<int>& inorder,vector<int>& postorder,int& pos,int left,int right)
{
	if(pos<0) return NULL;
	int i=left;
	for(i=left;i<=right;i++)
	{
		if(inorder[i] == postorder[pos])
			break;
	}
	TreeNode * root = new TreeNode(postorder[pos]);
	if(i+1<=right) root->right=buildTreeCore(inorder,postorder,--pos,i+1,right);
	if(left<=i-1) root->left=buildTreeCore(inorder,postorder,--pos,left,i-1);

	return root;
}

TreeNode* buildTree(vector<int>& inorder,vector<int>& postorder)
{
	int pos = postorder.size()-1;
	return buildTreeCore(inorder,postorder,pos,0,postorder.size()-1);
}

//



int main()
{
	return 0;

}
