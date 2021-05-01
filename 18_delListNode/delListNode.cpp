#include<iostream>
using namespace std;


/*leetcode 剑指offer 18  比书中简单一些

给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。
返回删除后的链表的头节点。
注意：此题对比原题有改动

*/
//leetcode 剑指offer 18  比书中简单一些

//方法1 递归
ListNode* deleteNode(ListNode* head, int val)
{
	if(head == NULL) return NULL;
	if(head->val == val) return head->next;
	head->next = deleteNode(head->next,val);
	return head;
}

//建立哑结点  不用在判断是不是头结点了 
//方便对头节点的操作，创建哑节点dummyhead
//cur = dummyhed, cur指向当前节点
//cur = cur->next，进行链表遍历
ListNode* deleteNode(ListNode* head,int val)
{
	ListNode* dummynode = New ListNode(INT_MIN);
	dummynode->next = head;
	ListNode* cur =dummynode;
	while(cur!=NULL && cur->next!=NULL)
	{
		if(cur->next->val == val)
		{
			cur->next = cur->next->next;
			break;
		}
		cur = cur->next;
	}
	return dummynode->next;
}


//剑指offer原题  时间复杂度要求O(1)
void DeleteNode(ListNode* head,ListNode* toDeleNode)
{
	if(NULL == head || NULL == toDeleNode) return;

	if(toDeleNode->next != NULL)  //要删除的节点不是尾结点
	{
		ListNode* next = toDeleNode->next;
		toDeleNode->val = next->val;
		toDeleNode->next = next->next;
		delete next;
		next = NULL;
	}
	else if(head == toDeleNode)  //链表只有一个节点，头结点也是尾结点
	{
		delete toDeleNode;
		toDeleNode = NULL;
		head = NULL;
	}
	else                        //删除尾结点 只能从都遍历
	{
		ListNode* temp = head;
		while(temp->next != toDeleNode)
		{
			temp=temp->next;
		}
		temp->next = NULL;
		delete toDeleNode;
		toDeleNode = NULL;
	}
}

//删除排序链表中的重复元素 leetcode 83 
/*
存在一个按升序排列的链表，给你这个链表的头节点 head ，请你删除所有重复的元素，
使每个元素 只出现一次 。
返回同样按升序排列的结果链表。
*/

ListNode* deleteDuplicates(ListNode* head)
{
	if(NULL == head) return NULL;
	ListNode* cur = head;
	while(cur->next != NULL)
	{
		if(cur->val == cur->next->val)
		{
			cur->next = cur->next->next;
		}
		else
		{
			cur = cur->next;
		}
	}
	return head;
}





int main()
{
	return 0;
}







