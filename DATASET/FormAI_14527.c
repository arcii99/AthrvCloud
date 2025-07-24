//FormAI DATASET v1.0 Category: Arithmetic ; Style: protected
#include <stdio.h>

int main() {
  int num1, num2, add, subtract, multiply;
  float divide;
  
  printf("Enter two integers: ");
  scanf("%d %d", &num1, &num2);
  
  add = num1 + num2;
  subtract = num1 - num2;
  multiply = num1 * num2;
  divide = num1 / (float)num2;
  
  printf("Addition: %d\n", add);
  printf("Subtraction: %d\n", subtract);
  printf("Multiplication: %d\n", multiply);
  printf("Division: %.2f\n", divide);
  
  if (num1 > num2) {
    printf("%d is greater than %d\n", num1, num2);
  } else if (num1 < num2) {
    printf("%d is lesser than %d\n", num1, num2);
  } else {
    printf("%d and %d are equal\n", num1, num2);
  }
  
  int counter = 0, sum = 0;
  while (counter <= num2) {
    sum += counter;
    counter++;
  }
  
  printf("The sum from 0 to %d is %d\n", num2, sum);
  
  return 0;
}