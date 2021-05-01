/*
常规做法
维护三个节点 pre  cur next 
*/

ListNode* reverseList(ListNode* head)
{
	ListNode* pre = NULL;
	ListNode* temp=head;
	ListNode* head_new = NULL;
	while(temp != NULL)
	{
		if(temp->next == NULL)
			head_new = temp;
		ListNode* next = temp->next;
		temp->next = pre;
		pre = temp;
		temp = next;
	}
	return head_new;

}


/*
递归  做法
*/

ListNode* reverseList(ListNode* head)
{
	if(head == NULL || head->next == NULL) return head;
	ListNode* head_new = reverseList(head->next);
	head->next->next = head;
	head->next = NULL;
	return head_new;
}


