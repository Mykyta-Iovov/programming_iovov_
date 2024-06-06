

/**
 * @file lib.h
 * @brief Оголошення функцій для виводу і підрахунку частоти символів у файлі.
 */



#ifndef LIB_H
#define LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define ASCII_SIZE 256



/**
 * @brief Виводить таблицю частот символів.
 * 
 * @details Ця функція приймає масив частот символів та загальну кількість символів,
 * потім виводить таблицю, яка показує частоту та відсоток кожного символу.
 * 
 * @param char_count Масив, що містить частоту кожного символу.
 * @param total_chars Загальна кількість символів у вхідному буфері.
 */

void print_frequency_table(const int char_count[ASCII_SIZE], int total_chars);




/**
 * @brief Розраховує частоту кожного символу в заданому буфері.
 * 
 * @details Ця функція приймає буфер і розраховує частоту кожного символу
 * в буфері. Результати зберігаються в масиві char_count, а загальна
 * кількість символів зберігається в total_chars.
 * 
 * @param buffer Вхідний рядок буфера.
 * @param char_count Масив для зберігання частоти кожного символу.
 * @param total_chars Вказівник на ціле число, в якому буде зберігатись загальна кількість символів.
 */

void calculate_frequency(const char *buffer, int char_count[ASCII_SIZE], int *total_chars);


#endif
