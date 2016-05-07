class Solution {
public:
	bool isValidSerialization(string preorder) {
		if (preorder.empty()) return false;
		istringstream ss(preorder);  //use istringstream to split preorder "92,2,3,24"
		vector<string> v; //splited strings save in vector
		string val;
		int d = 0;
		while (getline(ss, val, ',')) v.push_back(val); //v[0] = 92; v[1] = 2; v[2] = 3; v[2] = 24
		for (int i = 0; i < v.size() - 1; ++i) {
			if (v[i] == "#") {
				if (d == 0) return false;
				else --d;
			}
			else ++d;
		}
		return d != 0 ? false : v.back() == "#";
	}
};