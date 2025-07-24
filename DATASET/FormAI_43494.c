//FormAI DATASET v1.0 Category: Dice Roller ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
  int dice, i;
  char response[10];

  printf("Welcome to the Dice Roller Program!\n");
  
  do {
    printf("How many dice would you like to roll? ");
    scanf("%d", &dice);
    printf("\n");

    srand(time(0)); //seed the random number generator with current time

    printf("Rolling ");
    if (dice > 1) printf("%d dice...\n\n", dice);
    else printf("a die...\n\n");

    for (i=1; i<=dice; i++) {
      printf("Dice %d: %d\n", i, (rand() % 6) + 1); //generate random numbers between 1-6
    }

    printf("\nWould you like to roll again? (Yes/No) ");
    scanf("%s", response);
    printf("\n");

  } while (response[0] == 'Y' || response[0] == 'y'); //keep rolling until user says no

  printf("Thank you for using the Dice Roller Program! Goodbye!\n");

  return 0;
}