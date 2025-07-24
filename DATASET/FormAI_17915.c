//FormAI DATASET v1.0 Category: Dice Roller ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int num, x;
  srand(time(NULL));

  printf("Enter the number of dice to roll: "); // prompt user for input
  scanf("%d", &num);

  if(num <= 0) { // if user enters 0 or negative number
    printf("Please enter a positive number.\n");
    return 0; // exit program
  }

  printf("\nRolling...\n\n");

  for(int i=1; i<=num; i++) {
    x = (rand() % 6) + 1; // generate random number between 1 and 6
    printf("Die %d: ", i);

    for(int j=1; j<=x; j++) { // print out symbols for each roll of die
      switch(rand() % 5) {
        case 0:
          printf("** ");
          break;
        case 1:
          printf("() ");
          break;
        case 2:
          printf(">< ");
          break;
        case 3:
          printf("++ ");
          break;
        case 4:
          printf("~~ ");
          break;
      }
    }

    printf("\n");
  }

  return 0; // exit program
}