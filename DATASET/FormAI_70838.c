//FormAI DATASET v1.0 Category: Recursive ; Style: optimized
#include<stdio.h>

int fibonacci(int n) {
  if(n == 0) {
    return 0;
  }
  else if(n == 1) {
    return 1;
  }
  else {
    int f0 = 0, f1 = 1, fib = 0;
    while(n > 1) {
      fib = f0 + f1;
      f0 = f1;
      f1 = fib;
      n--;
    }
    return fib;
  }
}

int main() {
  int n = 10;
  printf("The first %d fibonacci numbers are:\n", n);
  for(int i = 0; i < n; i++) {
    printf("%d ", fibonacci(i));
  }
  return 0;
}