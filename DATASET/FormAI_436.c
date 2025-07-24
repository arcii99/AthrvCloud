//FormAI DATASET v1.0 Category: Error handling ; Style: brave
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Welcome to the C Error Handling Program!\n");

  int num1, num2;
  printf("Enter two numbers: ");
  if(scanf("%d %d", &num1, &num2) != 2) {
    fprintf(stderr, "Error: Invalid input\n");
    exit(1);
  }

  int result;
  if(num2 == 0) {
    fprintf(stderr, "Error: Division by zero\n");
    exit(1);
  }
  else {
    result = num1 / num2;
    printf("%d / %d = %d\n", num1, num2, result);
  }

  int* ptr = NULL;
  ptr = malloc(5 * sizeof(int));
  if(ptr == NULL) {
    fprintf(stderr, "Error: Memory allocation failed\n");
    exit(1);
  }
  else {
    printf("Memory allocation successful\n");
    free(ptr);
  }

  FILE* file = fopen("nonexistent_file.txt", "r");
  if(file == NULL) {
    fprintf(stderr, "Error: File doesn't exist\n");
    exit(1);
  }
  else {
    fclose(file);
  }

  printf("End of program\n");

  return 0;
}