

int count_of_words(char text[]) {

  int result = 0; //Змінна для зберігання кількості слів
  int isWord = 0; // Флаг, який вказує, чи розпочалось слово
  for (int i = 0; text[i] != '\0';
       i++) { //Перевірка   кожного символа рядка до завершення рядка

    //Перевірка на пробіли, табуляції та символом нового рядка, а також  на знак
    //оклику, питання
    if (text[i] != ' ' && text[i] != '\t' && text[i] != '\n' &&
        text[i] != '!' && text[i] != '?') {
      if (!isWord) {
        result++;
        isWord = 1;
      }
    } else { //Якщо поточний символ дорівнює пробілу, табуляції або символу
             //рядка, то слово закінчилось
      isWord = 0;
    }
  }
  return result;
}

int main(int argc, char *argv[]) {
  char *text;
  int result;
  if (argc > 1) {
    text = argv[1]; // Використовувати текст з аргументу командного рядка
  } else {
    text = "Hello world"; // "Hello world" Є за замовчуванням
  }

  result = count_of_words(text);
  return 0;
}
