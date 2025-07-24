//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 20
#define MAX_ROOMS 6

typedef struct Room {
  int x;
  int y;
  int width;
  int height;
} Room;

static char dungeon[ROWS][COLS];
static Room rooms[MAX_ROOMS];

void printDungeon() {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      printf("%c", dungeon[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void initDungeon() {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      dungeon[i][j] = '#';
    }
  }
}

void addRooms() {
  srand(time(NULL));
  for (int i = 0; i < MAX_ROOMS; i++) {
    int x = rand() % COLS;
    int y = rand() % ROWS;
    int width = (rand() % 7) + 5;
    int height = (rand() % 5) + 3;
    rooms[i] = (Room) { x, y, width, height };
    for (int j = y; j < y + height && j < ROWS; j++) {
      for (int k = x; k < x + width && k < COLS; k++) {
        if (dungeon[j][k] == '.') {
          return addRooms();
        }
      }
    }
    for (int j = y - 1; j < y + height + 1 && j < ROWS; j++) {
      for (int k = x - 1; k < x + width + 1 && k < COLS; k++) {
        if (dungeon[j][k] != '#' && (j != y - 1 || k != x - 1) && (j != y - 1 || k != x + width) && (j != y + height || k != x - 1) && (j != y + height || k != x + width)) {
          dungeon[j][k] = '.';
        }
      }
    }
  }
}

int main() {
  initDungeon();
  addRooms();
  printDungeon();
}