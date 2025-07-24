//FormAI DATASET v1.0 Category: Word Count Tool ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char input[1000];
  printf("Welcome to the Medieval Word Count Tool!\n");
  printf("Enter text to count: ");
  fgets(input, 1000, stdin);

  int count = 0;
  char *word = strtok(input, " ");
  while(word != NULL) {
    count++;
    word = strtok(NULL, " ");
  }

  printf("\nThe number of words is %d, my Liege.\n", count);

  return 0;
}