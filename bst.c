#include <stdio.h>

void nonRecursiveInorderWalk(BTS* root){
	BST* x = TREE-MINIMUM(root);

	while(x != NULL){
		printf("%d", x->value);
		x = TREE-SUCCESSOR(x);
	}
}

void NthElement(BTS* root, int n){
	BST* x = TREE-MINIMUM(root);

	while(x != NULL){
		x = TREE-SUCCESSOR(x);
		n--;
		if(n == 0){
			printf("%d", x->value);
			break;
		}
	}
}

void printLevel(BST* root, int h){
	if(h == 0){
		printf("%d", root->value);
	}
	else{
		if(root->left != NULL){
			printLevel(root->left, h-1);
		}
		if(root->right != NULL){
			printLevel(root->right, h-1);
		}
	}
}
