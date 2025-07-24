//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the width and height of the space grid
#define WIDTH 10
#define HEIGHT 10

// Define the type of space object
enum ObjectType {
  EMPTY,
  PLANET,
  ASTEROID,
  ALIEN_SHIP
};

// Define the struct for a space object
struct SpaceObject {
  enum ObjectType type;
  int has_been_visited;
};

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Initialize the space grid
  struct SpaceObject grid[WIDTH][HEIGHT];
  int i, j;
  for (i = 0; i < WIDTH; i++) {
    for (j = 0; j < HEIGHT; j++) {
      grid[i][j].type = rand() % 3 + 1; // Randomly choose a space object type
      grid[i][j].has_been_visited = 0; // Set the has_been_visited flag to false
    }
  }

  // Game loop
  int game_over = 0;
  int player_x = 0;
  int player_y = 0;
  while (!game_over) {
    // Print the space grid
    printf("Space Grid:\n");
    for (i = 0; i < WIDTH; i++) {
      for (j = 0; j < HEIGHT; j++) {
        if (i == player_x && j == player_y) { // Print the player symbol instead of the space object symbol
          printf("@");
        } else if (grid[i][j].has_been_visited) { // Print the space object symbol if it has been visited
          if (grid[i][j].type == PLANET) {
            printf("P");
          } else if (grid[i][j].type == ASTEROID) {
            printf("A");
          } else if (grid[i][j].type == ALIEN_SHIP) {
            printf("S");
          }
        } else { // Print a blank space if the space object has not been visited
          printf(".");
        }
      }
      printf("\n");
    }

    // Prompt the player for their next move
    printf("Enter your next move (N/S/E/W): ");
    char input;
    scanf(" %c", &input);

    // Move the player in the requested direction
    switch (input) {
      case 'N':
        if (player_y > 0) {
          player_y--;
        }
        break;
      case 'S':
        if (player_y < HEIGHT - 1) {
          player_y++;
        }
        break;
      case 'E':
        if (player_x < WIDTH - 1) {
          player_x++;
        }
        break;
      case 'W':
        if (player_x > 0) {
          player_x--;
        }
        break;
    }

    // Check the space object at the player's new location
    if (grid[player_x][player_y].has_been_visited) {
      printf("You have already visited this space object.\n");
    } else {
      grid[player_x][player_y].has_been_visited = 1;
      switch (grid[player_x][player_y].type) {
        case PLANET:
          printf("You have discovered a new planet!\n");
          break;
        case ASTEROID:
          printf("You have encountered an asteroid field!\n");
          break;
        case ALIEN_SHIP:
          printf("You have encountered an alien ship!\n");
          break;
        default:
          printf("You have discovered an empty space.\n");
          break;
      }
    }
  }

  return 0;
}