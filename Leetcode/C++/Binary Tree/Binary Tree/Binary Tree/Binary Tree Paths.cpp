class Solution {
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> res;
		dfs(root, "", res);
		return res;
	}

	void dfs(TreeNode* root, string list, vector<string> &res) {
		if (root == NULL) return;
		list += to_string(root->val); //int to string
		if (root->left == NULL and root->right == NULL) {
			res.push_back(list);
			return;
		}
		dfs(root->left, list + "->", res);
		dfs(root->right, list + "->", res);

	}
};