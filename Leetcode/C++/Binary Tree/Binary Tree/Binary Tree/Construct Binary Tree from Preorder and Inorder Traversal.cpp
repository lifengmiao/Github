//Method1 memeory limitation 
class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.size() == 0) return NULL;
		TreeNode *root = new TreeNode(preorder[0]);
		vector<int>::iterator it = inorder.begin();
		int index = 0;
		while (it < inorder.end() && *it != preorder[0]) { ++index; ++it; }
		//while(index<inorder.size() && inorder[index]!=preorder[0]) {++index;} //also works
		vector<int> inorder_new_left(inorder.begin(), inorder.begin() + index); //create new vector, so memory limited
		vector<int> inorder_new_right(inorder.begin() + index + 1, inorder.end());
		vector<int> preorder_new_left(preorder.begin() + 1, preorder.begin() + 1 + index);
		vector<int> preorder_new_right(preorder.begin() + 1 + index, preorder.end());
		root->left = buildTree(preorder_new_left, inorder_new_left);
		root->right = buildTree(preorder_new_right, inorder_new_right);
		return root;
	}
};

//Method2 use iterator
class Solution {
public:
	typedef vector<int>::iterator Iter;
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		return buildTreeRecur(inorder.begin(), inorder.end(), preorder.begin(), preorder.end());
	}
	TreeNode *buildTreeRecur(Iter istart, Iter iend, Iter pstart, Iter pend)
	{
		if (istart == iend)return NULL;
		int rootval = *pstart;
		Iter iterroot = find(istart, iend, rootval);
		TreeNode *res = new TreeNode(rootval);
		res->left = buildTreeRecur(istart, iterroot, pstart + 1, pstart + 1 + (iterroot - istart)); //can't trate iterroot as index
		//res->left = buildTreeRecur(istart, istart+iterroot, pstart + 1, pstart + 1 + iterroot); //this is not correct
		res->right = buildTreeRecur(iterroot + 1, iend, pstart + 1 + (iterroot - istart), pend);
		return res;
	}
};

//Method3 use index
class Solution {
public:
	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		if (inorder.size() != postorder.size()) return NULL;
		int n = inorder.size();
		return buildBT(inorder, postorder, 0, n - 1, 0, n - 1);
	}

	TreeNode *buildBT(vector<int> &inorder, vector<int> &postorder, int s1, int e1, int s2, int e2) {
		if (s1>e1 || s2>e2) return NULL;
		TreeNode *root = new TreeNode(postorder[e2]);
		int rootIndex = -1;
		for (int i = s1; i <= e1; i++) {
			if (inorder[i] == root->val) {
				rootIndex = i;
				break;
			}
		}
		if (rootIndex == -1) return NULL;
		int leftTreeSize = rootIndex - s1;
		int rightTreeSize = e1 - rootIndex;

		root->left = buildBT(inorder, postorder, s1, rootIndex - 1, s2, s2 + leftTreeSize - 1);
		root->right = buildBT(inorder, postorder, rootIndex + 1, e1, e2 - rightTreeSize, e2 - 1);
		return root;
	}
};

class Solution {
public:
	typedef vector<int>::iterator Itr;
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		return buildTreeHelp(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
	}
	TreeNode *buildTreeHelp(Itr is, Itr ie, Itr ps, Itr pe) {
		if (is == ie) return NULL;
		int root_val = *(pe - 1); //vector.end() point to NULL, vector.end()-1 point to the last element
		TreeNode *root = new TreeNode(root_val);
		Itr index = find(is, ie, root_val);
		root->left = buildTreeHelp(is, index, ps, ps + (index - is));
		root->right = buildTreeHelp(index + 1, ie, ps + (index - is), pe - 1);
		return root;

	}
};