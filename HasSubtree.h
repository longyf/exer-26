#ifndef HAS_SUB_TREE_H
#define HAS_SUB_TREE_H
#include <iostream>
#include "treeNode.h"
using namespace std;

void searchRoot(TreeNode *pNode1, TreeNode *pRoot2, TreeNode **pRoot2InTree1) {
	if (pNode1 != nullptr) {
		if (pNode1->val == pRoot2->val) {
			*pRoot2InTree1 = pNode1;
			return;
		}

		searchRoot(pNode1->left, pRoot2, pRoot2InTree1);
		searchRoot(pNode1->right, pRoot2, pRoot2InTree1);
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

	TreeNode *pTemp = nullptr;
	TreeNode **pRoot2InTree1 = &pTemp;
	searchRoot(pRoot1, pRoot2, pRoot2InTree1);//在tree1中寻找pRoot2，将指针存入*pRoot2InTree1。
	if (*pRoot2InTree1 == nullptr) return false;
	bool isMatched = true;
	preOrder(*pRoot2InTree1, pRoot2, isMatched);

	if (isMatched) return true;
	else return false;
}
#endif
