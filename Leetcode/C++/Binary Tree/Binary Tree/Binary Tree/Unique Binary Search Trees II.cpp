class Solution {
public:
	vector<TreeNode*> generateTrees(int n) {
		if (n == 0) return{};
		vector<TreeNode*> res;
		res = dfs(1, n);
		return res;
	}

	vector<TreeNode*> dfs(int start, int end) {
		vector<TreeNode*> res;
		if (start > end)
		{
			res.push_back(NULL); //vector with one element==NULL. It is different with vector with no elment
			return res;
		}
		for (int i = start; i <= end; ++i) {  //start == end, there is one element; if there is no "for' loop, it is a normal recursive
											  //TreeNode* root = new TreeNode(i); //must creats later
			vector<TreeNode*> left = dfs(start, i - 1);
			vector<TreeNode*> right = dfs(i + 1, end);
			for (int k = 0; k<left.size(); ++k) {
				for (int j = 0; j<right.size(); ++j) {
					TreeNode* root = new TreeNode(i); //creat root here
					root->left = left[k];
					root->right = right[j];
					res.push_back(root);
				}
			}
		}
	}
};