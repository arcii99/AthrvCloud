//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function prototypes
void intro();
void choosePath();
void pathOne();
void pathTwo();
void pathThree();
void battle();
void win();
void lose();

int main() {
  intro();
  choosePath();

  return 0;
}

// Displays the game's introduction
void intro() {
  printf("*** Welcome to the Adventure Game ***\n\n");
  printf("You find yourself standing at a fork on a path.\n");
  printf("You're not sure which way to go.\n");
  printf("Choose your path carefully, as your life depends on it.\n\n");
}

// Allows the player to choose their path
void choosePath() {
  char input[10];
  printf("Which path will you choose? (1, 2, or 3): ");
  fgets(input, 10, stdin);

  if (strcmp(input, "1\n") == 0) {
    pathOne();
  }
  else if (strcmp(input, "2\n") == 0) {
    pathTwo();
  }
  else if (strcmp(input, "3\n") == 0) {
    pathThree();
  }
  else {
    printf("Invalid input. Please try again.\n\n");
    choosePath();
  }
}

// The player chose path one
void pathOne() {
  printf("You have chosen path one.\n");
  printf("As you walk down the path, you hear strange noises in the distance.\n");
  printf("Suddenly, a monster appears and attacks you!\n\n");
  battle();
}

// The player chose path two
void pathTwo() {
  printf("You have chosen path two.\n");
  printf("As you walk down the path, you see a beautiful waterfall.\n");
  printf("You take a moment to admire it and feel refreshed.\n");
  printf("You continue on your journey.\n\n");
  win();
}

// The player chose path three
void pathThree() {
  printf("You have chosen path three.\n");
  printf("As you walk down the path, you come across a pack of wolves.\n");
  printf("They attack you!\n\n");
  battle();
}

// The battle sequence
void battle() {
  int enemyHealth = 20;
  int playerHealth = 20;
  int moves = 0;
  char input[10];

  printf("Battle sequence initiated.\n");
  printf("You have %d health points.\n", playerHealth);

  while (enemyHealth > 0 && playerHealth > 0) {
    printf("Your move. (punch, kick): ");
    fgets(input, 10, stdin);

    if (strcmp(input, "punch\n") == 0) {
      printf("You punched the enemy.\n");
      enemyHealth -= 5;
      moves++;
    }
    else if (strcmp(input, "kick\n") == 0) {
      printf("You kicked the enemy.\n");
      enemyHealth -= 10;
      playerHealth -= 5;
      moves++;
    }
    else {
      printf("Invalid move. Please try again.\n");
    }

    printf("Enemy health: %d\n", enemyHealth);
    printf("Your health: %d\n\n", playerHealth);

    if (enemyHealth > 0) {
      printf("Enemy's turn.\n");
      playerHealth -= 5;
      printf("Your health: %d\n\n", playerHealth);
    }
  }

  if (enemyHealth <= 0) {
    printf("You have defeated the enemy in %d moves!\n\n", moves);
    win();
  }
  else {
    printf("You have been defeated by the enemy.\n\n");
    lose();
  }
}

// The player wins the game
void win() {
  printf("Congratulations, you have won the game!\n\n");
}

// The player loses the game
void lose() {
  printf("Game over. Better luck next time!\n\n");
}