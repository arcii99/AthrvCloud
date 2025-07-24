//FormAI DATASET v1.0 Category: Arithmetic ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  printf("Connecting to cyber-network...\n");
  printf("Access granted. Initializing cyber arithmetic program...\n");

  // Generate two random integers
  srand(time(NULL));
  int a = rand() % 100;
  int b = rand() % 100;

  // Display the numbers to the user
  printf("Two numbers have been randomly generated: %d and %d\n", a, b);
  printf("Performing cyber-mathematics...\n\n");

  // Add the two numbers
  int sum = a + b;
  printf("The sum of the two numbers is: %d\n", sum);

  // Subtract the second number from the first
  int difference = a - b;
  printf("The difference between the two numbers is: %d\n", difference);

  // Multiply the two numbers
  int product = a * b;
  printf("The product of the two numbers is: %d\n", product);

  // Divide the first number by the second
  int quotient = a / b;
  printf("The quotient of the two numbers is: %d\n", quotient);

  printf("\nCyber arithmetic complete. Disconnecting from cyber-network.\n");
  return 0;
}