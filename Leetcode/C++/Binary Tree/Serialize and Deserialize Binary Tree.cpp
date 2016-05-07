class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		string out;
		serhelp(root, out);
		return out;
	}

	void serhelp(TreeNode* root, string &out) {
		if (root) {
			out += to_string(root->val);
			serhelp(root->left, out);
			serhelp(root->right, out);
		}
		else out += '#';
	}

	TreeNode* deserialize(string data) {
		return deshelp(data);
	}

	TreeNode* deshelp(string &data) {
		if (data.length() == 0) return nullptr; //return pointer point to NULL
		if (data[0] == '#') { //"#" is string; '#' is char; data is string; data[0] is char; must compare same type
			data = data.substr(1); //remove first element
			return nullptr;
		}
		TreeNode* root = new TreeNode(data[0] - '0'); //convert char to int, cant use stoi, since data[i] is char
		data = data.substr(1);
		root->left = deshelp(data);
		root->right = deshelp(data);
		return root;
	}
};