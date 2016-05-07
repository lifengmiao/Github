class Solution {
public:
	ListNode* sortList(ListNode* head) {
		if (head == NULL or head->next == NULL) return head;
		ListNode *slow = head;
		ListNode *fast = head;
		while (slow->next && fast->next && fast->next->next) { //fast->next need to exit for call fast->next->next
			slow = slow->next;
			fast = fast->next->next;
		}
		ListNode *head1 = head;
		ListNode *head2 = slow->next;
		slow->next = NULL;
		head1 = sortList(head1);
		head2 = sortList(head2);
		head = mergeList(head1, head2);
		return head;
	}

	ListNode* mergeList(ListNode* head1, ListNode *head2) {
		ListNode *dummy = new ListNode(-1); //dummy needed to point to the head
		ListNode *p = dummy;
		if (head1 == NULL) return head2;
		if (head2 == NULL) return head1;
		while (head1 != NULL && head2 != NULL) {
			if (head1->val < head2->val) {
				p->next = head1;
				head1 = head1->next;
			}
			else {
				p->next = head2;
				head2 = head2->next;
			}
			p = p->next;  //p move forward
		}
		if (head1 != NULL) p->next = head1;
		if (head2 != NULL) p->next = head2;
		p = dummy->next;
		delete(dummy);
		return p;
	}
};