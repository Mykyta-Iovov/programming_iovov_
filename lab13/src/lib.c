/**
 * @file lib.c
 * @brief Реалізація функцій для роботи з матрицями.
 */

#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

/**
 * @brief Зчитує матрицю з файлу.
 * 
 * @param filename Ім'я файлу.
 * @param rows Вказівник на кількість рядків.
 * @param cols Вказівник на кількість стовпців.
 * @return int** Вказівник на зчитану матрицю, або NULL у разі помилки.
 */
int **readMatrixFromFile(const char *filename, int *rows, int *cols) {
    FILE *fp;
    int **matrix = NULL;
    int i, j;

    // Відкриваємо файл для читання
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Помилка при відкритті файлу %s.\n", filename);
        return NULL;
    }

    // Зчитуємо кількість рядків і стовпців
    fscanf(fp, "%d %d", rows, cols);

    // Виділяємо пам'ять під матрицю
    matrix = (int **)malloc((size_t)(*rows) * sizeof(int *));
    if (matrix == NULL) {
        printf("Помилка виділення пам'яті.\n");
        fclose(fp);
        return NULL;
    }

    for (i = 0; i < *rows; i++) {
        *(matrix + i) = (int *)malloc((size_t)(*cols) * sizeof(int));
        if (*(matrix + i) == NULL) {
            printf("Помилка виділення пам'яті.\n");
            fclose(fp);
            freeMatrix(matrix, i);
            return NULL;
        }
    }

    // Зчитуємо елементи матриці
    for (i = 0; i < *rows; i++) {
        for (j = 0; j < *cols; j++) {
            fscanf(fp, "%d", (*(matrix + i) + j)); 
        }
    }

    
    fclose(fp);

    return matrix;
}

/**
 * @brief Обчислює визначник матриці.
 * 
 * @param matrix Вказівник на матрицю.
 * @param n Розмір матриці (кількість рядків/стовпців).
 * @return int Визначник матриці.
 */
int determinant(int **matrix, int n) {
    int det = 0;

    
    if (n == 1) {
        return *(*(matrix + 0) + 0);
    }

    // Для матриць більшого розміру обчислюємо визначник за методом розкладу по першому рядку
    int sign = 1;
    for (int i = 0; i < n; i++) {
        // Обчислюємо мінор матриці
        int **minor = (int **)malloc((size_t)(n - 1) * sizeof(int *));
        for (int k = 0; k < n - 1; k++) {
            *(minor + k) = (int *)malloc((size_t)(n - 1) * sizeof(int));
        }

        // Заповнюємо мінор, виключаючи поточний рядок і стовпець i
        for (int j = 1; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (k < i) {
                    *(*(minor + j - 1) + k) = *(*(matrix + j) + k);
                } else if (k > i) {
                    *(*(minor + j - 1) + k - 1) = *(*(matrix + j) + k);
                }
            }
        }

        // Обчислюємо визначник мінора і додаємо до загального визначника з урахуванням знака
        det += sign * *(*(matrix + 0) + i) * determinant(minor, n - 1);

        
        for (int k = 0; k < n - 1; k++) {
            free(*(minor + k));
        }
        free(minor);

        // Змінюємо знак для наступного мінора
        sign = -sign;
    }

    return det;
}

/**
 * @brief Звільняє пам'ять, виділену під матрицю.
 * 
 * @param matrix Вказівник на матрицю.
 * @param rows Кількість рядків у матриці.
 */
void freeMatrix(int **matrix, int rows) {
    if (matrix == NULL) return;

    for (int i = 0; i < rows; i++) {
        free(*(matrix + i));
    }
    free(matrix);
}

