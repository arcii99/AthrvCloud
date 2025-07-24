//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 30
#define HEIGHT 20

int dungeon[HEIGHT][WIDTH];

void init_dungeon()
{
  int x, y;
  for (y = 0; y < HEIGHT; y++) {
    for (x = 0; x < WIDTH; x++) {
      dungeon[y][x] = 0;
    }
  }
}

void print_dungeon()
{
  int x, y;
  for (y = 0; y < HEIGHT; y++) {
    for (x = 0; x < WIDTH; x++) {
      if (dungeon[y][x] == 1) {
        printf("#");
      }
      else {
        printf(".");
      }
    }
    printf("\n");
  }
}

void generate_dungeon()
{
  srand(time(NULL));
  int x, y;
  for (y = 0; y < HEIGHT; y++) {
    for (x = 0; x < WIDTH; x++) {
      if (rand() % 100 < 40) {
        dungeon[y][x] = 1;
      }
      else {
        dungeon[y][x] = 0;
      }
    }
  }
}

int main()
{
  init_dungeon();
  generate_dungeon();
  print_dungeon();
  return 0;
}