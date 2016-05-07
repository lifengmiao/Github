class Solution {
public:
	ListNode* oddEvenList(ListNode* head) {
		if (head == NULL || head->next == NULL) return head;
		ListNode *dummy = new ListNode(-1);
		ListNode *even = dummy;
		ListNode *p = head;
		while (p && p->next) {
			even->next = p->next;
			even = even->next;
			if (p->next->next) { //take care of even number of elements, last p == NULL
				p->next = p->next->next;
				p = p->next;
			}
			else break;
		}
		even->next = NULL;  //cutoff with old list
		p->next = dummy->next;
		delete(dummy);
		return head;
	}
};