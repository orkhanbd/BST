#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include "bst.h"
#include "bst_path_between.h"

BST *root;

START_TEST(test_path_between) {
	// this code tests path_between() function
	// on calculating path between two elements(6 and 12)
	// for the tree below
	//
	//          10               
	//         /  \         
	//        5    15                
	//       / \   / \                        
	//      2   7 12  17    
	//         /
	//        6 	   		
                                       
	BST *el1, *el2;
	BST **path;
	int i;
	int intendedPath[6] = {6, 7, 5, 10, 15, 12};

	root = create_bst_element(10);

	root->left = create_bst_element(5);
	(root->left)->parent = root;

	(root->left)->left = create_bst_element(2);
	((root->left)->left)->parent = root->left;

	(root->left)->right = create_bst_element(7);
	((root->left)->right)->parent = root->left;

	el1 = create_bst_element(6);
	((root->left)->right)->left = el1;
	el1->parent = (root->left)->right;

	root->right = create_bst_element(15);
	(root->right)->parent = root;

	el2 = create_bst_element(12);
	(root->right)->left = el2;
	el2->parent = root->right;

	(root->right)->right = create_bst_element(17);
	((root->right)->right)->parent = root->right;

	path = path_between(root, el1, el2);
	
	for(i = 0;path[i] != NULL;i++) {
		fail_unless(path[i]->value == intendedPath[i], "Test failed");
	}
	
}
END_TEST

Suite* hash_table_suite(void) {
	Suite *s = suite_create("BST_functions");
	
	TCase *ht_case = tcase_create("BST_case");
	tcase_add_test(ht_case, test_path_between);
	suite_add_tcase(s, ht_case);

	return s;
}

int main(void){
	int fail_num;
	Suite *s = hash_table_suite();
	SRunner *sr = srunner_create(s);
	srunner_run_all(sr, CK_NORMAL);
	fail_num = srunner_ntests_failed(sr);
	srunner_free(sr);

	return (fail_num == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
