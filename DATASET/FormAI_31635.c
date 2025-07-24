//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main() {
  char elements[18][3] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar"};
  int num_questions = 10;
  int correct = 0;
  int incorrect = 0;
  int i;
  char answer[3];

  printf("Welcome to the Periodic Table Quiz!\n\n");
  printf("Please enter your name: ");
  char name[50];
  scanf("%s", name);
  printf("\nHello, %s! Let's begin the quiz!\n\n", name);

  srand(time(0)); // seed the random number generator

  for (i = 0; i < num_questions; i++) {
    int element_index = rand() % 18; // randomly select an element index
    printf("Question %d: What is the symbol for %s?\n", i+1, elements[element_index]);
    printf("Enter your answer: ");
    scanf("%s", answer);

    // Convert answer to uppercase
    int j;
    for (j = 0; answer[j]; j++) {
        answer[j] = toupper(answer[j]);
    }

    // Check if answer is correct
    if (strcmp(answer, elements[element_index]) == 0) {
      printf("Correct!\n\n");
      correct++;
    } else {
      printf("Incorrect. The correct answer is %s.\n\n", elements[element_index]);
      incorrect++;
    }
  }

  printf("Quiz complete!\n");
  printf("You answered %d questions correctly and %d questions incorrectly.\n", correct, incorrect);

  return 0;
}