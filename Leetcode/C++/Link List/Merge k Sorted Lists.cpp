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
	ListNode* mergeKLists(vector<ListNode*>& lists) {//input is a vector with each element as pointer to ListNode
		int n = lists.size();
		if (n == 0)return NULL;
		if (n == 1)return lists[0];
		ListNode *head1;
		ListNode *head2;
		std::vector<ListNode*> new_lists1(lists.begin(), lists.begin() + (n + 1) / 2); //build new vector contain lists[0:(n+1)/2]
		std::vector<ListNode*> new_lists2(lists.begin() + (n + 1) / 2, lists.end());
		head1 = mergeKLists(new_lists1); //recursive
		head2 = mergeKLists(new_lists2);
		return mergeList(head1, head2);
	}

	ListNode* mergeList(ListNode *head1, ListNode *head2) {
		ListNode *dummy = new ListNode(-1);
		ListNode *p = dummy;
		while (head1 && head2) {
			if (head1->val < head2->val) {
				p->next = head1;
				head1 = head1->next;
			}
			else {
				p->next = head2;
				head2 = head2->next;
			}
			p = p->next;
		}
		if (head1 != NULL) p->next = head1;
		if (head2 != NULL) p->next = head2;
		p = dummy->next;
		delete(dummy);
		return p;
	}

};