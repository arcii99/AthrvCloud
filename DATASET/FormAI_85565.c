//FormAI DATASET v1.0 Category: Math exercise ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // seed random number generator
  
  int num1 = rand() % 20; // generate a random number between 0-19
  int num2 = rand() % 20; // generate another random number between 0-19
  int sum = num1 + num2; // calculate the sum
    
  printf("What is %d + %d?\n", num1, num2); // ask the user for input
  int userAnswer;
  scanf("%d", &userAnswer); // get user input and store in userAnswer

  if(userAnswer == sum){
    printf("Congratulations! Your answer is correct!\n");
  }
  else{
    printf("Sorry, your answer is incorrect. The correct answer is %d.\n", sum);
  }
  
  return 0;
}