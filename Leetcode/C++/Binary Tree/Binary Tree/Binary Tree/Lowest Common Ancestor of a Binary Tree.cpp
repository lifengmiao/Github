//Method1 mem limited
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		vector<TreeNode*> path;
		vector<TreeNode*> final_path1;
		vector<TreeNode*> final_path2;
		getPath(root, p, path, final_path1);
		getPath(root, q, path, final_path2);
		int i = 0;
		TreeNode* res;
		while (i<final_path1.size() and i<final_path2.size()) {
			if (final_path1[i] != final_path2[i]) break;
			else { res = final_path1[i]; ++i; }
		}
		return res;

	}
	//getPath function
	void getPath(TreeNode* root, TreeNode* node, vector<TreeNode*> path, vector<TreeNode*> &final_path) { //use path instead of &path which
		//copy the vector every recursive step, that may be the reason cause mem limitation
		if (root == NULL) return;
		if (!final_path.empty()) return;
		path.push_back(root);
		if (root == node) {
			final_path = path;
			return;
		}
		getPath(root->left, node, path, final_path);
		getPath(root->right, node, path, final_path);


	}
};
//Revised Method1 change parameter from "path" to "&path", no need to copy vector; pop.back path to remove node before going up
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		vector<TreeNode*> path;
		vector<TreeNode*> final_path1;
		vector<TreeNode*> final_path2;
		getPath(root, p, path, final_path1);
		path.clear(); //clear path for next
		getPath(root, q, path, final_path2);
		int i = 0;
		TreeNode* res;
		while (i<final_path1.size() and i<final_path2.size()) {
			if (final_path1[i] != final_path2[i]) break;
			else { res = final_path1[i]; ++i; }
		}
		return res;

	}
	//getPath function
	void getPath(TreeNode* root, TreeNode* node, vector<TreeNode*> &path, vector<TreeNode*> &final_path) { //use path instead of &path which
																										   //copy the vector every recursive step, that may be the reason cause mem limitation
		if (root == NULL) return;
		if (!final_path.empty()) return;
		path.push_back(root);
		if (root == node) {
			final_path = path;
			return;
		}
		getPath(root->left, node, path, final_path);
		getPath(root->right, node, path, final_path);
		path.pop_back(); //pop.back path to remove node before going up

	}
};
//Method2 from http://www.cnblogs.com/easonliu/p/4643873.html
class Solution {
public:
	void getPath(TreeNode *root, TreeNode *p, TreeNode *q, vector<TreeNode*> &path, vector<TreeNode *> &path1, vector<TreeNode*> &path2) {
		if (root == NULL) return;
		path.push_back(root);
		if (root == p) path1 = path;
		if (root == q) path2 = path;
		//
		if (!path1.empty() && !path2.empty()) return;
		getPath(root->left, p, q, path, path1, path2);
		getPath(root->right, p, q, path, path1, path2);
		path.pop_back();
	}

	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		vector<TreeNode*> path, path1, path2;
		getPath(root, p, q, path, path1, path2);
		TreeNode *res = root;
		int idx = 0;
		while (idx < path1.size() && idx < path2.size()) {
			if (path1[idx] != path2[idx]) break;
			else res = path1[idx++];
		}
		return res;
	}
};