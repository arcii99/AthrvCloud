//FormAI DATASET v1.0 Category: Digital signal processing ; Style: synchronous
#include <stdio.h>

// function to calculate the average of two numbers
int average(int x, int y) {
  return (x + y)/2;
}

// function to calculate the sum of two numbers
int sum(int x, int y) {
  return x + y;
}

// function to calculate the difference between two numbers
int difference(int x, int y) {
  return x - y;
}

// function to calculate the product of two numbers
int product(int x, int y) {
  return x * y;
}

// main function
int main() {
  int a, b;
  printf("Enter two numbers: ");
  scanf("%d%d", &a, &b);
  
  // calculate the average of the two numbers
  int avg = average(a, b);
  
  // calculate the sum of the two numbers
  int s = sum(a,b);
  
  // calculate the difference between the two numbers
  int diff = difference(a, b);
  
  // calculate the product of the two numbers
  int prod = product(a,b);
  
  // display the results to the user
  printf("The average of %d and %d is: %d\n", a, b, avg);
  printf("The sum of %d and %d is: %d\n", a, b, s);
  printf("The difference between %d and %d is: %d\n", a, b, diff);
  printf("The product of %d and %d is: %d\n", a, b, prod);
  
  return 0;
}