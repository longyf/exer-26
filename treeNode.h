#ifndef TREE_NODE_H
#define TREE_NODE_H
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
#endif
