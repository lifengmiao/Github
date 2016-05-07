// Link List.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL || head->next == NULL) return head;
		ListNode *dummy = new ListNode(-1);
		ListNode *p = dummy;
		ListNode *c = head;
		dummy->next = head;
		while (p->next) {
			while (c->next && p->next->val == c->next->val) {
				c = c->next;
			}
			if (p->next = c) {
				p = p->next;
				c = c->next;
			}
			else {
				p->next = c->next;
				c = c->next;
			}
		}
		head = dummy->next;
		delete(dummy);
		return head;
	}
};

int main()
{
	TreeNode *root;
	ListNode *head;
	ListNode *rest;
	ListNode head1(6); //alocate a memory
	head = new ListNode(1);  //new ListNode(x) return a pointer
	head->next = new ListNode(1);  //pointer must use -> 
	head1.next = head; //ListNode must use '.'
	head1.next->next = new ListNode(9);
	//head->next->next = new ListNode(4);
	Solution sol;
	rest = sol.deleteDuplicates(head);

    return 0;
}

