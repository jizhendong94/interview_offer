//leetcode 426
/* 36 offer  

输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。
要求不能创建任何新的节点，只能调整树中节点指针的指向。

   class Node {
   public:
   int val;
   Node* left;
   Node* right;

   Node() {}

   Node(int _val) {
   val = _val;
   left = NULL;
   right = NULL;
   }

   Node(int _val, Node* _left, Node* _right) {
   val = _val;
   left = _left;
   right = _right;
   }
   };

算法流程：
dfs(cur): 递归法中序遍历；

1. 终止条件： 当节点 cur 为空，代表越过叶节点，直接返回；
2. 递归左子树，即 dfs(cur.left) ；
3 构建链表：
	当 pre 为空时： 代表正在访问链表头节点，记为 head ；
	当 pre 不为空时： 修改双向节点引用，即 pre.right = cur ， cur.left = pre ；
	保存 cur ： 更新 pre = cur ，即节点 cur 是后继节点的 pre ；
4. 递归右子树，即 dfs(cur.right) ；

 */

Node* pre=NULL,*head=NULL;

void dfs(Node* cur)
{
	if(cur == NULL) return;
	dfs(cur->left);

	if(pre != NULL) pre->right = cur;
	else head = cur;
	cur->left = pre;
	pre=cur;

	dfs(cur->right);
}

Node* treeToDoublyList(Node* root) {
	if(NULL == root) return NULL;
	dfs(root);
	head->left =pre;
	pre->right = head;
	return head;
}








