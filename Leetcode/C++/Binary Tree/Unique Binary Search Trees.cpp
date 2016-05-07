class Solution {
public:
	int numTrees(int n) {
		vector<int> dp(n + 1); //initialize given size of vector
		dp[0] = dp[1] = 1; //assign certain elements
		dp[2] = 2;
		if (n <= 2) return dp[n];
		for (int i = 3; i <= n; ++i) {
			for (int j = 0; j<i; ++j) {
				dp[i] = dp[i] + dp[j] * dp[i - 1 - j];
			}
		}
		return dp[n];
	}
};