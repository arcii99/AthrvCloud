//FormAI DATASET v1.0 Category: Math exercise ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  // Random Seed
  srand(time(NULL));
  
  // Random numbers between 1-100
  int num1 = rand() % 100 + 1;
  int num2 = rand() % 100 + 1;
  
  // Calculate the sum and difference
  int sum = num1 + num2;
  int difference = num1 - num2;
  
  // Display the numbers and ask the user to solve the problems
  printf("What is the sum of %d and %d?\n", num1, num2);
  int userSum;
  scanf("%d", &userSum);
  
  printf("What is the difference of %d and %d?\n", num1, num2);
  int userDifference;
  scanf("%d", &userDifference);
  
  // Check if the user's answers are correct
  if (userSum == sum && userDifference == difference) {
    printf("Congratulations! You got both answers correct!\n");
  } else if (userSum == sum) {
    printf("You got the sum correct, but the difference was wrong. The difference is %d.\n", difference);
  } else if (userDifference == difference) {
    printf("You got the difference correct, but the sum was wrong. The sum is %d.\n", sum);
  } else {
    printf("Sorry, but both of your answers were incorrect. The correct sum is %d and the correct difference is %d.\n", sum, difference);
  }
  
  return 0;
}