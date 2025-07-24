//FormAI DATASET v1.0 Category: Math exercise ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int num1, num2, answer;
  int score = 0;
  int i;

  srand(time(NULL));

  printf("Welcome to the Math Quiz!\n");
  printf("You will be given two random numbers and asked to add them together.\n");

  for(i = 1; i <= 10; i++) {
    num1 = rand() % 100 + 1;
    num2 = rand() % 100 + 1;

    printf("\nQuestion %d:\n", i);
    printf("%d + %d = ", num1, num2);
    scanf("%d", &answer);

    if(answer == num1 + num2) {
      printf("Correct!\n");
      score++;
    } else {
      printf("Sorry, the correct answer is %d.\n", num1 + num2);
    }
  }

  printf("\n\nQuiz complete!\n");
  printf("You scored %d out of 10.\n", score);

  if (score >= 8) {
    printf("Congratulations, you passed the quiz with flying colors!\n");
  } else if (score >= 6) {
    printf("Not bad, but there's definitely room for improvement.\n");
  } else {
    printf("Oh no, looks like you need to brush up on your addition skills!\n");
  }

  return 0;
}