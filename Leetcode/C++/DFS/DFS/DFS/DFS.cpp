// DFS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> res;
		dfs(n, n, "", res);
		return res;
	}

	void dfs(int right, int left, string list, vector<string> &res) {
		if (right == 0 && left == 0) {
			res.push_back(list);
			return;
		}
		if (left>0) {
			dfs(right, left - 1, list + '(', res);
		}
		if (right>left) {
			dfs(right - 1, left, list + ')', res);
		}
	}
};

int main()
{
	Solution sol;
	vector<int> nums{ 1};
	vector<char> tmp{ 'O' };
	vector<vector<char>> board;
	board.push_back(tmp);
	//vector<vector<int>> res = sol.combinationSum(nums,2);
	string s = { "aaa" };

	vector<string> res = sol.generateParenthesis(3);
	return 0;
}

