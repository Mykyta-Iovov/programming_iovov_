#include "../src/lib.h"
#include <check.h>


//Тест на базову кiлькiсть слiв
START_TEST(test_count_of_words_basic)
{
    char *text = "Hello, world!";
    ck_assert_int_eq(count_of_words(text), 2);
}
END_TEST

START_TEST(test_count_of_words_with_special_chars)
{
    char *text = "Hello, world! How are you?";// Вхідний рядок зі спецсимволами
    ck_assert_int_eq(count_of_words(text), 5);// Перевірка на 5 слів
}
END_TEST

// Тест на відсутність слів
START_TEST(test_count_of_words_with_no_words)
{
    char *text = "     ";
    ck_assert_int_eq(count_of_words(text), 0);
}
END_TEST



// Функція створення тестового набору

Suite *words_suite(void)
{
    Suite *s; // Вказівник на тестовий набір
    TCase *tc_core;

    s = suite_create("WordsCount");
    
// Створення тестового випадку "Core"
    tc_core = tcase_create("Core");
    
    // Додавання тестів до тестового випадку
    tcase_add_test(tc_core, test_count_of_words_basic);
    tcase_add_test(tc_core, test_count_of_words_with_special_chars);
    tcase_add_test(tc_core, test_count_of_words_with_no_words);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void)
{
    int number_failed;
    Suite *s;
    SRunner *sr; // Вказівник на запускач тестів

    s = words_suite(); // Ініціалізація тестового набору
    sr = srunner_create(s);  // Створення запускача для тестового набору

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);// Звільнення ресурсів запускача тестів

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

