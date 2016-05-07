//refer to Python solution in notebook
class Solution {
public:
	int maxPathSum(TreeNode* root) {
		if (root == NULL) return 0;
		int res = INT_MIN;
		int maxroot;
		maxroot = maxPathSumhelp(root, res);
		return res;
	}

	int maxPathSumhelp(TreeNode* root, int &res) {
		if (root == NULL) return 0;
		int maxleftpath = max(maxPathSumhelp(root->left, res), 0);
		int maxrightpath = max(maxPathSumhelp(root->right, res), 0);
		int currpath = maxleftpath + maxrightpath + root->val;
		res = max(res, currpath);
		return max(maxleftpath, maxrightpath) + root->val;
	}
};