//FormAI DATASET v1.0 Category: Error handling ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

  char buffer[256];
  FILE *fp;

  fp = fopen("testfile.txt", "r");

  if (fp == NULL) {
    fprintf(stderr, "Failed to open testfile.txt\n");
    exit(EXIT_FAILURE);
  }

  if (fgets(buffer, sizeof buffer, fp) == NULL) {
    fprintf(stderr, "Failed to read line\n");
    exit(EXIT_FAILURE);
  }

  if (strlen(buffer) > 50) {
    fprintf(stderr, "Line exceeded maximum length\n");
    exit(EXIT_FAILURE);
  }

  // continue with program logic...

  if (fclose(fp) == EOF) {
    fprintf(stderr, "Failed to close file\n");
    exit(EXIT_FAILURE);
  }

  printf("Program executed successfully.\n");

  return 0;
}