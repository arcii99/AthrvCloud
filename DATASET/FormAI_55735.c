//FormAI DATASET v1.0 Category: Funny ; Style: minimalist
#include <stdio.h>

int main() {
  int a = 10;
  int b = 5;
  char operation = '+';

  switch(operation) {
    case '+':
      printf("%d + %d = %d\n", a, b, a+b);
      break;
    case '-':
      printf("%d - %d = %d\n", a, b, a-b);
      break;
    case '*':
      printf("%d * %d = %d\n", a, b, a*b);
      break;
    case '/':
      printf("%d / %d = %d\n", a, b, a/b);
      break;
    default:
      printf("Invalid operation!\n");
      break;
  }

  int n = 10;
  int fib_prev = 0;
  int fib_curr = 1;

  for (int i = 0; i < n; i++) {
    printf("%d ", fib_curr);
    int temp = fib_curr;
    fib_curr += fib_prev;
    fib_prev = temp;
  }

  printf("\n");

  int arr[5] = {1, 2, 3, 4, 5};

  for (int i = 0; i < 5; i++) {
    printf("%d ", *(arr+i));
  }

  printf("\n");

  int sum = 0;
  for (int i = 1; i <= 100; i++) {
    if (i % 3 == 0 && i % 5 == 0) {
      printf("FizzBuzz ");
    } else if (i % 3 == 0) {
      printf("Fizz ");
    } else if (i % 5 == 0) {
      printf("Buzz ");
    } else {
      printf("%d ", i);
    }

    sum += i;
  }

  printf("\nSum of numbers from 1 to 100: %d\n", sum);

  return 0;
}