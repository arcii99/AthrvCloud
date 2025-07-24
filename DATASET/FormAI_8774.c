//FormAI DATASET v1.0 Category: Arithmetic ; Style: shocked
#include <stdio.h>

int main() {
  int a = 10;
  int b = 5;
  int c = 2;
  int d = 8;
  int e = 3;

  // addition
  int sum = a + b + c + d + e;
  printf("The sum of all values is: %d\n", sum);
  
  // subtraction
  int sub = a - b;
  printf("The subtraction of %d from %d is: %d\n", b, a, sub);
  
  // multiplication
  int mul = a * b * c;
  printf("%d multiplied by %d and %d is: %d\n", a, b, c, mul);
  
  // division
  int div = d / b;
  printf("%d divided by %d is: %d\n", d, b, div);
  
  // modulus
  int mod = d % c;
  printf("The remainder of %d divided by %d is: %d\n", d, c, mod);
  
  // increment
  int inc = ++a;
  printf("The value of a after incrementing by 1 is: %d\n", inc);
  
  // decrement
  int dec = --b;
  printf("The value of b after decrementing by 1 is: %d\n", dec);
  
  return 0;
}