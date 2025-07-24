//FormAI DATASET v1.0 Category: Math exercise ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  srand(time(NULL));  // seed the random number generator
  int num1 = rand() % 101;  // generate a random number between 0 and 100
  int num2 = rand() % 101;  // generate a second random number between 0 and 100

  printf("What is the product of %d and %d?\n", num1, num2);  // prompt the user for the answer
  int answer;
  scanf("%d", &answer);  // read in the user's answer

  int correct_answer = num1 * num2;  // calculate the correct answer

  if (answer == correct_answer) {  // compare the user's answer to the correct answer
    printf("Congratulations, you got the right answer!\n");
  } else if (answer < 0) {  // check if the user's input is negative
    printf("Invalid input: the answer cannot be negative.\n");
  } else {
    printf("Sorry, that is incorrect. The correct answer is: %d\n", correct_answer);
  }

  return 0;
}