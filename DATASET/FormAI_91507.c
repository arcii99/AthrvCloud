//FormAI DATASET v1.0 Category: Word Count Tool ; Style: multivariable
#include <stdio.h>
#include <ctype.h>

int main() {
  char input[1000];
  int c_count = 0, w_count = 0, l_count = 0;
  char c; 

  printf("Enter a sentence: ");

  while ((c = getchar()) != EOF) {
    input[c_count] = c;
    c_count++;

    if (c == '\n') {
      input[c_count - 1] = '\0';
      break;
    }
  }

  for (int i = 0; input[i] != '\0'; i++) {
    if (input[i] == ' ') {
      w_count++;
    }
    if (isalpha(input[i])) {
      l_count++;
    }
  }

  w_count++;

  printf("\nNumber of characters: %d\n", c_count);
  printf("Number of words: %d\n", w_count);
  printf("Number of letters: %d\n", l_count);

  return 0;
}