//FormAI DATASET v1.0 Category: Math exercise ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // seeding the random number generator with system time

  int num1 = rand() % 50 + 1; // generates a random number between 1 and 50
  int num2 = rand() % 50 + 1;

  printf("What is the sum of %d and %d?\n", num1, num2);

  int answer;
  scanf("%d", &answer);

  int sum = num1 + num2;

  if (answer == sum) {
    printf("Congratulations! %d is the correct answer.\n", answer);
  } else {
    printf("Sorry, %d is incorrect. The correct answer is %d.\n", answer, sum);
  }

  return 0;
}