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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (headA == NULL or headB == NULL) return NULL;
		int lenA = getlength(headA);
		int lenB = getlength(headB);
		ListNode *nodeA = headA;
		ListNode *nodeB = headB;
		if (lenA>lenB) {
			for (int i = 0; i<(lenA - lenB); ++i) {
				nodeA = nodeA->next;
			}
		}
		if (lenB>lenA) {
			for (int i = 0; i<(lenB - lenA); ++i) {
				nodeB = nodeB->next;
			}
		}
		while (nodeA != nodeB) { //can't compare val
			nodeA = nodeA->next;
			nodeB = nodeB->next;
		}
		return nodeA;
	}

	int getlength(ListNode *head) {
		int len = 0;
		while (head) {
			++len;
			head = head->next;
		}
		return len;
	}
};