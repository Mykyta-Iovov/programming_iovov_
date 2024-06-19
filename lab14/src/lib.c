
/**
 * @file lib.c
 * @brief Реалізація функцій для роботи з файлами і структурами данних.
 */

#include "lib.h"



/**
 * @brief Функція для зчитування даних про навчальні заклади з файлу у пам'ять.
 *
 * @param institutions Вказівник на масив структур EducationalInstitution.
 * @param size Вказівник на розмір масиву institutions.
 * @param filename Ім'я вхідного файлу для зчитування даних.
 */

void readDataFromFile(EducationalInstitution **institutions, int *size, const char *filename) {


FILE *file = fopen(filename, "r");

if (!file) {

    fprintf(stderr, "Error opening file: %s\n", filename);

    return;

}



if (fscanf(file, "%d", size) != 1 || *size <= 0) {

    fprintf(stderr, "Error reading size from file or size is invalid.\n");

    fclose(file);

    return;

}



*institutions = (EducationalInstitution *)malloc((size_t)(*size) * sizeof(EducationalInstitution));

if (!*institutions) {

    fprintf(stderr, "Memory allocation failed.\n");

    fclose(file);

    return;

}



for (int i = 0; i < *size; i++) {

    int startTime;

    if (fscanf(file, "%d %99s %d %99s %99s %99s %d",

               &(*institutions)[i].isFreeEducation, (*institutions)[i].name,

               &(*institutions)[i].totalStudents, (*institutions)[i].head.surname,

               (*institutions)[i].head.name, (*institutions)[i].head.email, &startTime) != 7) {

        fprintf(stderr, "Error reading institution data from file.\n");

        free(*institutions);

        fclose(file);

        return;

    }

    (*institutions)[i].startTime = (StartTime)startTime;

}



fclose(file);
}

/**
 * @brief Функція для запису даних про навчальні заклади з пам'яті у файл.
 *
 * @param institutions Вказівник на масив структур EducationalInstitution.
 * @param size Розмір масиву institutions.
 * @param filename Ім'я вихідного файлу для запису даних.
 */
 
void writeDataToFile(EducationalInstitution *institutions, int size, const char *filename) {



FILE *file = fopen(filename, "w");

if (!file) {

    fprintf(stderr, "Error opening file for writing: %s\n", filename);

    return;

}



fprintf(file, "%d\n", size);

for (int i = 0; i < size; i++) {

    fprintf(file, "%d %s %d %s %s %s %d\n",

            institutions[i].isFreeEducation, institutions[i].name,

            institutions[i].totalStudents, institutions[i].head.surname,

            institutions[i].head.name, institutions[i].head.email, institutions[i].startTime);

}



fclose(file);
}

/**
 * @brief Функція для виведення даних про навчальні заклади на стандартний вивід.
 *
 * @param institutions Вказівник на масив структур EducationalInstitution.
 * @param size Розмір масиву institutions.
 */
 
void printData(EducationalInstitution *institutions, int size) {


for (int i = 0; i < size; i++) {

    printf("Назва: %s, Вільне навчання: %s, Кількість студентів: %d, Голова: %s %s (%s), Початок: ",

           institutions[i].name, 

           institutions[i].isFreeEducation ? "Так" : "Ні",

           institutions[i].totalStudents,

           institutions[i].head.surname, institutions[i].head.name, institutions[i].head.email);



    switch (institutions[i].startTime) {

        case STANDARD_8:

            printf("8:00\n");

            break;

        case LATER_830:

            printf("8:30\n");

            break;

        case SECOND_SHIFT_1430:

            printf("14:30\n");

            break;

        default:

            printf("Unknown\n");

    }

}
}


/**
 * @brief Функція для сортування навчальних закладів за загальною кількістю студентів у порядку зростання.
 *
 * @param institutions Вказівник на масив структур EducationalInstitution.
 * @param size Розмір масиву institutions.
 */
 
void sortDataByTotalStudents(EducationalInstitution *institutions, int size) {


for (int i = 0; i < size - 1; i++) {

    for (int j = 0; j < size - i - 1; j++) {

        if (institutions[j].totalStudents > institutions[j + 1].totalStudents) {

            EducationalInstitution temp = *(institutions + j);

            *(institutions + j) = *(institutions + j + 1);

            *(institutions + j + 1) = temp;

        }

    }

}
}



/**
 * @brief Функція для пошуку навчального закладу з найбільшою кількістю студентів.
 *
 * @param institutions Вказівник на масив структур EducationalInstitution.
 * @param size Розмір масиву institutions.
 * @return Вказівник на EducationalInstitution з найбільшою кількістю студентів, або NULL, якщо size <= 0.
 */

EducationalInstitution* findInstitutionWithMaxStudents(EducationalInstitution *institutions, int size) {


if (size <= 0) return NULL;



EducationalInstitution *maxInstitution = &institutions[0];

for (int i = 1; i < size; i++) {

    if (institutions[i].totalStudents > maxInstitution->totalStudents) {

        maxInstitution = &institutions[i];

    }

}




return maxInstitution;
}

