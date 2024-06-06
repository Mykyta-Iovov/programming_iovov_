
#include "lib.h"

int main(int argc, char *argv[]) {
  char *text;
  
  if (argc > 1) {
    text = argv[1];
  } else {
    text = "Hello world";
  }

  int result = count_of_words(text);
  return 0;
}
