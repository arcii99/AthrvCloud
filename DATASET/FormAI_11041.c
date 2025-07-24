//FormAI DATASET v1.0 Category: Math exercise ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
  printf("Welcome to the Math Game, where you'll test your math skills!\n");
  printf("Are you ready to begin? Press any key to continue...\n");
  getchar();
  
  printf("\nRound 1: Addition\n");
  int num1 = rand() % 10 + 1;
  int num2 = rand() % 10 + 1;
  int correct_answer = num1 + num2;
  int user_answer;
  printf("What is the sum of %d and %d?\n", num1, num2);
  scanf("%d", &user_answer);
  if(user_answer == correct_answer) {
    printf("Correct! You've earned 10 points!\n");
  }
  else {
    printf("Incorrect! The correct answer is %d. You've earned 0 points.\n", correct_answer);
    printf("Game Over!\n");
    return 0;
  }
  
  printf("\nRound 2: Subtraction\n");
  num1 = rand() % 10 + 1;
  num2 = rand() % 10 + 1;
  correct_answer = num1 - num2;
  printf("What is the difference between %d and %d?\n", num1, num2);
  scanf("%d", &user_answer);
  if(user_answer == correct_answer) {
    printf("Correct! You've earned 10 points!\n");
  }
  else {
    printf("Incorrect! The correct answer is %d. You've earned 0 points.\n", correct_answer);
    printf("Game Over!\n");
    return 0;
  }
  
  printf("\nRound 3: Multiplication\n");
  num1 = rand() % 10 + 1;
  num2 = rand() % 10 + 1;
  correct_answer = num1 * num2;
  printf("What is the product of %d and %d?\n", num1, num2);
  scanf("%d", &user_answer);
  if(user_answer == correct_answer) {
    printf("Correct! You've earned 10 points!\n");
  }
  else {
    printf("Incorrect! The correct answer is %d. You've earned 0 points.\n", correct_answer);
    printf("Game Over!\n");
    return 0;
  }
  
  printf("\nRound 4: Division\n");
  int quotient;
  num1 = rand() % 10 + 1;
  num2 = rand() % 10 + 1;
  correct_answer = (int) num1 / num2;
  printf("What is the quotient of %d divided by %d?\n", num1, num2);
  scanf("%d", &user_answer);
  if(user_answer == correct_answer) {
    printf("Correct! You've earned 10 points!\n");
  }
  else {
    printf("Incorrect! The correct answer is %d. You've earned 0 points.\n", correct_answer);
    printf("Game Over!\n");
    return 0;
  }
  
  printf("\nRound 5: Power\n");
  num1 = rand() % 5 + 1;
  num2 = rand() % 3 + 1;
  correct_answer = pow(num1, num2);
  printf("What is %d raised to the power of %d?\n", num1, num2);
  scanf("%d", &user_answer);
  if(user_answer == correct_answer) {
    printf("Correct! You've earned 10 points!\n");
  }
  else {
    printf("Incorrect! The correct answer is %d. You've earned 0 points.\n", correct_answer);
    printf("Game Over!\n");
    return 0;
  }
  
  printf("\nCongratulations, you've completed the Math Game and earned a perfect score of 50 points!\n");
  
  return 0;
}