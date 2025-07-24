//FormAI DATASET v1.0 Category: Math exercise ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int a, b, c, d, e;
  int correct_answers = 0;
  int total_questions = 0;
  char PlayAgain = 'y';

  printf("Welcome to the Math Quiz!\n");

  while (PlayAgain == 'y') {
    printf("Enter level of difficulty (1-5): ");
    scanf("%d", &e);
    printf("Enter number of questions (1-10): ");
    scanf("%d", &d);

    for (int i = 0; i < d; i++) {
      srand(time(NULL));
      a = rand() % e + 1;
      b = rand() % e + 1;
      c = a * b;
      int user_answer;
      printf("What is %d times %d? ", a, b);
      scanf("%d", &user_answer);
      total_questions++;

      if (user_answer == c) {
        printf("Correct!\n");
        correct_answers++;
      } else {
        printf("Wrong! The correct answer is %d\n", c);
      }
    }

    printf("You answered %d out of %d correctly\n", correct_answers, total_questions);
    printf("Would you like to play again? (y/n)");
    getchar(); // eat a newline character that's left in the buffer
    PlayAgain = getchar();
    printf("\n");
  }

  printf("Thanks for playing the Math Quiz!\n");
  return 0;
}