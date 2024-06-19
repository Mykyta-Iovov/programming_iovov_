/**
 * @file main.c
 * @brief Головний файл програми для читання матриці з файлу, обчислення її детермінанта та запису результату у вихідний файл.
 */


#include "lib.h"

/**
 * @brief Головна функція програми.
 * 
 * @param argc Кількість аргументів командного рядка.
 * @param argv Массив аргументів командного рядка.
 * @return int Код завершення програми (0 - успішне виконання, 1 - помилка).
 */
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", *(argv + 0));
        return 1;
    }

    const char *input_filename = *(argv + 1);
    const char *output_filename = *(argv + 2);

    int **matrix;
    int rows, cols;

    // Читаємо матрицю з файлу
    matrix = readMatrixFromFile(input_filename, &rows, &cols);
    if (matrix == NULL) {
        printf("Помилка зчитування матриці з файлу %s.\n", input_filename);
        return 1;
    }

    // Виводимо матрицю для перевірки
    printf("Матриця: \n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", *(*(matrix + i) + j)); 
        }
        printf("\n");
    }

    // Перевіряємо, що матриця квадратна (кількість рядків дорівнює кількості стовпців)
    if (rows != cols) {
        printf("Матриця не є квадратною, не можливо розрахувати детермінант.\n");
        freeMatrix(matrix, rows);
        return 1;
    }

    // Обчислюємо визначник матриці
    int det = determinant(matrix, rows);

    // Записуємо результат у вихідний файл
    FILE *output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Помилка при відкритті вихідного файлу %s.\n", output_filename);
        freeMatrix(matrix, rows);
        return 1;
    }

    printf("\nДетермінант матриці дорівнює: %d.\n", det);
    fprintf(output_file, "Детермінант матриці з файлу %s дорівнює %d.\n", input_filename, det);
    fprintf(output_file, "\nМатриця: \n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(output_file, "%d ", *(*(matrix + i) + j)); 
        }
        fprintf(output_file, "\n");
    }
    fclose(output_file);

   
    freeMatrix(matrix, rows);
    

    return 0;
}

