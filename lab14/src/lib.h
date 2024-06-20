/**
 * @file lib.h
 * @brief Заголовковий файл з визначенням функцій.
 */


#ifndef LIB_H

#define LIB_H

#include <stdio.h>

#include <stdlib.h>

#include <string.h>




typedef enum {


STANDARD_8 = 0,

LATER_830,

SECOND_SHIFT_1430
} StartTime;



typedef struct {


char surname[100];

char name[100];

char email[100];
} Head;

typedef struct {


int isFreeEducation;

char name[100];

int totalStudents;

Head head;

StartTime startTime;
} EducationalInstitution;



/**
 * @brief Функція для зчитування даних про навчальні заклади з файлу у пам'ять.
 *
 * @param institutions Вказівник на масив структур EducationalInstitution.
 * @param size Вказівник на розмір масиву institutions.
 * @param filename Ім'я вхідного файлу для зчитування даних.
 */

void readDataFromFile(EducationalInstitution **institutions, int *size, const char *filename);


/**
 * @brief Функція для запису даних про навчальні заклади з пам'яті у файл.
 *
 * @param institutions Вказівник на масив структур EducationalInstitution.
 * @param size Розмір масиву institutions.
 * @param filename Ім'я вихідного файлу для запису даних.
 */

void writeDataToFile(EducationalInstitution *institutions, int size, const char *filename);

/**
 * @brief Функція для виведення даних про навчальні заклади на стандартний вивід.
 *
 * @param institutions Вказівник на масив структур EducationalInstitution.
 * @param size Розмір масиву institutions.
 */
 
void printData(EducationalInstitution *institutions, int size);


/**
 * @brief Функція для сортування навчальних закладів за загальною кількістю студентів у порядку зростання.
 *
 * @param institutions Вказівник на масив структур EducationalInstitution.
 * @param size Розмір масиву institutions.
 */
void sortDataByTotalStudents(EducationalInstitution *institutions, int size);

/**
 * @brief Функція для пошуку навчального закладу з найбільшою кількістю студентів.
 *
 * @param institutions Вказівник на масив структур EducationalInstitution.
 * @param size Розмір масиву institutions.
 * @return Вказівник на EducationalInstitution з найбільшою кількістю студентів, або NULL, якщо size <= 0.
 */
 
EducationalInstitution* findInstitutionWithMaxStudents(EducationalInstitution *institutions, int size);

#endif // LIB_H
