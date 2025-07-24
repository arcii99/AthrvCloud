//FormAI DATASET v1.0 Category: Arithmetic ; Style: expert-level
#include <stdio.h>

int main() {
  int a = 10, b = 5, c = 2;
  float x = 2.7, y = 1.5, z;
  double pi = 3.14159265358979323846;
  
  // Arithmetic operators
  
  printf("Addition: %d\n", a + b); // Output: Addition: 15
  printf("Subtraction: %d\n", a - b); // Output: Subtraction: 5
  printf("Multiplication: %d\n", a * b); // Output: Multiplication: 50
  printf("Division: %d\n", a / b); // Output: Division: 2
  printf("Modulus: %d\n", a % b); // Output: Modulus: 0
  
  // Type casting
  
  z = (float)a / c; // Type casting 'a' to float and dividing by 'c'
  printf("Type Casting: %f\n", z); // Output: Type Casting: 5.000000
  
  // Precedence of operators
  
  z = x / 3 * 2 + y - 1 / 4 * pi; // Using BODMAS rule for operator precedence
  printf("Precedence: %f\n", z); // Output: Precedence: 1.184296
  
  return 0;
}