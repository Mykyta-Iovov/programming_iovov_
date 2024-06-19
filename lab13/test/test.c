/**
 * @file test.c
 * @brief Тестовий файл для перевірки функцій роботи з матрицями.
 */

#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

/**
 * @brief Тестує функцію readMatrixFromFile.
 */
void test_readMatrixFromFile() {
    int rows, cols;
    int **matrix = readMatrixFromFile("matrix.txt", &rows, &cols);

    if (matrix == NULL) {
        printf("Помилка зчитування матриці з файлу matrix.txt.\n");
        return;
    }

    printf("Матриця з файлу matrix.txt:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", *(*(matrix + i) + j)); 
        }
        printf("\n");
    }

    freeMatrix(matrix, rows);
}

/**
 * @brief Тестує функцію determinant.
 */
void test_determinant() {
    int rows = 3, cols = 3;
    int **matrix = (int **)malloc((size_t)rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        *(matrix + i) = (int *)malloc((size_t)cols * sizeof(int));
    }

    // Заповнюємо матрицю
    int values[3][3] = {{1, 2, 3}, {0, 1, 4}, {5, 6, 0}};
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            *(*(matrix + i) + j) = *(*(values + i) + j); 
        }
    }

    // Обчислюємо визначник
    int det = determinant(matrix, rows);
    printf("Визначник матриці дорівнює %d\n", det);

    freeMatrix(matrix, rows);
}

/**
 * @brief Головна функція для запуску тестів.
 * 
 * @return int Код завершення програми (0 - успішне виконання).
 */
 
int main() {
    test_readMatrixFromFile();
    test_determinant();
    return 0;
}

