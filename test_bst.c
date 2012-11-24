#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include "bst.h"

BST *root;

START_TEST(test_bst) {
	BST *el1, *el2, *el3;

	root = create_bst_element(5);
	fail_unless(root->value == 5, "test1 failed");

	el1 = create_bst_element(2);
	root->left = el1;
	fail_unless((root->left)->value == 2, "test2 failed");

	el1->right = create_bst_element(4);
	fail_unless((el1->right)->value == 4, "test3 failed");

	el2 = create_bst_element(9);
	root->right = el2;
	fail_unless((root->right)->value == 9, "test4 failed");
}
END_TEST

Suite* hash_table_suite(void) {
	Suite *s = suite_create("BST");
	
	TCase *ht_case = tcase_create("BST_case");
	tcase_add_test(ht_case, test_bst);
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
