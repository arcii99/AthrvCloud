//FormAI DATASET v1.0 Category: Arithmetic ; Style: safe
#include <stdio.h>

int main() {
  int a, b, c;
  printf("Enter three integer values: ");
  scanf("%d %d %d", &a, &b, &c);
  
  // Ensuring that the division is safe
  if(c == 0) {
    printf("The third integer value cannot be zero! Exiting...");
    return 1;
  }

  int d = a + b * c; // Arithmetic operation
  printf("Result of the operation: %d\n", d);

  // Checking if the result will exceed the maximum value of an integer
  if(d > 2147483647) {
    printf("The result of the operation exceeds the maximum value of an integer! Exiting...");
    return 1;
  }
  
  // Checking if the result will be less than the minimum value of an integer
  if(d < -2147483648) {
    printf("The result of the operation is less than the minimum value of an integer! Exiting...");
    return 1;
  }

  // if the result is safe, then print it out
  printf("The final result is safe: %d\n", d);

  return 0;
}