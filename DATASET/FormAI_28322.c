//FormAI DATASET v1.0 Category: Educational ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  printf("Welcome to the ridiculous random number generator!\n\n");

  int num1, num2, num3, num4, num5, num6;

  srand(time(NULL));

  num1 = rand() % 101;
  num2 = rand() % 101;
  num3 = rand() % 101;
  num4 = rand() % 101;
  num5 = rand() % 101;
  num6 = rand() % 101;

  printf("Your six lucky numbers are: %d, %d, %d, %d, %d, and %d\n", num1, num2, num3, num4, num5, num6);

  printf("\nNow let's see if you won the lottery!\n\n");

  int lottery1, lottery2, lottery3, lottery4, lottery5, lottery6;

  lottery1 = rand() % 101;
  lottery2 = rand() % 101;
  lottery3 = rand() % 101;
  lottery4 = rand() % 101;
  lottery5 = rand() % 101;
  lottery6 = rand() % 101;

  printf("The winning lottery numbers are: %d, %d, %d, %d, %d, and %d\n", lottery1, lottery2, lottery3, lottery4, lottery5, lottery6);

  int matches = 0;

  if (num1 == lottery1 || num1 == lottery2 || num1 == lottery3 || num1 == lottery4 || num1 == lottery5 || num1 == lottery6) {
    matches++;
  }
  if (num2 == lottery1 || num2 == lottery2 || num2 == lottery3 || num2 == lottery4 || num2 == lottery5 || num2 == lottery6) {
    matches++;
  }
  if (num3 == lottery1 || num3 == lottery2 || num3 == lottery3 || num3 == lottery4 || num3 == lottery5 || num3 == lottery6) {
    matches++;
  }
  if (num4 == lottery1 || num4 == lottery2 || num4 == lottery3 || num4 == lottery4 || num4 == lottery5 || num4 == lottery6) {
    matches++;
  }
  if (num5 == lottery1 || num5 == lottery2 || num5 == lottery3 || num5 == lottery4 || num5 == lottery5 || num5 == lottery6) {
    matches++;
  }
  if (num6 == lottery1 || num6 == lottery2 || num6 == lottery3 || num6 == lottery4 || num6 == lottery5 || num6 == lottery6) {
    matches++;
  }

  if (matches < 3) {
    printf("Sorry, you didn't win the lottery. Better luck next time!\n");
  } else {
    printf("Congratulations! You win the lottery with %d matches!\n", matches);
  }

  return 0;
}