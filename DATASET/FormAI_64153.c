//FormAI DATASET v1.0 Category: Arithmetic ; Style: complete
#include <stdio.h>

int main() {
  
  int a = 10;
  int b = 20;
  
  // Addition
  int sum = a + b;
  printf("The sum of %d and %d is %d\n", a, b, sum);
  
  // Subtraction
  int difference = a - b;
  printf("The difference between %d and %d is %d\n", a, b, difference);
  
  // Multiplication
  int product = a * b;
  printf("The product of %d and %d is %d\n", a, b, product);
  
  // Division
  if(b != 0) {
    float quotient = (float)a / b;
    printf("The quotient of %d and %d is %.2f\n", a, b, quotient);
  }
  else {
    printf("Cannot divide by zero!\n");
  }
  
  // Modulo
  int remainder = a % b;
  printf("The remainder when %d is divided by %d is %d\n", a, b, remainder);
  
  // Increment and Decrement
  int c = 5;
  printf("The initial value of c is %d\n", c);
  c++;
  printf("The value of c after incrementing is %d\n", c);
  c--;
  printf("The value of c after decrementing is %d\n", c);
  
  // Bitwise Operations
  int x = 10; // 1010
  int y = 6;  // 0110
  printf("The value of x is %d (1010 in binary)\n", x);
  printf("The value of y is %d (0110 in binary)\n", y);
  int and_result = x & y; // 0010 (2 in decimal)
  printf("x AND y is %d (0010 in binary)\n", and_result);
  int or_result = x | y; // 1110 (14 in decimal)
  printf("x OR y is %d (1110 in binary)\n", or_result);
  int xor_result = x ^ y; // 1100 (12 in decimal)
  printf("x XOR y is %d (1100 in binary)\n", xor_result);
  int complement_result = ~x; // 0101 (5 in decimal)
  printf("The complement of x is %d (0101 in binary)\n", complement_result);
  
  return 0;
}