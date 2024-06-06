#include "../src/lib.h"
#include <assert.h>
#include <check.h>


START_TEST(test_append_basic) {
    int initial_size = 0;
    int *arr = NULL;

    // Перевіряємо додавання одного елемента 
    int element1 = 10;
    arr = append(arr, &initial_size, element1);
    ck_assert_int_eq(initial_size, 1);
    ck_assert_int_eq(arr[0], 10);

    // Перевіряємо додавання ще одного елемента 
    int element2 = 20;
    arr = append(arr, &initial_size, element2);
    ck_assert_int_eq(initial_size, 2);
    ck_assert_int_eq(arr[1], 20);

    // Перевіряємо додавання декiлькох елементів 
    int element3 = 30;
    int element4 = 40;
    arr = append(arr, &initial_size, element3);
    arr = append(arr, &initial_size, element4);
    ck_assert_int_eq(initial_size, 4);
    ck_assert_int_eq(arr[2], 30);
    ck_assert_int_eq(arr[3], 40);

    
    free(arr);
}

Suite *append_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("Append");

    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_append_basic);

    suite_add_tcase(s, tc_core);

    return s;
}

int main(void) {
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = append_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}








