#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

BST *create_bst_element(int value) {
	BST* tmp;
	
	tmp = (BST *) malloc(sizeof(BST));
	tmp->value = value;

	tmp->parent = NULL;
	tmp->left = NULL;
	tmp->right = NULL;

	return tmp;
}
