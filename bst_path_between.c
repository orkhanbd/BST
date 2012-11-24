#include <stdio.h>
#include <stdlib.h>
#include "bst_path_between.h"

BST** path_between(BST* root, BST* sNode, BST* fNode) {
	BST **sNodeArray, **fNodeArray, **outputArray;
	int i, j, k, l, sNodeArraySize, fNodeArraySize, outputSize;
	BST *tmp, *commonAncestor;
		
	sNodeArraySize = 10;
	fNodeArraySize = 10;
	sNodeArray = (BST **) calloc(sNodeArraySize, sizeof(BST*));
	fNodeArray = (BST **) calloc(fNodeArraySize, sizeof(BST*));

	if(sNodeArray == NULL) {
		//these kind of errors should be handled too
	}

	tmp = sNode;
	for(i = 0;tmp != NULL;i++) {
		if(i == sNodeArraySize-1){	
			sNodeArraySize = sNodeArraySize * 2;
			sNodeArray = (BST **) realloc(sNodeArray, sNodeArraySize);
		}	

		sNodeArray[i] = tmp;
		tmp = tmp->parent;
	}
	sNodeArraySize = i;

	tmp = fNode;
	for(j = 0;tmp != NULL;j++) {
		if(j == fNodeArraySize-1) {	
			fNodeArraySize = fNodeArraySize * 2;
			fNodeArray = (BST **) realloc(fNodeArray, fNodeArraySize);
		}	
		
		fNodeArray[j] = tmp;
		tmp = tmp->parent;
	}
	fNodeArraySize = j;

	for(i = sNodeArraySize-1, j = fNodeArraySize-1;sNodeArray[i] == fNodeArray[j];i--, j--){
		commonAncestor = sNodeArray[i];
	}

	outputSize = sNodeArraySize + fNodeArraySize;									//included +1 is needed to insert NULL at the end
	outputArray = (BST **) calloc(outputSize, sizeof(BST*));
	outputArray[outputSize-1] = NULL;

	for(k = 0;k <= i;k++) {
		outputArray[k] = sNodeArray[k];	
	}

	outputArray[i+1] = commonAncestor;

	for(l = 0;l <= j;l++) {
		outputArray[outputSize-2-l] = fNodeArray[l];
	}

	return outputArray;
}
