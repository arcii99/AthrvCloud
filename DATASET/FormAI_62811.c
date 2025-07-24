//FormAI DATASET v1.0 Category: Arithmetic ; Style: Claude Shannon
// Welcome to the world of C Arithmetic with Claude Shannon!
#include <stdio.h>

// Define a base number
#define BASE 10

// Declare a function to perform addition
int add(int a, int b) {
  // Base case: If b is 0, return a
  if (b == 0) return a;
  // Recursive case: Call add() with modified arguments
  int sum = a ^ b;
  int carry = (a & b) << 1;
  return add(sum, carry); // Call function recursively
}

// Declare a function to perform subtraction
int sub(int a, int b) {
  // Base case: If b is 0, return a
  if (b == 0) return a;
  // Recursive case: Call sub() with modified arguments
  int diff = a ^ b;
  int borrow = ((~a) & b) << 1;
  return sub(diff, borrow); // Call function recursively
}

// Declare a function to perform multiplication
int mul(int a, int b) {
  // Base case: If a or b is 0, return 0
  if (a == 0 || b == 0) return 0;
  // Recursive case: Call mul() with modified arguments
  if (b % 2 == 0) {
    return mul(a << 1, b >> 1); // Call function recursively
  } else {
    return add(a, mul(a << 1, b >> 1)); // Call function recursively
  }
}

// Declare a function to perform division
int div(int a, int b) {
  // Base case: If a or b is 0, return 0
  if (a == 0 || b == 0) return 0;
  // Recursive case: Call div() with modified arguments
  if (a < b) {
    return 0; // Return 0 if a is less than b
  } else if (b == 1) {
    return a; // Return a if b is 1
  } else {
    return add(1, div(sub(a, b), b)); // Call function recursively
  }
}

int main() {
  // Test the add() function
  printf("3 + 5 = %d\n", add(3, 5)); // Output: 8
  printf("10 + 20 = %d\n", add(10, 20)); // Output: 30
  
  // Test the sub() function
  printf("10 - 5 = %d\n", sub(10, 5)); // Output: 5
  printf("20 - 15 = %d\n", sub(20, 15)); // Output: 5
  
  // Test the mul() function
  printf("3 * 6 = %d\n", mul(3, 6)); // Output: 18
  printf("2 * 8 = %d\n", mul(2, 8)); // Output: 16
  
  // Test the div() function
  printf("10 / 2 = %d\n", div(10, 2)); // Output: 5
  printf("12 / 4 = %d\n", div(12, 4)); // Output: 3
  
  return 0;
}