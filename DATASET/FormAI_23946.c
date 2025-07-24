//FormAI DATASET v1.0 Category: Error handling ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

int divide(int a, int b, int* result) {
  if (b == 0) {
    return -1; // error code for divide by zero
  }
  
  *result = a / b;
  return 0; // success
}

int main() {
  int a = 10;
  int b = 2;
  int result;
  
  int err = divide(a, b, &result);
  if (err == -1) {
    fprintf(stderr, "Error: divide by zero\n");
    exit(EXIT_FAILURE);
  }
  
  printf("%d / %d = %d\n", a, b, result);
  
  return 0;
}