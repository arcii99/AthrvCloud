//FormAI DATASET v1.0 Category: Online Examination System ; Style: future-proof
#include <stdio.h>

int main() {

  /* Variable declarations */
  int questions = 10;
  int correctAnswers = 0;
  int answer;

  /* Welcome message */
  printf("Welcome to the Online C Examination System\n");
  printf("You will be presented with %d multiple-choice questions.\n", questions);

  /* Question loop */
  for (int i = 1; i <= questions; i++) {
    printf("Question %d\n", i);
    printf("What is the output of the following code?\n");
    printf("\n\tint x = 5;\n\tint y = 3;\n\tprintf(\"%d\", x + y);\n\n");
    printf("Options:\n\t1) 8\n\t2) 9\n\t3) 10\n\t4) 11\n");
    printf("Enter your answer (1-4): ");
    scanf("%d", &answer);

    /* Check answer */
    if (answer == 1) {
      correctAnswers++;
      printf("Correct!\n\n");
    } else {
      printf("Incorrect.\n\n");
    }
  }

  /* Score report */
  printf("Exam Completed!\n");
  printf("You answered %d out of %d questions correctly.\n", correctAnswers, questions);

  return 0;
}