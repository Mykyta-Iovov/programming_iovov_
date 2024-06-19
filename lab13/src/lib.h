/**
 * @file lib.h
 * @brief Заголовковий файл з визначенням функцій для роботи з матрицями.
 */

#ifndef LIB_H
#define LIB_H


#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Зчитує матрицю з файлу.
 * 
 * @param filename Ім'я файлу.
 * @param rows Вказівник на кількість рядків.
 * @param cols Вказівник на кількість стовпців.
 * @return int** Вказівник на зчитану матрицю, або NULL у разі помилки.
 */
int **readMatrixFromFile(const char *filename, int *rows, int *cols);

/**
 * @brief Обчислює визначник матриці.
 * 
 * @param matrix Вказівник на матрицю.
 * @param n Розмір матриці (кількість рядків/стовпців).
 * @return int Визначник матриці.
 */
int determinant(int **matrix, int n);

/**
 * @brief Звільняє пам'ять, виділену під матрицю.
 * 
 * @param matrix Вказівник на матрицю.
 * @param rows Кількість рядків у матриці.
 */
void freeMatrix(int **matrix, int rows);

#endif // LIB_H

