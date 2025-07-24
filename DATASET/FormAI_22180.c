//FormAI DATASET v1.0 Category: Word Count Tool ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char input[1000], word[1000];
  int count = 0;

  printf("Enter a string: ");
  fgets(input, 1000, stdin);

  printf("Enter a word to count: ");
  scanf("%s", word);

  char *ptr = input;

  while ((ptr = strstr(ptr, word))) {
    count++;
    ptr++;
  }

  printf("'%s' occurs %d times in the input string.\n", word, count);

  return 0;
}