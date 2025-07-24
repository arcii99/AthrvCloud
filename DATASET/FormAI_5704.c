//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // allows for random generation
  int playerHealth = 100; // player starting health
  int ghostHealth = 50; // ghost starting health
  int ghostAttack; // ghost attack damage
  int playerAttack; // player attack damage
  int round = 0; // keeps track of what round we are on
  
  printf("Welcome to the Haunted House Simulator!\n\n");

  while (playerHealth > 0 && ghostHealth > 0) { // while both are alive, keep battling
    round++; // increment each round
    printf("\nRound %d:\n", round);
    ghostAttack = rand() % 10 + 5; // ghost damage range
    playerAttack = rand() % 15 + 10; // player damage range

    printf("The ghost attacks and deals %d damage to you!\n", ghostAttack);
    playerHealth -= ghostAttack; // deduct health from player
    printf("You attack the ghost and deal %d damage!\n", playerAttack);
    ghostHealth -= playerAttack; // deduct health from ghost

    printf("\nYour health: %d\nGhost health: %d\n", playerHealth, ghostHealth);
  }

  if (playerHealth <= 0) {
    printf("\nThe ghost won! You have been defeated.\n");
  } else {
    printf("\nYou won! The ghost has been defeated.\n");
  }

  return 0;
}