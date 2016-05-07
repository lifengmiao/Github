class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> res;
		vector<int> list;
		vector<bool> used(nums.size(), false); //initialize a vector
		dfs(nums, 0, used, list, res);
		return res;
	}

	void dfs(vector<int>nums, int level, vector<bool> &used, vector<int> list, vector<vector<int>> &res) {
		if (level == nums.size()) {
			res.push_back(list);
			return;
		}
		for (int i = 0; i<nums.size(); ++i) { //i from 0, no start as subset
			if (used[i]) continue;  //in the deeper layer, can be used again
			if (i>0 && nums[i] == nums[i - 1] && used[i - 1] == false) continue; //must decide duplicate in same level, if used[i-1]==true means i and i-1 not in same level
			used[i] = true; //set as used
			list.push_back(nums[i]);
			dfs(nums, level + 1, used, list, res);
			list.pop_back();
			used[i] = false; //release used; since in the same layer it can be used again
		}
	}
};