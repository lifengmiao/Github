#include "stdafx.h"

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head) {
		if (head == NULL) return NULL;
		if (head->next == NULL) {
			TreeNode *root = new TreeNode(head->val);
			return root;
		}
		ListNode *slow = head;
		ListNode *fast = head;
		ListNode *pre;  //pointer one step before middle
		while (slow && fast && fast->next) { //(slow && fast->next) doesn't work? if fast == NULL, can't call fast->next??
			pre = slow; //one step before middle
			slow = slow->next;
			fast = fast->next->next;
		}
		pre->next = NULL;
		TreeNode *root = new TreeNode(slow->val);
		root->left = sortedListToBST(head);
		root->right = sortedListToBST(slow->next);
		return root;
	}
};