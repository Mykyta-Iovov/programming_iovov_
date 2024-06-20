/**
 * @file main.c
 * @brief Головний файл програми.
 */

#include "lib.h"


/**
 * @brief Основна функція, яка зчитує, обробляє, сортує та записує дані навчальних закладів.
 *
 * @param argc Кількість аргументів командного рядка.
 * @param argv Масив рядків аргументів командного рядка.
 * @return 0 у разі успішного виконання, 1 у випадку помилки (некоректне використання або операції з файлами).
 */  
 
int main(int argc, char *argv[]) {


if (argc != 3) {

    fprintf(stderr, "Usage: %s <input_file>\n", *(argv + 0));

    return 1;

}



const char *filename = *(argv + 1);

EducationalInstitution *institutions = NULL;

int size = 0;



readDataFromFile(&institutions, &size, filename);

if (institutions == NULL) {

    return 1;

}



printf("Загальна інформація:\n");

printData(institutions, size);



sortDataByTotalStudents(institutions, size);

printf("\nВідсортовані дані:\n");

printData(institutions, size);



EducationalInstitution *maxInstitution = findInstitutionWithMaxStudents(institutions, size);

if (maxInstitution != NULL) {

    printf("\nНавчальний заклад з максимальною кількістю учнів:\n");

    printData(maxInstitution, 1);

}



writeDataToFile(institutions, size, *(argv + 2));



free(institutions);



return 0;
}
