#include <stdio.h>
#include "lib.h"


#define BUFFER_SIZE 1000






/**

 * @file main.c
 * @brief Основна функція для зчитування введення, розрахунку частот і виведення таблиці частот.
 * 
 * @details Ця функція зчитує введення зі stdin, розраховує частоту кожного символу
 * у введенні за допомогою calculate_frequency(), а потім виводить таблицю частот
 * за допомогою print_frequency_table().
 * 
 * @return int Повертає 0 при успіху, 1 при помилці.
 */




int main() {
    char buffer[BUFFER_SIZE];
    int char_count[ASCII_SIZE] = {0};
    int total_chars = 0;

    // Зчитуємо дані зі стандартного вводу
    if (fgets(buffer, BUFFER_SIZE, stdin) != NULL) {
        // Підраховуємо кількість кожного символу
        calculate_frequency(buffer, char_count, &total_chars);

        // Виводимо таблицю частот символів
        print_frequency_table(char_count, total_chars);
    } else {
        printf( "Error reading input.\n");
        return 1;
    }



    return 0;
}

