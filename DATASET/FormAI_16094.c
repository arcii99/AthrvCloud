//FormAI DATASET v1.0 Category: Recursive ; Style: relaxed
#include <stdio.h>

int fibonacci(int n) {
  if(n == 0) {
    return 0;
  }
  else if (n == 1 || n ==2) {
    return 1;
  }
  else {
    return fibonacci(n-1) + fibonacci(n-2);
  }
}

int main() {
  int n;
  printf("Enter the number of terms to generate in the Fibonacci sequence:\n");
  scanf("%d", &n);
  printf("The first %d terms of the Fibonacci sequence are:\n", n);

  for(int i = 0; i < n; i++){
    printf("%d ", fibonacci(i));
  }

  return 0;
}

/*
 Output:
 Enter the number of terms to generate in the Fibonacci sequence:
 10
 The first 10 terms of the Fibonacci sequence are:
 0 1 1 2 3 5 8 13 21 34
 */