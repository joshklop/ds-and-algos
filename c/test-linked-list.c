#include <stdio.h>
#include "linked-list.h"
#include "munit.h"

static void *setup_empty_list(const MunitParameter params[], void *user_data);
static void teardown_list(void *fixture);
static void *setup_three_node_list(const MunitParameter key_values[], void *user_data);
MunitResult test_list_initialization(const MunitParameter params[], void *fixture);
MunitResult test_insert_null(const MunitParameter params[], void *fixture);
MunitResult test_insert_into_empty_list(const MunitParameter params[], void *fixture);
MunitResult test_insert_into_nonempty_list(const MunitParameter params[], void *fixture);
MunitResult test_delete_null(const MunitParameter params[], void *fixture);
MunitResult test_delete_from_empty_list(const MunitParameter params[], void *fixture);
MunitResult test_delete_first_element(const MunitParameter params[], void *fixture);
MunitResult test_delete_last_element(const MunitParameter params[], void *fixture);
MunitResult test_delete_nonexistant(const MunitParameter params[], void *fixture);
MunitResult test_search_null(const MunitParameter params[], void *fixture);
MunitResult test_search_empty_list(const MunitParameter params[], void *fixture);
MunitResult test_search_nonempty(const MunitParameter params[], void *fixture);
MunitResult test_search_nonexistant(const MunitParameter params[], void *fixture);
MunitResult test_pred_null(const MunitParameter params[], void *fixture);
MunitResult test_pred_empty(const MunitParameter params[], void *fixture);
MunitResult test_pred_first_key(const MunitParameter params[], void *fixture);
MunitResult test_pred_nonempty(const MunitParameter params[], void *fixture);
MunitResult test_pred_nonexistant_key(const MunitParameter params[], void *fixture);
MunitResult test_succ_null(const MunitParameter params[], void *fixture);
MunitResult test_succ_empty(const MunitParameter params[], void *fixture);
MunitResult test_succ_last_key(const MunitParameter params[], void *fixture);
MunitResult test_succ_nonempty(const MunitParameter params[], void *fixture);
MunitResult test_succ_nonexistant_key(const MunitParameter params[], void *fixture);

