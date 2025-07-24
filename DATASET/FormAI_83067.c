//FormAI DATASET v1.0 Category: File handling ; Style: statistical
#include <stdio.h>

int main() {
  FILE *file;
  char filename[] = "sample.txt";
  int num_lines = 0;
  int num_words = 0;
  int num_chars = 0;

  if ((file = fopen(filename, "r")) == NULL) {
    printf("Error opening file.\n");
    return 1;
  }

  char c;
  while ((c = fgetc(file)) != EOF) {
    num_chars++;

    if (c == '\n') {
      num_lines++;
    }

    if (c == ' ' || c == '\n') {
      num_words++;
    }
  }

  printf("Statistics for file %s:\n", filename);
  printf("%d characters\n", num_chars);
  printf("%d words\n", num_words);
  printf("%d lines\n", num_lines);

  fclose(file);

  return 0;
}