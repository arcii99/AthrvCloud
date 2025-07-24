//FormAI DATASET v1.0 Category: Math exercise ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Declare variables and initialize random seed
  int num1, num2, sum, input;
  srand(time(0));
  
  // Generate two random numbers between 1 and 50
  num1 = rand() % 50 + 1;
  num2 = rand() % 50 + 1;
  
  // Calculate the sum of the two numbers
  sum = num1 + num2;
  
  // Prompt the user to input the sum of the two numbers
  printf("Welcome to the Math Exercise program!\n");
  printf("Please solve the following problem:\n");
  printf("%d + %d = ", num1, num2);
  
  // Read the user's input
  scanf("%d", &input);
  
  // Check if the user's input is correct
  if (input == sum) {
    printf("Congratulations! You are correct!\n");
  }
  else {
    printf("Sorry, the correct answer is %d.\n", sum);
  }
  
  return 0;
}