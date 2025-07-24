//FormAI DATASET v1.0 Category: Game ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAP_SIZE 20
#define MAX_SUPPLIES 10

// Function declarations
void printMap(char map[MAP_SIZE][MAP_SIZE], int playerRow, int playerCol);
void generateSupplies(char map[MAP_SIZE][MAP_SIZE], int numSupplies);
bool checkWinCondition(char map[MAP_SIZE][MAP_SIZE], int numSupplies, int playerRow, int playerCol);

int main(void) {
  // Seed the random number generator with the current time
  srand(time(NULL));

  char map[MAP_SIZE][MAP_SIZE];
  int playerRow = MAP_SIZE / 2;
  int playerCol = MAP_SIZE / 2;
  int numSupplies = 0;

  // Initialize the map to all empty spaces
  for (int i = 0; i < MAP_SIZE; i++) {
    for (int j = 0; j < MAP_SIZE; j++) {
      map[i][j] = ' ';
    }
  }

  // Generate some supplies on the map
  generateSupplies(map, MAX_SUPPLIES);

  // Main game loop
  while (true) {
    // Print the map and player position
    printMap(map, playerRow, playerCol);
    printf("Supplies: %d\n", numSupplies);

    // Check for win condition
    if (checkWinCondition(map, MAX_SUPPLIES, playerRow, playerCol)) {
      printf("You have collected all the supplies and survived!\n");
      break;
    }

    // Get user input
    char input;
    printf("Move (w,a,s,d): ");
    scanf(" %c", &input);
    printf("\n");

    // Update player position based on user input
    switch (input) {
      case 'w':
        if (playerRow > 0) {
          playerRow--;
        }
        break;
      case 'a':
        if (playerCol > 0) {
          playerCol--;
        }
        break;
      case 's':
        if (playerRow < MAP_SIZE - 1) {
          playerRow++;
        }
        break;
      case 'd':
        if (playerCol < MAP_SIZE - 1) {
          playerCol++;
        }
        break;
      default:
        printf("Invalid input!\n");
        break;
    }

    // Check for supplies on the current tile and collect them
    if (map[playerRow][playerCol] == 'S') {
      printf("You found some supplies!\n");
      map[playerRow][playerCol] = ' ';
      numSupplies++;
    }
  }

  return 0;
}

/**
 * Print the map with the player position highlighted.
 */
void printMap(char map[MAP_SIZE][MAP_SIZE], int playerRow, int playerCol) {
  for (int i = 0; i < MAP_SIZE; i++) {
    for (int j = 0; j < MAP_SIZE; j++) {
      if (i == playerRow && j == playerCol) {
        printf("@");
      } else {
        printf("%c", map[i][j]);
      }
    }
    printf("\n");
  }
}

/**
 * Generate a random number of supplies at random positions on the map.
 */
void generateSupplies(char map[MAP_SIZE][MAP_SIZE], int numSupplies) {
  for (int i = 0; i < numSupplies; i++) {
    int row = rand() % MAP_SIZE;
    int col = rand() % MAP_SIZE;
    if (map[row][col] == ' ') {
      map[row][col] = 'S';
    } else {
      i--; // Retry if there's already something on this tile
    }
  }
}

/**
 * Check if the player has collected all the supplies and survived.
 */
bool checkWinCondition(char map[MAP_SIZE][MAP_SIZE], int numSupplies, int playerRow, int playerCol) {
  if (numSupplies == MAX_SUPPLIES && map[playerRow][playerCol] == 'X') {
    return true;
  }
  return false;
}