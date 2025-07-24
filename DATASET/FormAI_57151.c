//FormAI DATASET v1.0 Category: Recursive ; Style: sophisticated
#include <stdio.h>

int fib(int n) {
  if (n == 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  } else {
    return fib(n-1) + fib(n-2);
  }
}

int main() {
  for (int i = 0; i < 10; i++) {
    printf("%d ", fib(i));
  }
  return 0;
}