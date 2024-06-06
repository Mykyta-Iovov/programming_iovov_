#include <check.h>

#include "lib.h"

/**

 * @file test.c

 *

 *

*/

START_TEST(test_binomialCoeff)
{

    ck_assert_int_eq(binomialCoeff(0, 0), 1);

    ck_assert_int_eq(binomialCoeff(1, 0), 1);

    ck_assert_int_eq(binomialCoeff(1, 1), 1);

    ck_assert_int_eq(binomialCoeff(2, 1), 2);

    ck_assert_int_eq(binomialCoeff(3, 1), 3);

    ck_assert_int_eq(binomialCoeff(4, 2), 6);

    ck_assert_int_eq(binomialCoeff(5, 2), 10);
}

START_TEST(test_printPascalRecursive)
{

    // Перенаправити стандартний вивід до тимчасового файлу

    freopen("temp.txt", "w", stdout);

    printPascalRecursive(5);

    fclose(stdout);

    // Відкриття тимчасового файлу та перевірка його вмісту

    FILE *fp = fopen("temp.txt", "r");

    char buffer[1024];

    int lines = 0;

    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {

        lines++;
    }

    fclose(fp);

    // Перевірка кількості рядків, які виведено

    ck_assert_int_eq(lines, 5);
}

START_TEST(test_printPascalIterative)
{

    // Перенаправити stdout до тимчасового файлу

    freopen("temp.txt", "w", stdout);

    // Виклик функції

    printPascalIterative(5);

    // Відновлення stdout

    fclose(stdout);

    // Відкриття тимчасового файлу та перевірка його вмісту

    FILE *fp = fopen("temp.txt", "r");

    char buffer[1024];

    int lines = 0;

    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {

        lines++;
    }

    fclose(fp);

    // Перевірка кількості рядків, які виведено

    ck_assert_int_eq(lines, 5);
}

Suite *lib_suite(void)
{

    Suite *s;

    TCase *tc_core;

    s = suite_create("Lib");

    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_binomialCoeff);

    tcase_add_test(tc_core, test_printPascalRecursive);

    tcase_add_test(tc_core, test_printPascalIterative);

    suite_add_tcase(s, tc_core);

    return s;
}

int main(void)
{

    int number_failed;

    Suite *s;

    SRunner *sr;

    s = lib_suite();

    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);

    number_failed = srunner_ntests_failed(sr);

    srunner_free(sr);

    return (number_failed == 0) ? 0 : 1;
}

