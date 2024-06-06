
#include "lib.h"

int count_of_words(char text[]) {
  int result = 0;
  int isWord = 0;
  for (int i = 0; text[i] != '\0'; i++) {
    if (text[i] != ' ' && text[i] != '\t' && text[i] != '\n' &&
        text[i] != '!' && text[i] != '?') {
      if (!isWord) {
        result++;
        isWord = 1;
      }
    } else {
      isWord = 0;
    }
  }
  return result;
}
