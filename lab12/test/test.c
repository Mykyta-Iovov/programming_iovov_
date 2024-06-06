
#include <check.h>
#include <assert.h>
#include "lib.h"




/**
 * @brief Тестовий випадок для функції calculate_frequency.
 * 
 * Цей тестовий випадок перевіряє правильність функції calculate_frequency шляхом
 * порівняння розрахованих частот та загальної кількості символів з очікуваними значеннями.
 */
 
 
START_TEST(test_calculate_frequency) {
    char buffer[] = "hello world";
    int char_count[ASCII_SIZE] = {0};
    int total_chars = 0;

    calculate_frequency(buffer, char_count, &total_chars);

    ck_assert_int_eq(char_count['h'], 1);
    ck_assert_int_eq(char_count['e'], 1);
    ck_assert_int_eq(char_count['l'], 3);
    ck_assert_int_eq(char_count['o'], 2);
    ck_assert_int_eq(char_count[' '], 1);
    ck_assert_int_eq(char_count['w'], 1);
    ck_assert_int_eq(char_count['r'], 1);
    ck_assert_int_eq(char_count['d'], 1);
    ck_assert_int_eq(total_chars, 11);
}
END_TEST



/**
 * @brief Створює тестовий набір для функцій роботи з частотою.
 * 
 * Ця функція створює і повертає тестовий набір для функцій роботи з частотою.
 * 
 * @return Suite* Вказівник на створений тестовий набір.
 */
 
Suite * frequency_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("Frequency");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_calculate_frequency);
    suite_add_tcase(s, tc_core);

    return s;
}


/**
 * @brief Основна функція для запуску тестового набору.
 * 
 * Ця функція запускає створений тестовий набір і повертає результат.
 * 
 * @return int Повертає 0, якщо всі тести пройшли успішно, 1, якщо будь-який тест провалився.
 */
 
 
 
int main(void) {
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = frequency_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? 0 : 1;
}


