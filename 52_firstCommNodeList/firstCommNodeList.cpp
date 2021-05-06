/*offer 52
  输入两个链表，找出它们的第一个公共节点。
 */


//常规方式
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	if(NULL == headA || NULL == headB) return NULL;
	ListNode* pa=headA,*pb=headB;
	int lena=0,lenb=0;
	while(pa!=NULL){
		lena++;
		pa=pa->next;
	}
	while(pb!=NULL){
		lenb++;
		pb=pb->next;
	}
	if(pa == pb){
		if(lena>lenb){
			while(lena-lenb>0){
				lena--;
				headA=headA->next;
			}
		}
		if(lenb>lena){
			while(lenb-lena>0){
				lenb--;
				headB=headB->next;
			}
		}
		while(headA!=headB){
			headA=headA->next;
			headB=headB->next;
		}
		return headA;
	}else{
		return NULL;
	}

}


//
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	if(NULL == headA || NULL == headB) return NULL;
	ListNode* h1=headA,*h2=headB;
	while(h1!=h2){
		h1 = h1==NULL?headB:h1->next;
		h2 = h2==NULL?headA:h2->next;
	}
	return h1;
}








