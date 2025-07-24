//FormAI DATASET v1.0 Category: Dice Roller ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice(int sides){ //function to roll a single dice with number of sides provided as an argument
  return rand()%sides +1;
}

int main(){
  int diceNum, sides, i;
  char reroll;
  srand(time(NULL));

  printf("***Dice Roller***\n");

  do{
    printf("\nEnter the number of dice to roll: ");
    scanf("%d", &diceNum);

    printf("Enter the number of sides for the dice: ");
    scanf("%d", &sides);

    printf("\nRolling %d dice with %d sides:\n", diceNum, sides);

    int total = 0;
    for(i=1; i<=diceNum; i++){
      int roll = rollDice(sides);
      printf("Dice %d: %d\n", i, roll);
      total += roll;
    }

    printf("\nTotal: %d\n\n", total);

    printf("Would you like to roll again? (y/n): "); //option to reroll with same dice and sides
    scanf(" %c", &reroll);

  } while(reroll == 'y' || reroll == 'Y');

  printf("\nThank you for using our Dice Roller!\n");

  return 0;
}