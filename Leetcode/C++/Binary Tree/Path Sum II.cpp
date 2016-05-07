class Solution {
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> res;
		vector<int> list;
		dfs(root, res, list, sum);
		return res;
	}
	void dfs(TreeNode* root, vector<vector<int>> &res, vector<int> list, int sum) {
		if (root == NULL) return;
		list.push_back(root->val);
		if (root->left == NULL and root->right == NULL and root->val == sum) {
			res.push_back(list);
			return;
		}
		dfs(root->left, res, list, sum - root->val);
		dfs(root->right, res, list, sum - root->val);
	}