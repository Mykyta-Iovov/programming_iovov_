/**



 * @file lib.c



 * @brief Функції для обчислення та виводу трикутника Паскаля.



 *



 * @details Цей файл містить функції для обчислення біноміального коефіцієнта,



 * а також для рекурсивного та ітеративного виводу трикутника Паскаля.



 */

#include "lib.h"

/**



 * @brief Обчислення біноміального коефіцієнта.



 *



 * @details Ця функція обчислює біноміальний коефіцієнт C(n, k) за допомогою рекурсивного методу.



 *



 * @param n Розмір множини.



 * @param k Розмір підмножини.



 * @return Значення біноміального коефіцієнта C(n, k).



 */

int binomialCoeff(int n, int k)

{

    if (k == 0 || k == n)

    {

        return 1;
    }

    return binomialCoeff(n - 1, k - 1) + binomialCoeff(n - 1, k);
}

/**



 * @brief Рекурсивний вивід значень в рядку трикутника Паскаля.



 *



 * @param line Номер рядка.



 * @param i Позиція в рядку.



 */

void printPascalLine(int line, int i)

{

    if (i > line)

    {

        return;
    }

    printf("%d ", binomialCoeff(line, i));

    printPascalLine(line, i + 1);
}

/**



 * @brief Рекурсивний вивід пробілів перед рядком трикутника Паскаля.



 *



 * @param spaces Кількість пробілів для виводу.



 */

void printSpaces(int spaces)

{

    if (spaces <= 0)

    {

        return;
    }

    printf(" ");

    printSpaces(spaces - 1);
}

/**



 * @brief Допоміжна функція для рекурсивного виводу трикутника Паскаля.



 *



 * @param n Кількість рядків трикутника Паскаля для виводу.



 * @param line Поточний рядок для виводу.



 */

void printPascalHelper(int n, int line)

{

    if (line >= n)

    {

        return;
    }

    printSpaces(n - line - 1);

    printPascalLine(line, 0);

    printf("\n");

    printPascalHelper(n, line + 1);
}

/**



 * @brief Вивід трикутника Паскаля рекурсивним методом.



 *



 * @param n Кількість рядків трикутника Паскаля для виводу.



 */

void printPascalRecursive(int n)

{

    printPascalHelper(n, 0);
}

/**



 * @brief Вивід трикутника Паскаля ітеративним методом.



 *



 * @details Ця функція виводить трикутник Паскаля до n рядків, використовуючи ітеративний метод



 * для обчислення біноміальних коефіцієнтів та динамічне виділення пам'яті.



 *



 * @param n Кількість рядків трикутника Паскаля для виводу.



 */

void printPascalIterative(int n)
{

    // Виділення пам'яті для двовимірного масиву

    int **arr = (int **)malloc((size_t)n * sizeof(int *));

    for (int i = 0; i < n; i++)
    {

        *(arr + i) = (int *)malloc(((size_t)i + 1) * sizeof(int));
    }

    for (int line = 0; line < n; line++)
    {

        for (int i = 0; i <= line; i++)
        {

            // Перший або останній елемент ряду має значення 1

            if (line == i || i == 0)
            {

                *(*(arr + line) + i) = 1;
            }
            else
            {

                // Обчислення біноміального коефіцієнта для решти елементів

                *(*(arr + line) + i) = *(*(arr + line - 1) + i - 1) + *(*(arr + line - 1) + i);
            }
        }
    }

    // Вивід значень трикутника Паскаля у вигляді рівнобедреного трикутника

    for (int line = 0; line < n; line++)
    {

        for (int space = 0; space < n - line - 1; space++)
        {

            printf(" ");
        }

        for (int i = 0; i <= line; i++)
        {

            printf("%d ", *(*(arr + line) + i));
        }

        printf("\n");
    }

    // Звільнення пам'яті

    for (int i = 0; i < n; i++)
    {

        free(*(arr + i));
    }

    free(arr);
}

