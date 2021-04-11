#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> reverseprint(ListNode* head)
{
	if(!head)
		return {}
	vector<int>res = reverseprint(head->next);
	res.push_back(head->val);
	return res;
}

    vector<int> reversePrint(ListNode* head) {
        stack<ListNode*>st;
        vector<int>res;
        ListNode* pNode = head;
        while(pNode != NULL)
        {
            st.push(pNode);
            pNode=pNode->next;
        }
        while(st.size())
        {
            res.push_back(st.top()->val);
            st.pop();
        }
        return res;
    }


int main()
{
	return 0;
}
