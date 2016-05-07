class Solution {
public:
	bool wordPattern(string pattern, string str) {
		unordered_map<char, string> myMap;
		istringstream ss(str);
		vector<string> val;
		string word;
		while (ss >> word) {
			val.push_back(word);
		}
		if (pattern.size() != val.size()) return false;
		for (int i = 0; i<pattern.size(); ++i) {
			if (myMap.count(pattern[i])) {
				if (myMap[pattern[i]] != val[i]) return false;
			}
			else {
				for (auto n : myMap) {
					if (n.second == val[i]) return false;
				}
				myMap[pattern[i]] = val[i];
			}
		}
		return true;
	}
};