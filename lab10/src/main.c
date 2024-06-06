
/**
 * @file main.c
 * @brief Програма для визначення кількості повторювань чисел у масиві.
 * 
 * 
*/

/**
 * @brief Основна функція програми.
 * @return 0 у випадку успішного завершення програми.
 *
 *
 */
#include "lib.h"

#define N 10

int main()
{

    int arr[N] = {1, 1, 1, 4, 5, 6, 7, 8, 10, 10}; //Ініцілізація масиву

    int *result = malloc(4);

    int *result_size = malloc(4); 

    //Цикл для перевірки кожного елемента масиву
    for (int i = 0; i < N; i++)
    {

        int count = 0;

        for (int el = 0; el < N; el++)
        {

            if (*(arr + i) == *(arr + el))
            {

                count++;
            }
        }

        if (count > 1)
        {

            result = append(result, result_size, *(arr + i));

            result = append(result, result_size, count);
        }
    }

    free(result);
    free(result_size);

    return 0;
}
















