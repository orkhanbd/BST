#ifndef BST_H
#define BST_H

typedef struct BST {
	int value;
	struct BST *parent;
	struct BST *left;
	struct BST *right;
}BST;

// this function creates a BST element and returns the pointer to it
BST *create_bst_element(int value);

#endif
