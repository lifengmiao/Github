/**
* Definition for singly-linked list with a random pointer.
* struct RandomListNode {
*     int label;
*     RandomListNode *next, *random; //two pointer
*     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
* };
*/
class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (head == NULL) return NULL;
		//insert node
		RandomListNode *c = head;
		while (c) {
			RandomListNode *node = new RandomListNode(c->label);
			node->next = c->next;
			c->next = node;
			c = node->next;
		}

		//copy random pointer
		c = head;
		while (c) {
			if (c->random != NULL) { //if c->random==NULL, can't call c->random->next
				c->next->random = c->random->next;
			}
			c = c->next->next;
		}

		//separate (note can't change the original list)
		c = head;
		RandomListNode *head2 = head->next;
		RandomListNode *p = head2;
		while (c) {
			c->next = p->next;
			c = c->next;
			if (p->next) {
				p->next = p->next->next;
				p = p->next;
			}
		}

		return head2;

	}
};