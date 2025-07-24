//FormAI DATASET v1.0 Category: Arithmetic ; Style: unmistakable
#include<stdio.h>

int main() {
  int a = 10, b = 20, c = 30;

  // Adding three numbers
  int sum = a + b + c;
  printf("The sum is: %d\n", sum);

  // Finding the average of three numbers
  float average = (float)(a + b + c)/3;
  printf("The average is: %f\n", average);

  // Multiplying two numbers
  int product = b * c;
  printf("The product is: %d\n", product);

  // Dividing two numbers
  float quotient = (float)b/c;
  printf("The quotient is: %f\n", quotient);

  // Subtracting two numbers
  int difference = b - a;
  printf("The difference is: %d\n", difference);

  // Finding the remainder of two numbers
  int remainder = c % a;
  printf("The remainder is: %d\n", remainder);

  // Incrementing and decrementing numbers
  printf("\nBefore incrementing: a = %d, b = %d, c = %d\n", a, b, c);
  a++;
  b--;
  c+= 2;
  printf("After incrementing: a = %d, b = %d, c = %d\n", a, b, c);

  // Using bitwise operators
  int x = 1, y = 2;
  int bitwise_and = x & y;
  int bitwise_or = x | y;
  int bitwise_xor = x ^ y;
  printf("\nBitwise AND of %d and %d is: %d\n", x, y, bitwise_and);
  printf("Bitwise OR of %d and %d is: %d\n", x, y, bitwise_or);
  printf("Bitwise XOR of %d and %d is: %d\n", x, y, bitwise_xor);
  
  return 0;
}