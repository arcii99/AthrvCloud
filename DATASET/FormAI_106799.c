//FormAI DATASET v1.0 Category: Error handling ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fp;

  fp = fopen("non-existing-file.txt", "r");

  if (fp == NULL) {
    perror("Error opening file:");
    exit(EXIT_FAILURE);
  }

  // do some file processing

  fclose(fp);

  return 0;
}