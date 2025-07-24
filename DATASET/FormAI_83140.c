//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 80
#define MAP_HEIGHT 24

// Define structs for player, enemy and map
typedef struct {
  int x;
  int y;
  int hp;
  int damage;
} Player;

typedef struct {
  int x;
  int y;
  int hp;
  int damage;
} Enemy;

typedef struct {
  int width;
  int height;
  char map[MAP_HEIGHT][MAP_WIDTH];
} Map;

void print_map(Map *map, Player *player, Enemy *enemy) {
  // Print the map with player and enemy positions
  int i, j;
  for (i = 0; i < map->height; i++) {
    for (j = 0; j < map->width; j++) {
      if (i == player->y && j == player->x) {
        printf("@");
      } else if (i == enemy->y && j == enemy->x) {
        printf("E");
      } else {
        printf("%c", map->map[i][j]);
      }
    }
    printf("\n");
  }
}

void generate_map(Map *map) {
  // Generate the map with random walls
  srand(time(NULL));
  int i, j;
  for (i = 0; i < map->height; i++) {
    for (j = 0; j < map->width; j++) {
      if (i == 0 || j == 0 || i == map->height - 1 || j == map->width - 1) {
        map->map[i][j] = '#';
      } else {
        map->map[i][j] = rand() % 100 < 40 ? '#' : '.';
      }
    }
  }
}

int main() {
  // Initialize player and enemy positions
  Player player = {2, 2, 10, 2};
  Enemy enemy = {MAP_WIDTH - 3, MAP_HEIGHT - 3, 5, 1};
  Map map = {MAP_WIDTH, MAP_HEIGHT};

  // Generate the map with walls
  generate_map(&map);

  // Print the initial map
  print_map(&map, &player, &enemy);

  // Game loop
  char input;
  int gameover = 0;
  while (!gameover) {
    // Get user input
    input = getchar();

    // Update player position based on input
    switch (input) {
      case 'w':
        if (map.map[player.y - 1][player.x] != '#') {
          player.y--;
        }
        break;
      case 'a':
        if (map.map[player.y][player.x - 1] != '#') {
          player.x--;
        }
        break;
      case 's':
        if (map.map[player.y + 1][player.x] != '#') {
          player.y++;
        }
        break;
      case 'd':
        if (map.map[player.y][player.x + 1] != '#') {
          player.x++;
        }
        break;
    }

    // Update enemy position towards player
    if (enemy.y > player.y) {
      enemy.y--;
    } else if (enemy.y < player.y) {
      enemy.y++;
    }

    if (enemy.x > player.x) {
      enemy.x--;
    } else if (enemy.x < player.x) {
      enemy.x++;
    }

    // Print the updated map with player and enemy positions
    system("clear");
    print_map(&map, &player, &enemy);

    // Check for collision with enemy
    if (player.y == enemy.y && player.x == enemy.x) {
      player.hp -= enemy.damage;
      printf("You were attacked by the enemy. You lost %d hp\n", enemy.damage);
      printf("You have %d hp remaining\n", player.hp);
      if (player.hp <= 0) {
        printf("Game Over\n");
        gameover = 1;
      }
    }

    // Check for victory
    if (player.y == MAP_HEIGHT - 3 && player.x == MAP_WIDTH - 3) {
      printf("Congratulations! You have reached the end of the game\n");
      gameover = 1;
    }
  }

  return 0;
}