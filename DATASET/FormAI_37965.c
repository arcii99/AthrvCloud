//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 30

// Defining the map and player structs
typedef struct {
  int x, y;
} Position;

typedef struct {
  char symbol;
  Position position;
} Player;

typedef struct {
  char symbol;
  int visited;
} Room;

typedef struct {
  Room rooms[MAP_SIZE][MAP_SIZE];
  Position exit;
} Map;

// Function to print the map
void print_map(Map* map, Player* player) {
  for (int i = 0; i < MAP_SIZE; i++) {
    for (int j = 0; j < MAP_SIZE; j++) {
      if (player->position.x == j && player->position.y == i) {
        printf("%c ", player->symbol);
      } else if (map->rooms[j][i].visited) {
        printf("%c ", map->rooms[j][i].symbol);
      } else {
        printf("# ");
      }
    }
    printf("\n");
  }
}

// Function to randomize the map
void randomize_map(Map* map, Player* player) {
  // Initialize rooms with unvisited walls
  for (int i = 0; i < MAP_SIZE; i++) {
    for (int j = 0; j < MAP_SIZE; j++) {
      map->rooms[j][i].symbol = '#';
      map->rooms[j][i].visited = 0;
    }
  }

  // Randomly place the player
  player->position.x = rand() % MAP_SIZE;
  player->position.y = rand() % MAP_SIZE;

  // Randomly generate rooms
  int num_rooms = (int)(MAP_SIZE * MAP_SIZE * 0.05); // 5% of the map cells
  for (int i = 0; i < num_rooms; i++) {
    int x = rand() % MAP_SIZE;
    int y = rand() % MAP_SIZE;
    if (!map->rooms[x][y].visited) {
      map->rooms[x][y].visited = 1;
      map->rooms[x][y].symbol = '.';
    }
  }

  // Randomly place the exit
  do {
    map->exit.x = rand() % MAP_SIZE;
    map->exit.y = rand() % MAP_SIZE;
  } while (map->exit.x == player->position.x && map->exit.y == player->position.y);
  map->rooms[map->exit.x][map->exit.y].symbol = 'E';
}

int main() {
  srand(time(0)); // Seed the random number generator

  Player player = {'@', {0, 0}};
  Map map;

  randomize_map(&map, &player);
  print_map(&map, &player);

  return 0;
}