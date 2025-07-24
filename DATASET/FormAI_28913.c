//FormAI DATASET v1.0 Category: Math exercise ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int answer, guess;
  int num1, num2;
  char operations[] = {'+', '-', '*', '/'};
  char operation;
  
  srand(time(NULL));
  num1 = rand() % 100 + 1;
  num2 = rand() % 100 + 1;
  operation = operations[rand() % 4];
  
  printf("Welcome to the post-apocalyptic Math Exercise Challenge!\n");
  printf("Your mission is to solve the following equation:\n");
  printf("%d %c %d = ", num1, operation, num2);
  
  switch(operation) {
    case '+':
      answer = num1 + num2;
      break;
    case '-':
      answer = num1 - num2;
      break;
    case '*':
      answer = num1 * num2;
      break;
    case '/':
      answer = num1 / num2;
      break;
  }
  
  scanf("%d", &guess);
  
  if(guess == answer) {
    printf("Congratulations! You have successfully completed the Math Exercise Challenge!\n");
  } else {
    printf("Incorrect. The correct answer is %d.\n", answer);
    printf("Unfortunately, you have failed the Math Exercise Challenge. As punishment, you will be sent on a dangerous mission to scavenge for supplies in the wasteland.\n");
  }
  
  return 0;
}