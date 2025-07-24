//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print the game world
void printWorld(char world[][80], int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%c", world[i][j]);
    }
    printf("\n");
  }
}

// Function to generate a new game world
void generateWorld(char world[][80], int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      world[i][j] = rand() % 2 == 0 ? '.' : '#';
    }
  }
}

// Function to fill the world with player chars
void addPlayer(char world[][80], int row, int col) {
  world[row][col] = '@';
}

int main() {
  srand(time(NULL)); // Seed the random number generator

  // Declare variables for the game world size and player position
  int rows = 20;
  int cols = 80;
  int playerRow = rows / 2;
  int playerCol = cols / 2;

  // Declare the game world array and generate a new world
  char world[rows][cols];
  generateWorld(world, rows, cols);

  // Add the player to the world
  addPlayer(world, playerRow, playerCol);

  // Print the initial game world
  printWorld(world, rows, cols);

  return 0;
}