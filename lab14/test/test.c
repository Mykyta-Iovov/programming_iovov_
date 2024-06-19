#include <check.h>
#include <stdio.h>
#include "../src/lib.h"

// Прототип функції для підготовки тестових даних
void prepareTestData(const char *filename);

START_TEST(test_readDataFromFile) {
    EducationalInstitution *institutions = NULL;
    int size = 0;

    // Підготовка тестових даних перед читанням
    prepareTestData("./test/test_data.txt");

    const char *filename = "./test/test_data.txt";  // Використання підготовлених тестових даних

    readDataFromFile(&institutions, &size, filename);

    ck_assert_ptr_nonnull(institutions);
    ck_assert_int_eq(size, 2);

    // Перевірки на основі тестових даних
    ck_assert_int_eq(institutions[0].isFreeEducation, 1);
    ck_assert_str_eq(institutions[0].name, "Берізка");
    ck_assert_int_eq(institutions[0].totalStudents, 250);
    ck_assert_str_eq(institutions[0].head.surname, "Іванов");
    ck_assert_str_eq(institutions[0].head.name, "Іван");
    ck_assert_str_eq(institutions[0].head.email, "ivanov@example.com");
    ck_assert_int_eq(institutions[0].startTime, STANDARD_8);

    free(institutions);
}

END_TEST

Suite *educational_institution_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("EducationalInstitution");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_readDataFromFile);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void) {
    int number_failed;
    Suite *s;
    SRunner *sr;

    
    prepareTestData("./test/input.txt");

    s = educational_institution_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? 0 : 1;
}



void prepareTestData(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        fprintf(stderr, "Error opening file for writing: %s\n", filename);
        return;
    }

    fprintf(file, "2\n");
    fprintf(file, "1 Берізка 250 Іванов Іван ivanov@example.com 0\n");
    fprintf(file, "0 Дубова 180 Петров Петро petrov@example.com 1\n");

    fclose(file);
}



