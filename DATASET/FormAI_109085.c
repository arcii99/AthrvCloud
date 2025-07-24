//FormAI DATASET v1.0 Category: Recursive ; Style: minimalist
#include <stdio.h>

int fibonacci(int num) {
  if (num <= 1) {
    return num;
  }

  return fibonacci(num - 1) + fibonacci(num - 2);
}

int main() {
  int num, i;

  printf("Enter the number of terms: ");
  scanf("%d", &num);

  printf("The Fibonacci sequence is: ");
  for(i = 0; i < num; i++) {
    printf("%d ", fibonacci(i));
  }

  return 0;
}