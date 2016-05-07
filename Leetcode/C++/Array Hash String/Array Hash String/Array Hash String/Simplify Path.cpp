class Solution {
public:
	string simplifyPath(string path) {
		string curr;
		vector<string> addr;
		string res;
		path.push_back('/');
		for (int i = 0; i<path.size(); ++i) {
			if (path[i] != '/') curr.push_back(path[i]);
			else {
				if (curr.empty()) continue;
				else if (curr == ".") curr.clear();
				else if (curr == "..") {
					if (addr.empty() != 1) addr.pop_back();
					curr.clear();
				}
				else {
					addr.push_back(curr);
					curr.clear();
				}
			}
		}
		for (int j = 0; j<addr.size(); ++j) {
			res += '/' + addr[j];
		}
		if (res.empty()) res.push_back('/');
		return res;
	}
};