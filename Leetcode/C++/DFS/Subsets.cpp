class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> res;
		vector<int> list;
		res.push_back(list);
		//if(nums.size()==0) return res;
		sort(nums.begin(), nums.end());
		dfs(nums, 0, list, res);
		return res;
	}
	void dfs(vector<int>nums, int start, vector<int> list, vector<vector<int>> &res) {
		for (int i = start; i<nums.size(); ++i) {
			list.push_back(nums[i]); //push new element into list, need to pop at the end. different from Python, in python pass list+[new node] into next level, no need to pop.
			res.push_back(list);
			dfs(nums, i + 1, list, res); //must be i+1 instead of start+1
			list.pop_back(); //need to pop the new added element. different with Python
		}
	}
};