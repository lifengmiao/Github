class Solution {
public:
	typedef vector<int>::iterator Itr;
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (nums.size() == 0) return NULL;
		return sortedArrayToBSThelp(nums.begin(), nums.end());
	}

	TreeNode* sortedArrayToBSThelp(Itr start, Itr end) {
		if (start == end) return NULL;
		int n = end - start;
		TreeNode* root = new TreeNode(*(start + (n + 1) / 2 - 1));
		root->left = sortedArrayToBSThelp(start, start + (n + 1) / 2 - 1);
		root->right = sortedArrayToBSThelp(start + (n + 1) / 2, end);
		return root;
	}
};