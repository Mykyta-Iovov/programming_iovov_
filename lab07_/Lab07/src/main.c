

#include <stdarg.h>
//Функція для рахування кількості пар
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

  int last = va_arg(args, int);
  if (last > 0) {
    resultat++;
  }

  va_end(args); //функція завершує обробку змінного списку аргументів.
  return resultat;
}

int main() {
  int result = count_of_pairs(3, 4, 3, 3, 4, 2);

  return 0;
}
