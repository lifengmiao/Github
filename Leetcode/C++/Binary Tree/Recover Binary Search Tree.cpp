//http://yucoding.blogspot.com/2013/03/leetcode-question-75-recover-binary.html
//Note that, (1)the previous element is NOT the root node of the current element,
//but the previous element in the "inOrder" order; (2) To store the wrong pair, 
//the first found wrong element is stored in first pointer, while the next is stored in the second pointer.
class Solution {
public:
	TreeNode *first; //global class scope
	TreeNode *second;
	TreeNode *pre;

	void inOrder(TreeNode *root) {
		if (root == NULL) { return; }
		else {
			inOrder(root->left);
			if (pre == NULL) { pre = root; }
			else {
				if (pre->val > root->val) {
					if (first == NULL) { first = pre; } //The first wrong node must be the larger one in inorder traversal
					second = root; //the second wrong node must be the smaller one in inorder traversal
				}
				pre = root;
			}
			inOrder(root->right);

		}
	}
	void recoverTree(TreeNode *root) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		pre = NULL;
		first = NULL;
		second = NULL;
		inOrder(root);  //find the location of two wrong nodes and save in TreeNode* first and TreeNode* second
		int val;
		val = first->val;
		first->val = second->val;
		second->val = val;
		return;
	}
};