//FormAI DATASET v1.0 Category: Math exercise ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // seed for random number generation
  int a = rand() % 10 + 1; // generate a random integer between 1-10
  int b = rand() % 10 + 1; // generate another random integer between 1-10
  int op = rand() % 4; // generate a random integer between 0-3 (0: add, 1: subtract, 2: multiply, 3: divide)

  int answer, user_answer;

  // randomly select arithmetic operation and print the problem
  switch (op) {
    case 0:
      answer = a + b;
      printf("%d + %d = ?\n", a, b);
      break;
    case 1:
      answer = a - b;
      printf("%d - %d = ?\n", a, b);
      break;
    case 2:
      answer = a * b;
      printf("%d * %d = ?\n", a, b);
      break;
    case 3:
      answer = a / b;
      printf("%d / %d = ?\n", a, b);
      break;
  }

  // read in user answer
  scanf("%d", &user_answer);

  // keep asking user for answer until they get it correct
  while (user_answer != answer) {
    printf("Incorrect. Please try again.\n");
    scanf("%d", &user_answer);
  }

  printf("Correct!\n");
  
  return 0;
}