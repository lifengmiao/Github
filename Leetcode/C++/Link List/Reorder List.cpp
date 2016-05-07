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
	void reorderList(ListNode* head) {
		if (head == NULL or head->next == NULL) return; //void no need to return head; head change in line
		ListNode *slow = head;
		ListNode *fast = head;
		while (slow->next and fast->next and fast->next->next) {
			slow = slow->next;
			fast = fast->next->next;
		}
		ListNode *head1 = head;
		ListNode *head2 = slow->next;
		slow->next = NULL;
		head2 = reverseList(head2);
		head = mergeList(head1, head2);
	}
	ListNode* reverseList(ListNode *head) {
		if (head == NULL || head->next == NULL) return head;
		ListNode *p = NULL;
		ListNode *c = head;
		ListNode *tmp;
		while (c) {
			tmp = c->next;
			c->next = p;
			p = c;
			c = tmp;
		}
		return p;
	}
	ListNode* mergeList(ListNode* head1, ListNode* head2) {
		ListNode *p1 = head1;
		ListNode *p2 = head2;
		ListNode *tmp1;
		ListNode *tmp2;
		while (p2) {  //len of p2 is smaller than p1
			tmp1 = p1->next;
			tmp2 = p2->next;
			p1->next = p2;
			p2->next = tmp1;
			p1 = tmp1;
			p2 = tmp2;
		}
		return head1;
	}
};