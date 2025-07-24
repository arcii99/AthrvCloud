//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAP_SIZE 10
#define MAX_ENEMIES 3

typedef struct {
  int x;
  int y;
} Point;

void printMap(char map[MAP_SIZE][MAP_SIZE], Point player, Point enemies[MAX_ENEMIES]) {
  for (int i = 0; i < MAP_SIZE; i++) {
    for (int j = 0; j < MAP_SIZE; j++) {
      if (i == player.y && j == player.x) {
        printf("P");
      } else {
        bool isEnemy = false;
        for (int k = 0; k < MAX_ENEMIES; k++) {
          if (enemies[k].x == j && enemies[k].y == i) {
            printf("E");
            isEnemy = true;
            break;
          }
        }
        if (!isEnemy) printf("%c", map[i][j]);
      }
    }
    printf("\n");
  }
}

Point movePlayer(char map[MAP_SIZE][MAP_SIZE], Point player, char direction) {
  int newX = player.x;
  int newY = player.y;

  switch(direction) {
    case 'w':
      newY--;
      break;
    case 's':
      newY++;
      break;
    case 'a':
      newX--;
      break;
    case 'd':
      newX++;
      break;
    default:
      break;
  }

  if(newX < 0 || newX >= MAP_SIZE || newY < 0 || newY >= MAP_SIZE || map[newY][newX] == '#') {
    return player;
  }

  player.x = newX;
  player.y = newY;
  return player;
}

bool isEnemyInRange(Point player, Point enemy) {
  int xDiff = abs(player.x - enemy.x);
  int yDiff = abs(player.y - enemy.y);
  int diffSum = xDiff + yDiff;

  if(diffSum <= 3) return true;
  else return false;
}

int main() {
  char map[MAP_SIZE][MAP_SIZE] = {
    {'#', '#', '#', '#', '#', ' ', '#', '#', '#', '#'},
    {'#', '.', '.', '.', '#', ' ', '#', '.', '.', '#'},
    {'#', '.', '#', '.', '#', '#', '#', '.', '.', '#'},
    {'#', '.', '.', '.', '.', ' ', '.', '.', '#', '#'},
    {'#', '#', '#', '#', '#', ' ', '#', '.', '.', '#'},
    {' ', ' ', ' ', ' ', '#', ' ', '#', '.', '#', '#'},
    {'#', '.', '.', '.', '#', '#', '#', '.', '.', '#'},
    {'#', '.', '#', '.', ' ', ' ', '.', '.', '#', '#'},
    {'#', '.', '.', '.', '.', '#', '.', '.', '.', ' '},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
  };

  Point player = {1, 1};
  Point enemies[MAX_ENEMIES];
  srand(time(NULL));
  for(int i = 0; i < MAX_ENEMIES; i++) {
    enemies[i].x = rand() % MAP_SIZE;
    enemies[i].y = rand() % MAP_SIZE;
  }

  bool gameover = false;
  while(!gameover) {
    printMap(map, player, enemies);

    char input;
    printf("Enter a direction (w,a,s,d): ");
    scanf(" %c", &input);

    player = movePlayer(map, player, input);

    for (int i = 0; i < MAX_ENEMIES; i++) {
      if(isEnemyInRange(player, enemies[i])) {
        printf("You were killed by an enemy!\n");
        gameover = true;
        break;
      }
    }

    if(player.x == 8 && player.y == 9) {
      printf("You win!\n");
      gameover = true;
    }
  }

  return 0;
}