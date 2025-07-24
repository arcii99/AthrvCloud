//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 20
#define MAP_HEIGHT 10
#define MAX_ENEMIES 5

int player_x, player_y;
int enemies_count = 0;
int map[MAP_HEIGHT][MAP_WIDTH];

void print_map() {
  printf("-------------------\n");
  for(int i = 0; i < MAP_HEIGHT; i++) {
    for(int j = 0; j < MAP_WIDTH; j++) {
      if(i == player_y && j == player_x) {
        printf("O");
        continue;
      }
      if(map[i][j] == 1) {
        printf("X");
      } else {
        printf(".");
      }
    }
    printf("\n");
  }
  printf("-------------------\n");
}

void move_player(char direction) {
  switch(direction) {
    case 'w':
      if(player_y > 0) {
        player_y--;
      }
      break;
    case 'a':
      if(player_x > 0) {
        player_x--;
      }
      break;
    case 's':
      if(player_y < MAP_HEIGHT - 1) {
        player_y++;
      }
      break;
    case 'd':
      if(player_x < MAP_WIDTH - 1) {
        player_x++;
      }
      break;
    default:
      printf("Invalid direction.\n");
      break;
  }
}

void spawn_enemies() {
  while(enemies_count < MAX_ENEMIES) {
    int x = rand() % MAP_WIDTH;
    int y = rand() % MAP_HEIGHT;
    if(map[y][x] == 0 && player_x != x && player_y != y) {
      map[y][x] = 1;
      enemies_count++;
    }
  }
}

void fight_enemy(int x, int y) {
  map[y][x] = 0;
  printf("You defeated an enemy!\n");
  enemies_count--;
}

int main() {
  srand(time(NULL));
  player_x = rand() % MAP_WIDTH;
  player_y = rand() % MAP_HEIGHT;
  map[player_y][player_x] = 0;
  spawn_enemies();

  char input;
  int steps = 0;
  while(enemies_count > 0 && steps < 50) {
    print_map();
    printf("Enter your move [w - up, a - left, s - down, d - right]: ");
    scanf(" %c", &input);
    move_player(input);
    for(int i = 0; i < MAP_HEIGHT; i++) {
      for(int j = 0; j < MAP_WIDTH; j++) {
        if(map[i][j] == 1 && player_x == j && player_y == i) {
          fight_enemy(j, i);
        }
      }
    }
    spawn_enemies();
    steps++;
  }

  if(enemies_count == 0) {
    printf("You won! Congratulations!\n");
  } else {
    printf("Game over, you lost!\n");
  }

  return 0;
}