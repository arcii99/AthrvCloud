//FormAI DATASET v1.0 Category: Text processing ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
  printf("Welcome to the Text Processor!\n");

  char text[500];
  printf("Please enter some text:\n");
  fgets(text, 500, stdin);

  printf("Thanks! Here's your text with alternating capitalization:\n");
  int i = 0, flag = 1;
  while (text[i] != '\0') {
    if (isalpha(text[i])) {
      if (flag == 1) {
        printf("%c", toupper(text[i]));
        flag = 0;
      } else {
        printf("%c", tolower(text[i]));
        flag = 1;
      }
    } else {
      printf("%c", text[i]);
    }
    i++;
  }
  printf("\n");

  printf("Here's your text with all vowels replaced by the letter 'o':\n");
  i = 0;
  while (text[i] != '\0') {
    if (text[i] == 'a' || text[i] == 'e' || text[i] == 'i' || text[i] == 'o' || text[i] == 'u') {
      printf("o");
    } else {
      printf("%c", text[i]);
    }
    i++;
  }
  printf("\n");

  printf("Thanks for using the Text Processor!\n");
  return 0;
}