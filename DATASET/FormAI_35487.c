//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

int main() {
  int score = 0;
  
  printf("Welcome to the Periodic Table Quiz!\n");
  printf("Please enter the correct symbol for each element.\n");

  // Question 1
  printf("\n1. Hydrogen: ");
  char answer1;
  scanf(" %c", &answer1);
  if (answer1 == 'H') {
    printf("Correct!\n");
    score++;
  } else {
    printf("Incorrect. The correct answer is H.\n");
  }
  
  // Question 2
  printf("\n2. Oxygen: ");
  char answer2;
  scanf(" %c", &answer2);
  if (answer2 == 'O') {
    printf("Correct!\n");
    score++;
  } else {
    printf("Incorrect. The correct answer is O.\n");
  }
  
  // Question 3
  printf("\n3. Sodium: ");
  char answer3;
  scanf(" %c", &answer3);
  if (answer3 == 'Na') {
    printf("Correct!\n");
    score++;
  } else {
    printf("Incorrect. The correct answer is Na.\n");
  }
  
  // Question 4
  printf("\n4. Carbon: ");
  char answer4;
  scanf(" %c", &answer4);
  if (answer4 == 'C') {
    printf("Correct!\n");
    score++;
  } else {
    printf("Incorrect. The correct answer is C.\n");
  }
  
  // Question 5
  printf("\n5. Gold: ");
  char answer5[10];
  scanf(" %s", answer5);
  if (strcmp(answer5, "Au") == 0) {
    printf("Correct!\n");
    score++;
  } else {
    printf("Incorrect. The correct answer is Au.\n");
  }
  
  // Final score
  printf("\nYour final score is %d out of 5!\n", score);

  return 0;
}