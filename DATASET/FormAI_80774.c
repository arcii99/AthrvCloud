//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: multivariable
#include <stdio.h>

int main() {
  int a = 10, b = 20, c = 30, d = 40;
  int result = 0;

  /* Performance-critical component that requires optimizing */

  for (int i = 0; i < 10000000; i++) {
    result += a * b + c * d;
    result += b * c + d * a;
    result += c * d + a * b;
    result += d * a + b * c;
  }

  /* End of performance-critical component */

  printf("Result: %d\n", result);
  return 0;
}