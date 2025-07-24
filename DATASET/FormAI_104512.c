//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10 // number of rows in the dungeon
#define COLS 20 // number of columns in the dungeon

char dungeon[ROWS][COLS]; // stores the dungeon map
int playerX, playerY; // stores the player's current position

// function to initialize the dungeon with random values
void initDungeon() {
  // seed the random number generator
  srand(time(NULL));
  
  // fill the dungeon with random floor/wall tiles
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      if (i == 0 || i == ROWS-1 || j == 0 || j == COLS-1) {
        dungeon[i][j] = '#'; // boundary walls
      } else if (rand() % 100 < 40) {
        dungeon[i][j] = '#'; // randomly generate walls 40% of the time
      } else {
        dungeon[i][j] = '.'; // otherwise generate floors
      }
    }
  }
  
  // place the player randomly on a floor tile
  while (1) {
    int x = rand() % (COLS-2) + 1;
    int y = rand() % (ROWS-2) + 1;
    if (dungeon[y][x] == '.') {
      playerX = x;
      playerY = y;
      break;
    }
  }
}

// function to draw the dungeon map and display the player's position
void drawDungeon() {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      if (i == playerY && j == playerX) {
        printf("@");
      } else {
        printf("%c", dungeon[i][j]);
      }
    }
    printf("\n");
  }
}

// function to update the player's position based on input
void updatePlayer(char input) {
  int dx = 0, dy = 0;
  switch (input) {
    case 'w': // move up
      dy = -1;
      break;
    case 'a': // move left
      dx = -1;
      break;
    case 's': // move down
      dy = 1;
      break;
    case 'd': // move right
      dx = 1;
      break;
  }
  if (dungeon[playerY+dy][playerX+dx] == '.') {
    playerX += dx;
    playerY += dy;
  }
}

int main() {
  initDungeon(); // initialize the dungeon with random values
  char input;
  while (1) {
    system("clear"); // clear the screen
    drawDungeon(); // draw the dungeon map and display the player's position
    input = getchar(); // get user input
    updatePlayer(input); // update the player's position based on input
  }
  return 0;
}