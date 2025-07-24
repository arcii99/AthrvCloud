//FormAI DATASET v1.0 Category: Error handling ; Style: brave
#include <stdio.h>
#include <stdlib.h>

void error_handler(int status) {
  switch (status) {
    case 1:
      printf("Error: File not found\n");
      break;
    case 2:
      printf("Error: Division by zero\n");
      break;
    case 3:
      printf("Error: Invalid input\n");
      break;
    case 4:
      printf("Error: Memory allocation failed\n");
      break;
    default:
      break;
  }
  exit(1);
}

int main() {
  FILE* fp = fopen("nonexistent_file.txt", "r");
  if (fp == NULL) {
    error_handler(1);
  }

  int numerator = 10, denominator = 0;
  if (denominator == 0) {
    error_handler(2);
  }
  int result = numerator / denominator;
  printf("Result: %d\n", result);

  char str[10];
  printf("Enter a string: ");
  if (fgets(str, 10, stdin) == NULL) {
    error_handler(3);
  }

  int* arr = malloc(1000 * sizeof(int));
  if (arr == NULL) {
    error_handler(4);
  }

  return 0;
}