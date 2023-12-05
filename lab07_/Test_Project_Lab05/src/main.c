#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generaciya_randomnogo_chysla() { return (rand() % 10) + 1; }

int Perevirka(int num) {
  int result =
      1; // Початкове значення result - 1 (припускаємо, що число є простим)

  if (num == 0) {
    return 0; // Число нуль не є простим
  }

  // Перевірка чи є число менше або дорівнює 2
  if (num <= 1) {
    result = 0; // Якщо число менше або дорівнює 1, то воно не є простим
  } else {
    for (int i = 2; i * i <= num; i++) {
      if (num % i == 0) {
        result = 0; // Знайдено дільник, отже число не є простим
        break;
      }
    }
  }

  return result;
}

int main(int argc, char *argv[]) {
  srand((unsigned int)time(NULL));

  int num;
  if (argc > 1) {
    // Якщо передано аргумент з командного рядка, використати його
    char *endptr;
    long parsed_value = strtol(argv[1], &endptr, 10);

    if (*endptr != '\0' || parsed_value > RAND_MAX || parsed_value < 0) {
      
      return 1;
    }
    num = (int)parsed_value;
  } else {
    // Якщо аргумент не передано, згенерувати випадкове число
    num = generaciya_randomnogo_chysla();
  }

  int result = Perevirka(num);

  if (result == 1) {
    // число є простим

  } else {
    // число не є простим
  }

  return 0;
}
