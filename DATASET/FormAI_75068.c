//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // seed random number generator with the current time
  int score = 0;
  int num1, num2, answer, guess;
  char operator;
  while (1) {
    num1 = rand() % 10 + 1; // generate random number between 1 and 10
    num2 = rand() % 10 + 1;
    switch(rand() % 4) { // randomly choose an arithmetic operator (+, -, *, /)
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
    }
    printf("Score: %d\n", score);
    printf("What is %d %c %d? ", num1, operator, num2);
    scanf("%d", &guess); // get user's guess
    if (guess == answer) {
      printf("Correct!\n");
      score += 10;
    } else {
      printf("Incorrect. The answer is %d.\n", answer);
      if (score >= 10) {
        score -= 10;
      }
    }
  }
  return 0;
}