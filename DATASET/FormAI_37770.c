//FormAI DATASET v1.0 Category: Error handling ; Style: complete
#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fp;
  char *filename = "example.txt";
  int num;

  fp = fopen(filename, "r");

  if (fp == NULL) {
    printf("Error: Failed to open file %s.\n", filename);
    exit(EXIT_FAILURE);
  }

  printf("Enter a number: ");
  scanf("%d", &num);

  if (num < 1 || num > 10) {
    printf("Error: Number must be between 1 and 10.\n");
    fclose(fp);
    exit(EXIT_FAILURE);
  }

  if (num == 5) {
    printf("Error: Number cannot be 5.\n");
    fclose(fp);
    exit(EXIT_FAILURE);
  }

  // Do something with the number...

  fclose(fp);
  return 0;
}