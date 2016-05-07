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
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL || head->next == NULL) return head;
		ListNode *dummy = new ListNode(-1);
		ListNode *p = dummy;
		ListNode *c = head;
		dummy->next = head;
		while (p->next) {
			//inside while loop to skip the duplicated elements
			//different from the step by step method for I
			while (c->next && p->next->val == c->next->val) {  //c->next must exit to call c->next->val
				c = c->next;
			}
			if (p->next == c) { //no duplucate
				p = p->next;
				c = c->next;
			}
			else {
				p->next = c->next;  //skip all duplicate at one step
				c = c->next;
			}
		}
		head = dummy->next;
		delete(dummy);
		return head;
	}
};