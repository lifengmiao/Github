class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if (head == NULL || head->next == NULL) return head;
		ListNode *dummy = new ListNode(-1);
		ListNode *p = dummy;
		dummy->next = head;
		while (head && head->next) { //head need to be exit in order to cal head->next
			p->next = head->next;
			head->next = head->next->next;
			p->next->next = head;
			p = head;
			head = head->next;
		}
		head = dummy->next;
		delete(dummy);
		return head;
	}
};