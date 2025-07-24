//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int score = 0;
  srand(time(NULL));
  printf("Welcome to the C Periodic Table Quiz!\n");
  printf("Answer the following questions and earn points.\n");
  printf("Are you ready? Let's begin!\n\n");

  // Question 1
  printf("1. What is the chemical symbol for Carbon?\n");
  printf("a) Cr\n");
  printf("b) C\n");
  printf("c) Ca\n");
  char answer = getchar();
  getchar(); // flush buffer
  if (answer == 'b') {
    printf("Correct!\n");
    score += 10;
  } else {
    printf("Incorrect. The correct answer is b) C.\n");
  }
  printf("Score: %d\n\n", score);

  // Question 2
  printf("2. What is the chemical symbol for Oxygen?\n");
  printf("a) O\n");
  printf("b) Ox\n");
  printf("c) Ol\n");
  answer = getchar();
  getchar(); // flush buffer
  if (answer == 'a') {
    printf("Correct!\n");
    score += 10;
  } else {
    printf("Incorrect. The correct answer is a) O.\n");
  }
  printf("Score: %d\n\n", score);

  // Question 3
  printf("3. What is the chemical symbol for Iron?\n");
  printf("a) Fe\n");
  printf("b) F\n");
  printf("c) Fi\n");
  answer = getchar();
  getchar(); // flush buffer
  if (answer == 'a') {
    printf("Correct!\n");
    score += 10;
  } else {
    printf("Incorrect. The correct answer is a) Fe.\n");
  }
  printf("Score: %d\n\n", score);

  // Question 4
  printf("4. What is the chemical symbol for Hydrogen?\n");
  printf("a) H\n");
  printf("b) He\n");
  printf("c) Ho\n");
  answer = getchar();
  getchar(); // flush buffer
  if (answer == 'a') {
    printf("Correct!\n");
    score += 10;
  } else {
    printf("Incorrect. The correct answer is a) H.\n");
  }
  printf("Score: %d\n\n", score);

  // Question 5
  printf("5. What is the chemical symbol for Sodium?\n");
  printf("a) Sn\n");
  printf("b) Sd\n");
  printf("c) Na\n");
  answer = getchar();
  getchar(); // flush buffer
  if (answer == 'c') {
    printf("Correct!\n");
    score += 10;
  } else {
    printf("Incorrect. The correct answer is c) Na.\n");
  }
  printf("Score: %d\n\n", score);

  // Random bonus question
  int bonus = rand() % 2;
  if (bonus) {
    printf("Bonus Question: What is the atomic number of Zinc?\n");
    printf("a) 30\n");
    printf("b) 60\n");
    printf("c) 90\n");
    answer = getchar();
    getchar(); // flush buffer
    if (answer == 'a') {
      printf("Correct!\n");
      score += 20;
    } else {
      printf("Incorrect. The correct answer is a) 30.\n");
    }
    printf("Score: %d\n\n", score);
  }

  printf("Thanks for playing! Your final score is: %d\n", score);
  return 0; 
}