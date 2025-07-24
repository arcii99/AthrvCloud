//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 24

#define NUM_ROOMS 10
#define MIN_ROOM_SIZE 5
#define MAX_ROOM_SIZE 15

#define PLAYER '@'
#define WALL '#'
#define FLOOR '.'

#define UP 'w'
#define LEFT 'a'
#define DOWN 's'
#define RIGHT 'd'

void generateDungeon(char dungeon[HEIGHT][WIDTH]) {
  int i, j, k;
  int x, y, width, height;

  // Init the map with walls
  for (i = 0; i < HEIGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      dungeon[i][j] = WALL;
    }
  }

  // Generate rooms
  for (k = 0; k < NUM_ROOMS; k++) {
    width = rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE + 1) + MIN_ROOM_SIZE;
    height = rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE + 1) + MIN_ROOM_SIZE;
    x = rand() % (WIDTH - width - 1) + 1;
    y = rand() % (HEIGHT - height - 1) + 1;

    for (i = y; i < y + height; i++) {
      for (j = x; j < x + width; j++) {
        dungeon[i][j] = FLOOR;
      }
    }
  }

  // Connect rooms with corridors
  for (i = 0; i < NUM_ROOMS - 1; i++) {
    x = rand() % WIDTH;
    y = rand() % HEIGHT;

    while (dungeon[y][x] != FLOOR) {
      x = rand() % WIDTH;
      y = rand() % HEIGHT;
    }

    int x2 = rand() % WIDTH;
    int y2 = rand() % HEIGHT;

    while (dungeon[y2][x2] != FLOOR) {
      x2 = rand() % WIDTH;
      y2 = rand() % HEIGHT;
    }

    // Draw a corridor from (x,y) to (x2,y2)
    while (x != x2) {
      if (x < x2) {
        x++;
      } else {
        x--;
      }

      dungeon[y][x] = FLOOR;
    }

    while (y != y2) {
      if (y < y2) {
        y++;
      } else {
        y--;
      }

      dungeon[y][x] = FLOOR;
    }
  }
}

void printDungeon(char dungeon[HEIGHT][WIDTH]) {
  int i, j;

  for (i = 0; i < HEIGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      putchar(dungeon[i][j]);
    }

    putchar('\n');
  }
}

int main() {
  char dungeon[HEIGHT][WIDTH];
  char input;
  int playerX, playerY;

  // Seed the random number generator
  srand(time(NULL));

  // Generate the dungeon
  generateDungeon(dungeon);

  // Find a starting position for the player
  playerX = rand() % WIDTH;
  playerY = rand() % HEIGHT;

  while (dungeon[playerY][playerX] != FLOOR) {
    playerX = rand() % WIDTH;
    playerY = rand() % HEIGHT;
  }

  // Main game loop
  while (true) {
    // Clear the screen
    system("clear");

    // Print the dungeon
    printDungeon(dungeon);

    // Print the player
    dungeon[playerY][playerX] = PLAYER;

    // Handle the player input
    input = getchar();

    switch (input) {
      case UP:
        if (dungeon[playerY - 1][playerX] == FLOOR) {
          dungeon[playerY][playerX] = FLOOR;
          playerY--;
        }

        break;

      case LEFT:
        if (dungeon[playerY][playerX - 1] == FLOOR) {
          dungeon[playerY][playerX] = FLOOR;
          playerX--;
        }

        break;

      case DOWN:
        if (dungeon[playerY + 1][playerX] == FLOOR) {
          dungeon[playerY][playerX] = FLOOR;
          playerY++;
        }

        break;

      case RIGHT:
        if (dungeon[playerY][playerX + 1] == FLOOR) {
          dungeon[playerY][playerX] = FLOOR;
          playerX++;
        }

        break;

      default:
        break;
    }
  }

  return 0;
}