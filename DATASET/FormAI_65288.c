//FormAI DATASET v1.0 Category: Text processing ; Style: high level of detail
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
  char input1[100];
  char input2[100];

  printf("Enter a word or sentence: ");
  fgets(input1, 100, stdin);
  printf("Enter a character to count: ");
  fgets(input2, 100, stdin);

  int count = 0;
  char *temp = input1;

  while (*temp) {
    if (tolower(*temp) == tolower(*input2)) {
      count++;
    }
    temp++;
  }

  printf("The character %c appears %d times in '%s'", *input2, count, input1);

  return 0;
}