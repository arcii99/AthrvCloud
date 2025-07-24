//FormAI DATASET v1.0 Category: Recursive ; Style: high level of detail
#include <stdio.h>

// function to calculate factorial recursively
int factorial(int n) {
  if(n == 0)
    return 1;
  return n * factorial(n-1);
}

// function to print fibonacci sequence recursively
void fibonacci(int n) {
  static int n1=0, n2=1, n3;
  
  if (n > 0) {
    n3 = n1 + n2;
    n1 = n2;
    n2 = n3;
    printf("%d ", n3);
    fibonacci(n-1);
  }
}

int main() {
  int number, choice;
  printf("Enter a number: ");
  scanf("%d", &number);
  printf("Enter 1 to calculate factorial or 2 to print fibonacci sequence: ");
  scanf("%d", &choice);
  
  switch(choice) {
    case 1:
      printf("Factorial of %d is %d\n", number, factorial(number));
      break;
    case 2:
      printf("Fibonacci sequence up to %d is: 0 1 ", number);
      fibonacci(number-2);
      break;
    default:
      printf("Invalid choice\n");
  }

  return 0;
}