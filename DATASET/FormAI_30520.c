//FormAI DATASET v1.0 Category: Math exercise ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int num1, num2, op, answer, user_answer;
  srand(time(0)); // Seed the random generator

  printf("*** Welcome to the Math Exercise Program! ***\n");
  printf("You will be given ten math problems to solve.\n");
  printf("Are you ready? Let's begin!\n\n");

  for(int i=1; i<=10; i++){
    num1 = rand() % 10 + 1; // Generate a random number from 1 to 10
    num2 = rand() % 10 + 1;
    op = rand() % 4; // Generate a random operation to perform

    switch(op) {
      case 0:
        printf("%d + %d = ", num1, num2);
        answer = num1 + num2;
        break;
      case 1:
        printf("%d - %d = ", num1, num2);
        answer = num1 - num2;
        break;
      case 2:
        printf("%d * %d = ", num1, num2);
        answer = num1 * num2;
        break;
      case 3:
        printf("%d / %d = ", num1 * num2, num2); // Ensure division is whole
        answer = num1;
        break;
    }

    scanf("%d", &user_answer);

    if(user_answer == answer){
      printf("Correct!\n\n");
    } else {
      printf("Incorrect. The correct answer is %d.\n\n", answer);
    }
  }

  printf("You completed the exercise! Good job!\n");

  return 0;
}