int main(int argc, char *argv[]) {
    MunitTest tests[] = {
        { 
            "/initialization", /* name */
            test_list_initialization, /* test */
            NULL, /* setup */
            NULL, /* teardown */
            MUNIT_TEST_OPTION_NONE, /* options */
            NULL /* parameters */
        },
        {
            "/insert-null",
            test_insert_null,
            NULL,
            NULL,
            MUNIT_TEST_OPTION_NONE,
            NULL
        },
        {
            "/insert-into-empty-list",
            test_insert_into_empty_list,
            setup_empty_list,
            teardown_list,
            MUNIT_TEST_OPTION_NONE,
            NULL
        },
        {
            "/insert-into-nonempty-list",
            test_insert_into_empty_list,
            setup_three_node_list,
            teardown_list,
            MUNIT_TEST_OPTION_NONE,
            NULL
        },
        {
            "/list-delete-null",
            test_delete_null,
            NULL,
            NULL,
            MUNIT_TEST_OPTION_NONE,
            NULL
        },
        {
            "/delete-from-empty-list",
            test_delete_from_empty_list,
            setup_empty_list,
            teardown_list,
            MUNIT_TEST_OPTION_NONE,
            NULL
        },
        {
            "/delete-first-element",
            test_delete_first_element,
            setup_three_node_list,
            teardown_list,
            MUNIT_TEST_OPTION_NONE,
            NULL
        },
        {
            "/delete-last-element",
            test_delete_last_element,
            setup_three_node_list,
            teardown_list,
            MUNIT_TEST_OPTION_NONE,
            NULL
        },
        {
            "/delete-nonexistant",
            test_delete_nonexistant,
            setup_three_node_list,
            teardown_list,
            MUNIT_TEST_OPTION_NONE,
            NULL
        },
        {
            "/search-null",
            test_search_null,
            NULL,
            NULL,
            MUNIT_TEST_OPTION_NONE,
            NULL
        },
        {
            "/search-empty-list",
            test_search_empty_list,
            setup_empty_list,
            teardown_list,
            MUNIT_TEST_OPTION_NONE,
            NULL
        },
        {
            "/search-nonempty",
            test_search_nonempty,
            setup_three_node_list,
            teardown_list,
            MUNIT_TEST_OPTION_NONE,
            NULL
        },
        {
            "/search-for-nonexistant-key",
            test_search_nonexistant,
            setup_three_node_list,
            teardown_list,
            MUNIT_TEST_OPTION_NONE,
            NULL
        },
        {
            "/pred-null",
            test_pred_null,
            NULL,
            NULL,
            MUNIT_TEST_OPTION_NONE,
            NULL
        },
        {
            "/pred-empty",
            test_pred_empty,
            setup_empty_list,
            teardown_list,
            MUNIT_TEST_OPTION_NONE,
            NULL
        },
        {
            "/pred-first-key",
            test_pred_first_key,
            setup_three_node_list,
            teardown_list,
            MUNIT_TEST_OPTION_NONE,
            NULL
        },
        {
            "/pred-nonempty",
            test_pred_nonempty,
            setup_three_node_list,
            teardown_list,
            MUNIT_TEST_OPTION_NONE,
            NULL
        },
        {
            "/pred-nonexistant",
            test_pred_nonexistant_key,
            setup_three_node_list,
            teardown_list,
            MUNIT_TEST_OPTION_NONE,
            NULL
        },
        {
            "/succ-null",
            test_succ_null,
            NULL,
            NULL,
            MUNIT_TEST_OPTION_NONE,
            NULL
        },
        {
            "/succ-empty",
            test_succ_empty,
            setup_empty_list,
            teardown_list,
            MUNIT_TEST_OPTION_NONE,
            NULL
        },
        {
            "/succ-last-key",
            test_succ_last_key,
            setup_three_node_list,
            teardown_list,
            MUNIT_TEST_OPTION_NONE,
            NULL
        },
        {
            "/succ-nonempty",
            test_succ_nonempty,
            setup_three_node_list,
            teardown_list,
            MUNIT_TEST_OPTION_NONE,
            NULL
        },
        { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
    };
    const MunitSuite suite = {
        "/list", /* name */
        tests, /* tests */
        NULL, /* suites */
        1, /* iterations */
        MUNIT_SUITE_OPTION_NONE /* options */
    };
    int key_values[3] = {0, 1, 2};
    return munit_suite_main(&suite, key_values, argc, argv);
}

static void *setup_empty_list(const MunitParameter params[], void *user_data) {
    struct List *l = new_list();
    return l;
}

static void teardown_list(void *list) {
    freelist(list);
}

static void *setup_three_node_list(const MunitParameter params[], void *user_data) {
    struct Node *node3 = malloc(sizeof(struct Node));
    struct Node *node2 = malloc(sizeof(struct Node));
    struct Node *node1 = malloc(sizeof(struct Node));
    int *key_values = (int *) user_data;
    node1->key = key_values[0], node2->key = key_values[1], node3->key = key_values[2];
    node1->next = node2, node2->next = node3, node3->next = NULL;
    struct List *l = malloc(sizeof(struct List));
    l->head = node1;
    return l;
}

MunitResult test_list_initialization(const MunitParameter params[], void *fixture) {
    struct List *l = new_list();
    munit_assert_ptr_equal(l->head, NULL);
    freelist(l);
    return MUNIT_OK;
}

MunitResult test_insert_null(const MunitParameter params[], void *fixture) {
    munit_assert_ptr_null(insert(NULL, 0));
    return MUNIT_OK;
}

MunitResult test_insert_into_empty_list(const MunitParameter params[], void *fixture) {
    struct List *three_node_list = (struct List *) fixture;
    int key = 0;
    struct Node *n = insert(three_node_list, key);
    munit_assert_int(three_node_list->head->key, ==, key);
    munit_assert_ptr_equal(three_node_list->head->next, n->next);
    return MUNIT_OK;
}

MunitResult test_insert_into_nonempty_list(const MunitParameter params[], void *fixture) {
    struct List *three_node_list = (struct List *) fixture;
    struct Node *n = insert(three_node_list, 0);
    munit_assert_ptr_not_null(n);
    munit_assert_ptr_equal(three_node_list->head, n);
    munit_assert_ptr_equal(three_node_list->head->next, n->next);
    return MUNIT_OK;
}

MunitResult test_delete_null(const MunitParameter params[], void *fixture) {
    munit_assert_ptr_null(delete_list(NULL, 0));
    return MUNIT_OK;
}

MunitResult test_delete_from_empty_list(const MunitParameter params[], void *fixture) {
    munit_assert_ptr_null(delete_list((struct List *)fixture, 0));
    return MUNIT_OK;
}

MunitResult test_delete_first_element(const MunitParameter params[], void *fixture) {
    struct List *three_node_list = (struct List *) fixture;
    struct Node *n = delete_list(three_node_list, 0);
    munit_assert_ptr_equal(three_node_list->head, n);
    munit_assert_int(n->key, ==, 1);
    return MUNIT_OK;
}

MunitResult test_delete_last_element(const MunitParameter params[], void *fixture) {
    struct List *three_node_list = (struct List *) fixture;
    struct Node *n = delete_list(three_node_list, 2);
    munit_assert_ptr_equal(three_node_list->head->next, n);
    munit_assert_int(n->key, ==, 1);
    return MUNIT_OK;
}

MunitResult test_delete_nonexistant(const MunitParameter params[], void *fixture) {
    struct List *three_node_list = (struct List *) fixture;
    munit_assert_ptr_null(delete_list(three_node_list, -1));
    return MUNIT_OK;
}

MunitResult test_search_null(const MunitParameter params[], void *fixture) {
    munit_assert_ptr_null(search(NULL, 0));
    return MUNIT_OK;
}

MunitResult test_search_empty_list(const MunitParameter params[], void *fixture) {
    munit_assert_ptr_null(search((struct List *) fixture, 0));
    return MUNIT_OK;
}

MunitResult test_search_nonempty(const MunitParameter params[], void *fixture) {
    struct List *three_node_list = (struct List *) fixture;
    int key = munit_rand_int_range(0, 2);
    struct Node *n = search(three_node_list, key);
    munit_assert_ptr_not_null(n);
    munit_assert_int(n->key, ==, key);
    return MUNIT_OK;
}

MunitResult test_search_nonexistant(const MunitParameter params[], void *fixture) {
    struct List *three_node_list = (struct List *) fixture;
    int key = -1;
    struct Node *n = search(three_node_list, key);
    munit_assert_ptr_null(n);
    return MUNIT_OK;
}

MunitResult test_pred_null(const MunitParameter params[], void *fixture) {
    munit_assert_ptr_null(pred(NULL, 0));
    return MUNIT_OK;
}

MunitResult test_pred_empty(const MunitParameter params[], void *fixture) {
    munit_assert_ptr_null(pred((struct List *) fixture, 1));
    return MUNIT_OK;
}

MunitResult test_pred_first_key(const MunitParameter params[], void *fixture) {
    struct List *three_node_list = (struct List *) fixture;
    int key = 0;
    struct Node *n = pred(three_node_list, key);
    munit_assert_ptr_null(n);
    return MUNIT_OK;
}

MunitResult test_pred_nonempty(const MunitParameter params[], void *fixture) {
    struct List *three_node_list = (struct List *) fixture;
    int key = munit_rand_int_range(1, 2);
    struct Node *n = pred(three_node_list, key);
    munit_assert_ptr_not_null(n);
    munit_assert_int(n->key, ==, key-1);
    return MUNIT_OK;
}

MunitResult test_pred_nonexistant_key(const MunitParameter params[], void *fixture) {
    struct List *three_node_list = (struct List *) fixture;
    int key = -1;
    struct Node *n = pred(three_node_list, key);
    munit_assert_ptr_null(n);
    return MUNIT_OK;
}

MunitResult test_succ_null(const MunitParameter params[], void *fixture) {
    munit_assert_ptr_null(succ(NULL, 0));
    return MUNIT_OK;
}

MunitResult test_succ_empty(const MunitParameter params[], void *fixture) {
    munit_assert_ptr_null(succ((struct List *) fixture, 0));
    return MUNIT_OK;
}

MunitResult test_succ_last_key(const MunitParameter params[], void *fixture) {
    struct List *three_node_list = (struct List *) fixture;
    int key = 2;
    struct Node *n = succ(three_node_list, key);
    munit_assert_ptr_null(n);
    return MUNIT_OK;
}

MunitResult test_succ_nonempty(const MunitParameter params[], void *fixture) {
    struct List *three_node_list = (struct List *) fixture;
    int key = munit_rand_int_range(0, 1);
    struct Node *n = succ(three_node_list, key);
    munit_assert_ptr_not_null(n);
    munit_assert_int(n->key, ==, key+1);
    return MUNIT_OK;
}

MunitResult test_succ_nonexistant_key(const MunitParameter params[], void *fixture) {
    struct List *three_node_list = (struct List *) fixture;
    int key = -1;
    struct Node *n = succ(three_node_list, key);
    munit_assert_ptr_null(n);
    return MUNIT_OK;
}
