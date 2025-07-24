//FormAI DATASET v1.0 Category: Error handling ; Style: excited
#include <stdio.h>

int main() {
  printf("Welcome to the error handling program!\n");
  
  // Let's try to open a non-existing file
  FILE *file_pointer;
  file_pointer = fopen("non_existing_file.txt", "r");
  if (file_pointer == NULL) {
    printf("Oops! File does not exist.\n");
    return 1;
  }
  
  // Let's divide a number by 0
  int a = 10;
  int b = 0;
  int c;
  if (b == 0) {
    printf("Oops! Division by 0 is not allowed.\n");
    return 1;
  }
  c = a / b;
  printf("Result of a divided by b: %d", c);
  
  // Let's allocate memory dynamically and free it before finished
  int *ptr = malloc(sizeof(int) * 10);
  if (ptr == NULL) {
    printf("Oops! Memory allocation failed.\n");
    return 1;
  }
  free(ptr);
  
  // Let's trigger a segmentation fault
  char *str = "Hello";
  *(str + 10) = '!';
  
  printf("All the errors have been handled successfully! You are a rockstar error handler!\n");
  return 0;
}