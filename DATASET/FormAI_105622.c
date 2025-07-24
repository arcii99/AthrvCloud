//FormAI DATASET v1.0 Category: Dice Roller ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
  srand(time(0)); // seed the random number generator with current time
  
  int num_dice, num_sides, roll_again;
  
  printf("Welcome to the Dice Roller program!\n\n");
  
  do {
    printf("How many dice would you like to roll? ");
    scanf("%d", &num_dice);
    
    printf("How many sides should the dice have? ");
    scanf("%d", &num_sides);
    
    printf("\nRolling %d %d-sided dice...\n", num_dice, num_sides);
    
    int total = 0;
    
    for(int i=0;i<num_dice;i++) {
      int roll = rand() % num_sides + 1;
      printf("Die %d rolled %d\n", i+1, roll);
      total += roll;
    }
    
    printf("\nTotal: %d\n\n", total);
    
    printf("Roll again? (1 for yes, 0 for no) ");
    scanf("%d", &roll_again);
    
    printf("\n");
    
  } while(roll_again == 1);
  
  printf("Thanks for using the Dice Roller program!");
  
  return 0;
}