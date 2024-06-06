/**
 * @file lib.h
 * @brief Заголовочний файл, що містить прототипи функцій для роботи з динамічним масивом.
 *
 */

#ifndef LIB_H

#define LIB_H

#include <stdio.h>

#include <stdlib.h>

/**
 *
 * @brief Додає новий елемент до динамічного масиву.
 * @details Функція додає новий елемент до динамічного масиву arr, збільшуючи його розмір на одиницю.
 * @param  arr Вказівник на початок динамічного масиву.
 * @param size Вказівник на змінну, що зберігає поточний розмір масиву.
 * @param element Елемент, який потрібно додати до масиву.
 * @return Вказівник на оновлений масив після додавання нового елементу.
 */

int *append(int *arr, int *size, int element);

#endif