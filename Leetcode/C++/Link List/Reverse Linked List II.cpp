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
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (head == NULL or head->next == NULL or n == m) return head;
		ListNode *dummy = new ListNode(-1); //must creat to handle m = 1 case
		ListNode *last = dummy; //needed to connect the start of the sorted part
		dummy->next = head;
		for (int i = 0; i<m - 1; ++i) {
			last = last->next;
		}
		ListNode *tail = last->next; //needed to connect the end of the sorted part

		ListNode *p = tail;
		ListNode *c = tail->next; //start from the second one
		ListNode *tmp;
		for (int i = 0; i<(n - m); ++i) {
			//if(c){ //no need, since length>=n>=m, c must exit
			tmp = c->next;
			c->next = p;
			p = c;
			c = tmp;
		}
		tail->next = c;
		last->next = p;
		head = dummy->next;
		delete(dummy);
		return head;
	}
};