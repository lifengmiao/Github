class Solution {
public:
	void flatten(TreeNode* root) {
		if (root == NULL) return;
		flatten(root->left);
		flatten(root->right);
		TreeNode *p = root;
		if (p->left == NULL) return;  //no left subtree, so it is already flatten, go back to higher level
		p = root->left;
		while (p->right) p = p->right;
		p->right = root->right;
		root->right = root->left;
		root->left = NULL;

	}
};