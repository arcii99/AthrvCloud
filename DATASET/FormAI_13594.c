//FormAI DATASET v1.0 Category: Dice Roller ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to roll a dice and return the result
int roll_dice(){
  return (rand() % 6) + 1;
}

int main(){
  int num_rolls, i;
  
  //Seeding the random number generator
  srand(time(0));
  
  printf("Welcome to the Dice Roller!\n\n");
  
  //Prompt the user for the number of rolls they want to perform
  printf("How many times would you like to roll the dice? ");
  scanf("%d", &num_rolls);
  
  printf("\nRolling the dice %d times...\n\n", num_rolls);
  
  //Perform the rolls and print the results
  for(i=1; i<=num_rolls; i++){
    printf("Roll %d: %d\n", i, roll_dice());
  }
  
  printf("\nFinished rolling the dice!\n");
  
  return 0;
}