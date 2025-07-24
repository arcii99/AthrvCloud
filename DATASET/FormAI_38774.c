//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: cheerful
#include <stdio.h>

int main() {
  int a = 2, b = 3;
  int result = 0;
  for (int i = 0; i < 10000000; i++) {
      int temp = a * b;
      result += temp;
  }
  printf("The result is: %d\n", result);
  return 0;
}