//FormAI DATASET v1.0 Category: Error handling ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main() {
  FILE *file = fopen("non_existent_file.txt", "r");
  if(file == NULL) {
    perror("Error opening file");
    exit(EXIT_FAILURE);
  }

  int num1 = 2;
  int num2 = 0;
  int result;

  if(num2 == 0) {
    fprintf(stderr, "Division by zero\n");
    exit(EXIT_FAILURE);
  }
  result = num1 / num2;

  char *ptr = malloc(sizeof(char) * 10);
  if(ptr == NULL) {
    fprintf(stderr, "Error allocating memory: %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }

  printf("Program success!\n");

  fclose(file);
  free(ptr);
  return 0;
}