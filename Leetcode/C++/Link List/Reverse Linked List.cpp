/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == NULL or head->next == NULL) return head;
		ListNode *p = NULL;  //no need to creat dummy node
		ListNode *c = head;
		ListNode *t;
		while (c) {
			t = c->next;
			c->next = p;
			p = c;
			c = t;
		}
		return p;
	}
};