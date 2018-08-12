#ifndef HAS_SUB_TREE_H
#define HAS_SUB_TREE_H
#include <iostream>
#include "treeNode.h"
using namespace std;

void preOrder(TreeNode *pNode1, TreeNode *pNode2, bool &isMatched);

void searchRoot(TreeNode *pNode1, TreeNode *pRoot2, bool &isFounded) {
	if (pRoot2 == nullptr) return;
	if (pNode1 != nullptr) {
		if (pNode1->val == pRoot2->val) {
			//pNode1和pRoot2匹配
			bool isMatched = true;
			preOrder(pNode1, pRoot2, isMatched);
			if (isMatched == true) {
				isFounded = true;
				return;
			}
		}

		searchRoot(pNode1->left, pRoot2, isFounded);
		searchRoot(pNode1->right, pRoot2, isFounded);
	}
}

void preOrder(TreeNode *pNode1, TreeNode *pNode2, bool &isMatched) {
	if (pNode2 != nullptr) {
		//节点不匹配。
		if (pNode1 == nullptr || pNode1->val != pNode2->val) {
			isMatched = false;
			return;
		}

		preOrder(pNode1->left, pNode2->left, isMatched);
		preOrder(pNode1->right, pNode2->right, isMatched);
	}
}

bool HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2) {
	if (pRoot1 == nullptr || pRoot2 == nullptr)
		return false;
	
	bool isFounded = false;
	searchRoot(pRoot1, pRoot2, isFounded);
	return isFounded;
}
#endif
