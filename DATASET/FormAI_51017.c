//FormAI DATASET v1.0 Category: Math exercise ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int num1, num2, answer, user_answer;
  char operator;
  
  srand(time(NULL)); // seed the random number generator
  
  for (int i = 0; i < 10; i++) {
    num1 = rand() % 10 + 1; // generate a random number between 1 and 10
    num2 = rand() % 10 + 1; // generate another random number between 1 and 10
    
    switch (rand() % 4) { // use a switch statement to randomly decide which operator to use
      case 0:
        operator = '+';
        answer = num1 + num2;
        break;
      case 1:
        operator = '-';
        answer = num1 - num2;
        break;
      case 2:
        operator = '*';
        answer = num1 * num2;
        break;
      case 3:
        operator = '/';
        answer = num1 / num2;
        break;
      default:
        break;
    }
    
    printf("Question %d: %d %c %d = ", i+1, num1, operator, num2); // print the math problem to the console
    scanf("%d", &user_answer); // receive user input
    
    if (user_answer == answer) { // check if the user's answer is correct
      printf("Correct!\n");
    } else {
      printf("Incorrect, the correct answer is %d.\n", answer);
    }
  }
  
  printf("End of math quiz. Goodbye!\n");
  
  return 0;
}