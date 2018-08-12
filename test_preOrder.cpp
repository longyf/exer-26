#include <iostream>
#include "treeNode.h"
using namespace std;

void preOrder(TreeNode *pRoot) {
	if (pRoot != nullptr) {
		cout<<pRoot->val<<endl;
		preOrder(pRoot->left);
		preOrder(pRoot->right);
		cout<<"test:"<<endl;
	}
}

int main() {
	TreeNode *p1 = new TreeNode(1);
	TreeNode *p2 = new TreeNode(2);
	TreeNode *p3 = new TreeNode(3);
	p1->left = p2;
	p1->right = p3;
	preOrder(p1);
	return 0;
}
