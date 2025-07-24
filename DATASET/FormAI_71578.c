//FormAI DATASET v1.0 Category: Word Count Tool ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: ./wordcount [filename]\n");
    exit(1);
  }

  FILE *file = fopen(argv[1], "r");
  if (!file) {
    printf("Cannot open file %s\n", argv[1]);
    exit(1);
  }

  char c, last_char = ' ';
  int num_words = 0;
  
  while ((c = fgetc(file)) != EOF) {
    if (isspace(c) && !isspace(last_char)) {
      num_words++;
    }
    last_char = c;
  }

  printf("Number of words in %s: %d\n", argv[1], num_words);
  
  fclose(file);
  return 0;
}