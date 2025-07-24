//FormAI DATASET v1.0 Category: Dice Roller ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // Seed the random number generator
  int numRolls = 0;
  int numSides = 0;
  
  printf("Welcome to the Dice Roller! How many sides does your die have? ");
  scanf("%d", &numSides);
  printf("And how many times would you like to roll it? ");
  scanf("%d", &numRolls);
  
  printf("\nRolling your %d-sided die %d times...\n\n", numSides, numRolls);
  
  for (int i = 1; i <= numRolls; i++) {
    int roll = rand() % numSides + 1; // Random number between 1 and numSides
    
    printf("Roll #%d: %d\n", i, roll);
    
    if (roll == numSides) {
      printf("Wow, you rolled a max value! That's like finding a needle in a haystack, except the haystack is made of dice and the needle is... also a dice?\n\n");
    } else if (roll == 1) {
      printf("You got the lowest possible roll! But hey, at least it can't get any worse than this, right?\n\n");
    } else if (roll % 2 == 0) {
      printf("Hey, that's an even roll! That's... moderately interesting, I guess. Next!\n\n");
    } else {
      printf("Odd roll! Not quite a jackpot, but not a total loss either. Keep on rollin'!\n\n");
    }
  }
  
  printf("Thanks for using the Dice Roller! Please try again soon, or else the dice might get lonely without you...\n");
  
  return 0;
}