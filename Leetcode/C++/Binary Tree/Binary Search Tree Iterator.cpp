//Method1 save the whole inorder traverse in list
class BSTIterator {
private:
	vector<int> inorder; //global class vector
	int index; //global class int
public:
	BSTIterator(TreeNode *root) { //initialization 
		if (root == NULL) return;
		this->index = 0;  //any difference with or without "this->" ??
		inordertra(root, inorder);
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		++index;
		if ((index - 1) < inorder.size()) return true; //0 is the first element, must "index-1" to go back to the first element;note don't overflow
		else return false;
	}

	/** @return the next smallest number */
	int next() {
		if ((index - 1)<inorder.size()) return inorder[index - 1];
		else return NULL;
	}

	void inordertra(TreeNode* root, vector<int> &inorder) {//void function, change vector "inorder" online
		if (root == NULL) return;
		inordertra(root->left, inorder);
		inorder.push_back(root->val);
		inordertra(root->right, inorder);
	}
};