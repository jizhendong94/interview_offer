

/*合并两个排序的链表
递归做法
*/

ListNode* mergeTwoList(ListNode* l1,ListNode* l2)
{
	if(NULL == l1) return l2;
	if(NULL == l2) return l1;

	if(l1->val < l2->val){
		l1->next = mergeTwoList(l1->next,l2);
		return l1;
	}
	else{
		l2->next = mergeTwoList(l1,l2->next);
		return l2;
	}
}



/*
迭代解法

*/

ListNode* mergeTwoList(ListNode* l1,ListNode* l2)
{
	ListNode* dummynode = new ListNode(-1),*pre = dummynode;
	while(l1!=NULL && l2!=NULL)
	{
		if(l1->val < l2->val){
			pre->next = l1;
			pre=pre->next;
			l1=l1->next;
		}else{
			pre->next = l2;
			pre = pre->next;
			l2=l2->next;
		}
	}
	if(l1!=NULL) pre->next = l1;
	if(l2!=NULL) pre->next = l2;
	return dummynode->next;
}





