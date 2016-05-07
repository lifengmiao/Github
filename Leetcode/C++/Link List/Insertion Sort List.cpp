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
	ListNode* insertionSortList(ListNode* head) {
		if (head == NULL or head->next == NULL) return head;
		ListNode *dummy = new ListNode(-1);  //dummy needed, since head may change
		ListNode *p = dummy;
		dummy->next = head;
		ListNode *node = head;
		ListNode *tmp;
		while (node->next) {
			if (node->next->val < node->val) {
				while (p->next->val <= node->next->val) { //use the previous pointer instead of the curr pointer for insert
					p = p->next;
				}
				tmp = node->next;  //pick the element needed to insert
				node->next = tmp->next;
				tmp->next = p->next;
				p->next = tmp;
				p = dummy;
			}
			else {
				node = node->next;
			}
		}
		head = dummy->next;  //don't forget to release mem
		delete(dummy);
		return head;
	}
};