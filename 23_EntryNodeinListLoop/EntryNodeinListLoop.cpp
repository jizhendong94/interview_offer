/*  141 环形链表
给定一个链表，判断链表中是否有环。

如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 
为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，
仅仅是为了标识链表的实际情况。

如果链表中存在环，则返回 true 。 否则，返回 false 。


*/

bool hasCycle(ListNode* head)
{
	ListNode* fast = head;
	ListNode* slow = head;
	while(fast!=NULL && fast->next!=NULL)
	{
		fast=fast->next->next;
		slow = slow->next;
		if(fast == slow)
			return true;
	}
	return false;
}

/*环形链表2   142

给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
如果 pos 是 -1，则在该链表中没有环。注意，pos 仅仅是用于标识环的情况
，并不会作为参数传递到函数中。

说明：不允许修改给定的链表。


*/

//方法一：哈希表
//思路与算法

//一个非常直观的思路是：我们遍历链表中的每个节点，并将它记录下来；
//一旦遇到了此前遍历过的节点，就可以判定链表中存在环。借助哈希表可以很方便地实现。

ListNode* detectCycle(ListNode* head)
{
	unordered_set<ListNode*>visited;
	ListNode* temp =head;
	while(temp)
	{
		if(visited.count(temp))
			return temp;
		visited.insert(head);
		head=head->next;
	}
	return NULL;
}


/* 双指针法
从相遇点到入环点的距离加上 n-1n−1 圈的环长，恰好等于从链表头部到入环点的距离。

*/

ListNode* detectCycle(ListNode* head)
{
	ListNode* fast =head;
	ListNode* slow =head;
	while(fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if(fast == slow){
			ListNode* temp = head;
			while(temp != slow)
			{
				temp=temp->next;
				slow = slow->next;
			}
			return temp;
		}
	}
	return NULL;
}






















