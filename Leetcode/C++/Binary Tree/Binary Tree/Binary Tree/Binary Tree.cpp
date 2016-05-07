// Binary Tree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include "stdio.h"
#include <iostream>
#include <string>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isValidSerialization(string preorder) {
		if (preorder.length() == 0) return false;
		int d = 0;
		int a;
		for (int i = 0; i<preorder.length() - 1; ++i) {
			if (preorder[i] == '#') {
				if (d == 0) return false;
				else --d;
			}
			else {
				a = preorder[i] - '0';
				if (a>=0 && a <= 9) 
					++d;
			}
		}
		return d != 0 ? false : preorder.back() == '#';
	}
};


int main()
{
	TreeNode *root = new TreeNode(2);
	root->left = new TreeNode(1);
	root->right = new TreeNode(3);
	root->right->left = new TreeNode(4);
	//vector<vector<int>> res; //0 length vector {}
	//TreeNode *root;
	//vector<int> preorder{ 4,3,1,8,6,9 };
	//vector<int> inorder{ 1,3,4,6,8,9 };
	//vector<int> nums{ 0 };
	string s = "92,3,4,#,#,1,#,#,2,#,6,#,#";
	Solution sol;
	bool res = sol.isValidSerialization(s);
	//BSTIterator i = BSTIterator(root);
	//while (i.hasNext()) cout << i.next() << '\n';
	//Codec codec;
	//string res = codec.serialize(root);
	//TreeNode* build_tree = codec.deserialize(res);
    return 0;
}

