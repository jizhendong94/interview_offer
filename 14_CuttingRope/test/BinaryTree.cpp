#include<iostream>
using namespace std;

typedef struct _TreeNode{
	_TreeNode* left;
	_TreeNode* right;
	int val;
}TreeNode;

void MidPrintTree(TreeNode *head)
{
	if(NULL == head) return;
	
	if(NULL != head->left)
		MidPrintTree(head->left);
	cout<<head->val<<endl;
	if(NULL != head->right)
		MidPrintTree(head->right);
	return;
}

int main(int argc,const char* argv[])
{
	TreeNode* head = new TreeNode;
	head->val = 10;
	TreeNode* head_left = new TreeNode;
	head_left->val = 20;
	TreeNode* head_right = new TreeNode;
	head_right->val = 30;
	TreeNode* right_r = new TreeNode;
	right_r->val = 40;

	head->left = head_left;
	head->right = head_right;
	head_right->right = right_r;
	head->right->left = NULL;
	right_r->left = NULL;
	right_r->right=NULL;
	MidPrintTree(head);
#if 1
	delete head;
	delete head_left;
	delete head_right;
	delete right_r;
#endif
	return 0;
}

