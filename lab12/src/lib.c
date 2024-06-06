#include <stdio.h>
#include "lib.h"


/**
 * @file lib.c
 *@brief файл з функціями для підрахунку частотності символів у текстовому файлі.
 */
 	



/**
 * 
 * @brief Виводить таблицю частот символів.
 * 
 * @details Ця функція приймає масив частот символів та загальну кількість символів,
 * потім виводить таблицю, яка показує частоту та відсоток кожного символу.
 * 
 * @param char_count Масив, що містить частоту кожного символу.
 * @param total_chars Загальна кількість символів у вхідному буфері.
 */
 
 
 
void print_frequency_table(const int char_count[ASCII_SIZE], int total_chars) {
    printf("Character Frequency Table:\n");
    printf("Char | Count | Percentage\n");
    printf("-----+-------+-----------\n");

    for (int i = 0; i < ASCII_SIZE; i++) {
        if (*(char_count + i) > 0) {
            double percentage = (*(char_count + i) / (double)total_chars) * 100;
            printf("  %c  |  %4d |  %7.2f%%\n", i, *(char_count + i), percentage);
        }
    }
}



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


void calculate_frequency(const char *buffer, int char_count[ASCII_SIZE], int *total_chars) {
    *total_chars = 0;
    for (size_t i = 0; i < strlen(buffer); i++) {
        *(char_count + (unsigned char)*(buffer + i)) += 1;
        (*total_chars)++;
    }
}

