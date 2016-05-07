class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		std::vector<int> res;
		preorder(root, res);
		return res;
	}

	void preorder(TreeNode* root, vector<int> &res) {//without "&" copy res to another mem, and pass the new mem, 
													 //change of inside res will not change outside res; 
													 //with "&", don't copy, change inside res will change outside res
		if (root) {
			res.push_back(root->val);
			preorder(root->left, res);
			preorder(root->right, res);
		}
	}
};