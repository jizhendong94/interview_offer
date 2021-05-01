



ListNode* getKthFromEnd(ListNode* head, int k) {
	ListNode* fast = head;
	ListNode* slow = head;
	for(int i=0;i<k;i++)
	{
		if(fast == NULL) return NULL;
		fast = fast->next;
	}
	while(fast!=NULL)
	{
		fast=fast->next;
		slow = slow->next;
	}
	return slow;
	
}
