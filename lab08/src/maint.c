
/**
 * @file mainf.c
 * @brief Програма для знаходження пар чисел, де одне число більше наступного
*/



#include <stdarg.h>


/**
 * @brief Функція для знаходження кількості пар.
 * 
 * @details Функція отримує кількість чисел та їх значення та повертає кількість пар,
 * де перше число менше наступного.
 * 
 * 
 * @param ... Змінний список аргуменів.
 * 
 * 
 * @return Кількість пар, де перше число менше наступного.
*/
int count_of_pairs(int count, ...) {
  int resultat = 0;
  va_list args;
  va_start(args, count);

  for (int i = 0; i < count - 1; ++i) {
    int potochne = va_arg(args, int);
    int nastupne = va_arg(args, int);

    if (potochne > nastupne) {
      resultat++;
    }
  }

 

  va_end(args); //функція завершує обробку змінного списку аргументів.
  return resultat;
}

/**
 * @brief Точка входу в програму.
 * 
 * @details Точка входу, де викликається функція count_of_pairs для демонстрації її роботи.
 * 
 * @return Завершення програмию
 * 
*/

int main() {
  int result = count_of_pairs(3, 4, 3, 3, 4, 2);

  return 0;
}
