//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Rogue-like game with procedural generation

// Function to generate random numbers between min and max
int rand_range(int min, int max) {
  return rand() % (max - min + 1) + min;
}

// Function to generate a random map
void generate_map(int map[][20], int height, int width) {
  int i, j;

  // Set all cells to 0
  for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
      map[i][j] = 0;
    }
  }

  // Randomly place walls
  for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
      if (rand_range(0, 100) < 40) {
        map[i][j] = 1;
      }
    }
  }

  // Randomly place player
  int player_x = rand_range(0, width - 1);
  int player_y = rand_range(0, height - 1);
  map[player_y][player_x] = 2;

  // Randomly place goal
  int goal_x = rand_range(0, width - 1);
  int goal_y = rand_range(0, height - 1);
  while (goal_x == player_x && goal_y == player_y) {
    goal_x = rand_range(0, width - 1);
    goal_y = rand_range(0, height - 1);
  }
  map[goal_y][goal_x] = 3;
}

// Function to print the map
void print_map(int map[][20], int height, int width) {
  int i, j;

  for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
      switch (map[i][j]) {
        case 0:
          printf(".");
          break;
        case 1:
          printf("#");
          break;
        case 2:
          printf("@");
          break;
        case 3:
          printf("$");
          break;
      }
    }
    printf("\n");
  }
}

// Main function
int main() {
  int map[20][20];
  int height = 10;
  int width = 10;

  // Seed the random number generator
  srand(time(0));

  // Generate the map
  generate_map(map, height, width);

  // Print the map
  print_map(map, height, width);

  return 0;
}