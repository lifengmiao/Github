class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> res;
		zigzagtraver(root, 0, res);
		return res;
	}
	void zigzagtraver(TreeNode* root, int level, vector<vector<int>> &res) {
		if (root) {
			if (res.size() <= level) {
				vector<int> tmp;
				tmp.push_back(root->val);
				res.push_back(tmp);
			}
			else {
				if (level % 2 == 0) {
					res[level].push_back(root->val);
				}
				else res[level].insert(res[level].begin(), root->val); //must be res[level].begin() can't be res.begin()
			}
			zigzagtraver(root->left, level + 1, res);
			zigzagtraver(root->right, level + 1, res);
		}
	}
};