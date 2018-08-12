#include <iostream>
#include "treeNode.h"
#include "HasSubtree.h"

using namespace std;

void test1() {
	TreeNode *pNode1 = new TreeNode(8);
	TreeNode *pNode2 = new TreeNode(8);
	TreeNode *pNode3 = new TreeNode(7);
	TreeNode *pNode4 = new TreeNode(9);
	TreeNode *pNode5 = new TreeNode(2);
	TreeNode *pNode6 = new TreeNode(4);
	TreeNode *pNode7 = new TreeNode(7);

	TreeNode *pNode8 = new TreeNode(8);
	TreeNode *pNode9 = new TreeNode(9);
	TreeNode *pNode10 = new TreeNode(2);

	pNode1->left = pNode2;
	pNode1->right = pNode3;
	pNode2->left = pNode4;
	pNode2->right = pNode5;
	pNode5->left = pNode6;
	pNode5->right = pNode7;

	pNode8->left = pNode9;
	pNode8->right = pNode10;

	if (HasSubtree(pNode1, pNode8)) {
		cout<<"Yes."<<endl;
	}
	else {
		cout<<"No."<<endl;
	}
}

int main() {
	test1();
	return 0;
}
