//FormAI DATASET v1.0 Category: Math exercise ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int score = 0;
  char user_answer[5];

  srand(time(0));

  for(int i = 0; i < 10; i++) {
    int num1 = rand() % 100; // generate a random number between 0 and 99
    int num2 = rand() % 100;
    int answer = num1 + num2; // calculate the correct answer

    printf("Question %d: %d + %d = ", i+1, num1, num2);
    scanf("%s", user_answer);

    if(atoi(user_answer) == answer) { // convert the user's answer to an integer and check if it's correct
      printf("Correct!\n");
      score += 10;
    } else {
      printf("Incorrect. The correct answer is %d\n", answer);
    }
  }

  printf("Your score is %d\n", score);

  return 0;
}