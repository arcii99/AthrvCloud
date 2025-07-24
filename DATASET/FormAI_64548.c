//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // seed the random number generator with current time

  int playerHealth = 100; // player's initial health
  int ghostHealth = 50; // ghost's initial health

  printf("Welcome to the Haunted House Simulator!\n");
  printf("You are on a mission to explore a haunted house and defeat the ghost who resides within.\n");
  printf("You will start with 100 health and the ghost will start with 50 health.\n");
  printf("You will take turns attacking each other until someone's health drops to 0.\n");
  printf("Let the game begin!\n");

  while (1) {
    // player's turn
    int playerDamage = rand() % 20 + 1; // generate a random damage between 1 and 20
    ghostHealth -= playerDamage; // deduct the damage from ghost's health
    printf("You attacked the ghost and dealt %d damage. The ghost's health is now %d.\n", playerDamage, ghostHealth);

    if (ghostHealth <= 0) {
      printf("Congratulations! You have defeated the ghost and won the game!\n");
      printf("Your health: %d\n", playerHealth);
      printf("Ghost's health: %d\n", ghostHealth);
      break;
    }

    // ghost's turn
    int ghostDamage = rand() % 15 + 1; // generate a random damage between 1 and 15
    playerHealth -= ghostDamage; // deduct the damage from player's health
    printf("The ghost attacked you and dealt %d damage. Your health is now %d.\n", ghostDamage, playerHealth);

    if (playerHealth <= 0) {
      printf("Game over! You have been defeated by the ghost.\n");
      printf("Your health: %d\n", playerHealth);
      printf("Ghost's health: %d\n", ghostHealth);
      break;
    }
  }

  return 0;
}