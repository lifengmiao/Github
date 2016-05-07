class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		if (head == NULL || head->next == NULL) return head;
		ListNode *dummy = new ListNode(-1);
		ListNode *c = dummy;
		ListNode *p = dummy;
		ListNode *tmp;
		dummy->next = head;
		while (c->next && c->next->val < x) { //handle beginning element < x
			c = c->next;
			p = p->next;
		}
		while (c->next) {  //remove element and insert it into front position
			if (c->next->val >= x) c = c->next;
			else {
				tmp = c->next;
				c->next = tmp->next;
				tmp->next = p->next;
				p->next = tmp;
				p = p->next;
			}
		}
		head = dummy->next;
		delete(dummy);
		return head;
	}
};

class Solution2 {
public:
	ListNode *partition(ListNode *head, int x) {
		// Start typing your C/C++ solution below  
		// DO NOT write int main() function  
		if (head == NULL) return NULL;

		ListNode* a = new ListNode(0);
		ListNode* pSmall = a;
		ListNode* b = new ListNode(0);
		ListNode* pLarge = b;

		while (head != NULL)
		{
			if (head->val < x)
			{
				pSmall->next = head;
				pSmall = head;
				head = head->next;
			}
			else
			{
				pLarge->next = head;
				pLarge = head;
				head = head->next;
			}
		}

		pLarge->next = NULL;
		pSmall->next = b->next;
		return a->next;
	}
};