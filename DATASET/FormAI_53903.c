//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 20
#define PLAYER_CHAR 'P'
#define ENEMY_CHAR 'E'
#define LOOT_CHAR '$'
#define WALL_CHAR '#'
#define FLOOR_CHAR '.'

typedef struct {
  int x;
  int y;
} XY_Position;

char map[MAP_SIZE][MAP_SIZE];

// Initialize the map with walls and floors
void init_map() {
  // Set all tiles to walls
  for (int i = 0; i < MAP_SIZE; i++) {
    for (int j = 0; j < MAP_SIZE; j++) {
      map[i][j] = WALL_CHAR;
    }
  }

  // Add floors in the middle
  for (int i = 1; i < MAP_SIZE - 1; i++) {
    for (int j = 1; j < MAP_SIZE - 1; j++) {
      map[i][j] = FLOOR_CHAR;
    }
  }
}

// Place the player's character on the map
void place_player(XY_Position *player_pos) {
  // Place the player in the top left corner
  player_pos->x = 1;
  player_pos->y = 1;
  map[player_pos->y][player_pos->x] = PLAYER_CHAR;
}

// Check if a given position is inside the playable area
int is_within_map(XY_Position *pos) {
  return pos->x >= 0 && pos->x < MAP_SIZE &&
         pos->y >= 0 && pos->y < MAP_SIZE;
}

// Check if a given position is a floor tile
int is_floor(XY_Position *pos) {
  return map[pos->y][pos->x] == FLOOR_CHAR;
}

// Check if a given position is a loot tile
int is_loot(XY_Position *pos) {
  return map[pos->y][pos->x] == LOOT_CHAR;
}

// Check if a given position is an enemy tile
int is_enemy(XY_Position *pos) {
  return map[pos->y][pos->x] == ENEMY_CHAR;
}

// Move the player in a given direction
void move_player(XY_Position *player_pos, int dx, int dy) {
  XY_Position new_pos = {player_pos->x + dx, player_pos->y + dy};

  // Check if the new position is within the map and a floor tile
  if (is_within_map(&new_pos) && is_floor(&new_pos)) {
    // Check if there's loot at the new position
    if (is_loot(&new_pos)) {
      printf("You found loot!\n");
    }

    // Move the player
    map[player_pos->y][player_pos->x] = FLOOR_CHAR;
    player_pos->x += dx;
    player_pos->y += dy;
    map[player_pos->y][player_pos->x] = PLAYER_CHAR;
  }
}

// Spawn enemies randomly on the map
void spawn_enemies() {
  int num_enemies = rand() % 10 + 5;

  for (int i = 0; i < num_enemies; i++) {
    XY_Position enemy_pos = {rand() % (MAP_SIZE - 2) + 1, rand() % (MAP_SIZE - 2) + 1};

    // Check if the position is a floor tile
    if (is_floor(&enemy_pos)) {
      map[enemy_pos.y][enemy_pos.x] = ENEMY_CHAR;
    }
  }
}

// Spawn loot randomly on the map
void spawn_loot() {
  int num_loot = rand() % 5 + 1;

  for (int i = 0; i < num_loot; i++) {
    XY_Position loot_pos = {rand() % (MAP_SIZE - 2) + 1, rand() % (MAP_SIZE - 2) + 1};

    // Check if the position is a floor tile
    if (is_floor(&loot_pos)) {
      map[loot_pos.y][loot_pos.x] = LOOT_CHAR;
    }
  }
}

// Print the current state of the map
void print_map() {
  for (int i = 0; i < MAP_SIZE; i++) {
    for (int j = 0; j < MAP_SIZE; j++) {
      printf("%c", map[i][j]);
    }
    printf("\n");
  }
}

int main() {
  // Seed the RNG
  srand(time(NULL));

  // Initialize the map, place the player, and spawn enemies and loot
  init_map();

  XY_Position player_pos;
  place_player(&player_pos);

  spawn_enemies();
  spawn_loot();

  // Main game loop
  while (1) {
    // Print the map and ask for input
    print_map();
    printf("Move (WASD): ");

    // Read input and move the player
    char input;
    scanf(" %c", &input);
    switch (input) {
      case 'w':
        move_player(&player_pos, 0, -1);
        break;
      case 'a':
        move_player(&player_pos, -1, 0);
        break;
      case 's':
        move_player(&player_pos, 0, 1);
        break;
      case 'd':
        move_player(&player_pos, 1, 0);
        break;
    }
  }

  return 0;
}