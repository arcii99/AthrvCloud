//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 20
#define ROOM_MIN 3
#define ROOM_MAX 8

typedef enum { wall, floor } tile_t;

tile_t Map[MAP_SIZE][MAP_SIZE];

void clear_map(void)
{
  for (int i = 0; i < MAP_SIZE; i++) {
    for (int j = 0; j < MAP_SIZE; j++) {
      Map[i][j] = wall;
    }
  }
}

void print_map(void)
{
  for (int i = 0; i < MAP_SIZE; i++) {
    for (int j = 0; j < MAP_SIZE; j++) {
      if (Map[i][j] == wall) {
        printf("#");
      } else {
        printf(".");
      }
    }
    printf("\n");
  }
}

int is_room_valid(int lt_x, int lt_y, int rb_x, int rb_y)
{
  for (int i = lt_x; i <= rb_x; i++) {
    for (int j = lt_y; j <= rb_y; j++) {
      if (Map[i][j] == floor) {
        return 0;
      }
    }
  }
  return 1;
}

void draw_room(int lt_x, int lt_y, int rb_x, int rb_y)
{
  for (int i = lt_x; i <= rb_x; i++) {
    for (int j = lt_y; j <= rb_y; j++) {
      Map[i][j] = floor;
    }
  }
}

void generate_dungeon(int num_rooms)
{
  for (int i = 0; i < num_rooms; i++) {
    int room_width = rand() % (ROOM_MAX - ROOM_MIN + 1) + ROOM_MIN;
    int room_height = rand() % (ROOM_MAX - ROOM_MIN + 1) + ROOM_MIN;
    int lt_x = rand() % (MAP_SIZE - room_width);
    int lt_y = rand() % (MAP_SIZE - room_height);
    int rb_x = lt_x + room_width - 1;
    int rb_y = lt_y + room_height - 1;

    if (is_room_valid(lt_x, lt_y, rb_x, rb_y)) {
      draw_room(lt_x, lt_y, rb_x, rb_y);
    }
  }
}

int main(void)
{
  srand(time(NULL));
  clear_map();
  generate_dungeon(5);
  print_map();
  return 0;
}