//FormAI DATASET v1.0 Category: Recursive ; Style: configurable
#include <stdio.h>

int factorial(int num) {
  int result = 1;
  for (int i=num; i>0; i--) {
    result *= i;
  }
  return result;
}

int fibonacci(int num) {
  if (num <= 1) {
    return num;
  }
  return fibonacci(num-1) + fibonacci(num-2);
}

int main() {
  int choice, num;
  
  printf("Enter the type of calculation:\n");
  printf("1. Factorial\n");
  printf("2. Fibonacci\n");
  scanf("%d", &choice);
  
  printf("Enter the number for calculation: ");
  scanf("%d", &num);
  
  if (choice == 1) {
    printf("Factorial of %d is %d\n", num, factorial(num));
  }
  else if (choice == 2) {
    printf("Fibonacci of %d is %d\n", num, fibonacci(num));
  }
  else {
    printf("Invalid choice!\n");
  }
  
  return 0;
}