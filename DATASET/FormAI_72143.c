//FormAI DATASET v1.0 Category: Educational ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAP_SIZE 10
#define MAX_ENEMIES 5
#define MAX_MOVES 10

enum TileType {
  EMPTY,
  WALL,
  ENEMY,
  PLAYER
};

struct Tile {
  enum TileType type;
  bool is_visible;
  bool is_visited;
  bool is_trapped;
};

struct Point {
  int x;
  int y;
};

void clear_screen() {
  system("clear");
}

void print_map(struct Tile map[MAP_SIZE][MAP_SIZE], struct Point player) {
  for(int i = 0; i < MAP_SIZE; i++) {
    for(int j = 0; j < MAP_SIZE; j++) {
      if(i == player.y && j == player.x) {
        printf("P ");
      } else if(!map[i][j].is_visible) {
        printf("? ");
      } else if(map[i][j].is_trapped) {
        printf("* ");
      } else {
        switch(map[i][j].type) {
          case WALL:
            printf("# ");
            break;
          case ENEMY:
            printf("E ");
            break;
          default:
            printf(". ");
            break;
        }
      }
    }
    printf("\n");
  }
}

bool is_in_map(int x, int y) {
  return x >= 0 && x < MAP_SIZE && y >= 0 && y < MAP_SIZE;
}

int main() {
  struct Tile map[MAP_SIZE][MAP_SIZE] = {0};
  struct Point player = {0};
  struct Point enemies[MAX_ENEMIES] = {{0}};
  srand(time(NULL));

  // Generate player position
  player.x = rand() % MAP_SIZE;
  player.y = rand() % MAP_SIZE;

  // Generate walls
  for(int i = 0; i < MAP_SIZE; i += (rand() % 2 + 1)) {
    map[i][0].type = WALL;
    map[i][MAP_SIZE - 1].type = WALL;
  }
  for(int i = 0; i < MAP_SIZE; i += (rand() % 2 + 1)) {
    map[0][i].type = WALL;
    map[MAP_SIZE - 1][i].type = WALL;
  }

  // Generate enemies
  int num_enemies = rand() % MAX_ENEMIES + 1;
  for(int i = 0; i < num_enemies; i++) {
    enemies[i].x = rand() % MAP_SIZE;
    enemies[i].y = rand() % MAP_SIZE;
    map[enemies[i].y][enemies[i].x].type = ENEMY;
  }

  // Game loop
  int moves_left = MAX_MOVES;
  while(moves_left > 0) {
    clear_screen();
    printf("Moves left: %d\n", moves_left);
    print_map(map, player);

    struct Point next_pos = {0};
    printf("Enter next move (WASD): ");
    char move = getchar();
    getchar();
    switch(move) {
      case 'w':
        next_pos.y = player.y - 1;
        break;
      case 'a':
        next_pos.x = player.x - 1;
        break;
      case 's':
        next_pos.y = player.y + 1;
        break;
      case 'd':
        next_pos.x = player.x + 1;
        break;
    }

    if(!is_in_map(next_pos.x, next_pos.y)) {
      continue;
    }

    if(map[next_pos.y][next_pos.x].type == WALL) {
      continue;
    }

    player = next_pos;
    moves_left--;

    // Check for enemy encounters
    for(int i = 0; i < num_enemies; i++) {
      if(enemies[i].x == player.x && enemies[i].y == player.y) {
        map[enemies[i].y][enemies[i].x].is_trapped = true;
      }
    }

    // Reveal nearby tiles
    for(int i = player.y - 1; i <= player.y + 1; i++) {
      for(int j = player.x - 1; j <= player.x + 1; j++) {
        if(is_in_map(j, i)) {
          map[i][j].is_visible = true;
        }
      }
    }
  }

  // Game over
  printf("Game over!\n");
  print_map(map, player);

  return 0;
}