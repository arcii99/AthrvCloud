//FormAI DATASET v1.0 Category: Arithmetic ; Style: innovative
#include <stdio.h>

int main()
{
  int a, b, c;
  
  printf("Enter the value of a: ");
  scanf("%d", &a);
  
  printf("Enter the value of b: ");
  scanf("%d", &b);
  
  printf("Enter the value of c: ");
  scanf("%d", &c);
  
  int sum = a + b + c;
  int difference = a - b - c;
  int product = a * b * c;
  int quotient = a / b;
  int modulus = a % b;
  float average = sum / 3.0;
  
  printf("\n\nThe sum of %d, %d, and %d is: %d", a, b, c, sum);
  printf("\nThe difference of %d, %d, and %d is: %d", a, b, c, difference);
  printf("\nThe product of %d, %d, and %d is: %d", a, b, c, product);
  printf("\nThe quotient of %d and %d is: %d", a, b, quotient);
  printf("\nThe modulus of %d and %d is: %d", a, b, modulus);
  printf("\nThe average of %d, %d, and %d is: %.2f", a, b, c, average);
  
  return 0;
}