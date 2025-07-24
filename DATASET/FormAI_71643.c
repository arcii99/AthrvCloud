//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 20
#define MAP_HEIGHT 10
#define ENEMY_COUNT 5
#define MAX_HEALTH 20

typedef enum {
  FLOOR,
  WALL,
  TREASURE,
  ENEMY
} TileType;

typedef struct {
  int x;
  int y;
  TileType type;
} Tile;

typedef struct {
  char name[20];
  int health;
  int damage;
  int x;
  int y;
} Enemy;

void generate_map(Tile map[MAP_HEIGHT][MAP_WIDTH]) {
  int x, y, i;
  // Generate walls
  for (y = 0; y < MAP_HEIGHT; y++) {
    for (x = 0; x < MAP_WIDTH; x++) {
      if (x == 0 || y == 0 || x == MAP_WIDTH-1 || y == MAP_HEIGHT-1) {
        map[y][x].type = WALL;
      } else {
        map[y][x].type = FLOOR;
      }
    }
  }
  // Generate treasure
  x = rand() % (MAP_WIDTH - 2) + 1;
  y = rand() % (MAP_HEIGHT - 2) + 1;
  map[y][x].type = TREASURE;
  // Generate enemies
  for (i = 0; i < ENEMY_COUNT; i++) {
    Enemy e;
    sprintf(e.name, "Enemy %d", i+1);
    e.health = rand() % (MAX_HEALTH - 1) + 1;
    e.damage = rand() % 5 + 1;
    e.x = rand() % (MAP_WIDTH - 2) + 1;
    e.y = rand() % (MAP_HEIGHT - 2) + 1;
    map[e.y][e.x].type = ENEMY;
  }
}

void print_map(Tile map[MAP_HEIGHT][MAP_WIDTH]) {
  int x, y;
  for (y = 0; y < MAP_HEIGHT; y++) {
    for (x = 0; x < MAP_WIDTH; x++) {
      switch (map[y][x].type) {
        case FLOOR:
          printf(".");
          break;
        case WALL:
          printf("#");
          break;
        case TREASURE:
          printf("$");
          break;
        case ENEMY:
          printf("E");
          break;
      }
    }
    printf("\n");
  }
}

int main() {
  Tile map[MAP_HEIGHT][MAP_WIDTH];
  srand(time(NULL));
  generate_map(map);
  print_map(map);
  return 0;
}