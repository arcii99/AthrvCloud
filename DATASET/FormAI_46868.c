//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  srand(time(NULL)); // Seed the random number generator
  
  int playerHealth = 100;
  int alienHealth = 50;

  int roundNumber = 1;

  printf("Welcome to Procedural Space Adventure!\n");
  printf("You are a space explorer on a mission to find new planets.\n");
  printf("Suddenly, you are attacked by an alien! You must fight for your life.\n");

  while (playerHealth > 0 && alienHealth > 0) {

    printf("\nRound %d\n", roundNumber);
    // Player attacks
    int playerAttack = rand() % 20 + 10; // Random number between 10-30
    printf("You attack the alien for %d damage!\n", playerAttack);
    alienHealth -= playerAttack;

    // Check if alien survived
    if (alienHealth <= 0) {
      printf("\nYou defeated the alien! Congratulations, you survived your first space battle!\n");
      break;
    }

    // Alien attacks
    int alienAttack = rand() % 15 + 5; // Random number between 5-20
    printf("The alien attacks you for %d damage!\n", alienAttack);
    playerHealth -= alienAttack;

    // Check if player survived
    if (playerHealth <= 0) {
      printf("\nYou were defeated by the alien. Better luck next time!\n");
      break;
    }

    // Display current health status
    printf("\nCurrent Health:\n");
    printf("You: %d\n", playerHealth);
    printf("Alien: %d\n", alienHealth);

    roundNumber++;
  }

  return 0;
}