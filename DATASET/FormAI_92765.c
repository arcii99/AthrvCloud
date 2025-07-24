//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLUMNS 10

int maze[ROWS][COLUMNS];
int visited[ROWS][COLUMNS];

typedef struct position {
  int x;
  int y;
} Position;

void generateMaze() {
  srand(time(0));
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLUMNS; j++) {
      maze[i][j] = rand() % 2;
    }
  }
}

void printMaze() {
  printf("\n");
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLUMNS; j++) {
      printf("%d ", maze[i][j]);
    }
    printf("\n");
  }
}

int isValidMove(int x, int y) {
  if (x < 0 || x >= ROWS || y < 0 || y >= COLUMNS) {
    return 0;
  }
  if (maze[x][y] == 0 || visited[x][y] == 1) {
    return 0;
  }
  return 1;
}

void explore(Position currentPosition) {
  visited[currentPosition.x][currentPosition.y] = 1;
  printf("Current Position is (%d, %d)\n", currentPosition.x, currentPosition.y);

  if (currentPosition.x == ROWS - 1 && currentPosition.y == COLUMNS - 1) {
    printf("You have reached the end!\n");
    return;
  }

  if (isValidMove(currentPosition.x + 1, currentPosition.y)) { // Move Down
    Position newPosition = {currentPosition.x + 1, currentPosition.y};
    explore(newPosition);
  }
  if (isValidMove(currentPosition.x - 1, currentPosition.y)) { // Move Up
    Position newPosition = {currentPosition.x - 1, currentPosition.y};
    explore(newPosition);
  }
  if (isValidMove(currentPosition.x, currentPosition.y + 1)) { // Move Right
    Position newPosition = {currentPosition.x, currentPosition.y + 1};
    explore(newPosition);
  }
  if (isValidMove(currentPosition.x, currentPosition.y - 1)) { // Move Left
    Position newPosition = {currentPosition.x, currentPosition.y - 1};
    explore(newPosition);
  }
}

int main() {
  generateMaze();
  printMaze();

  Position startPosition = {0, 0};
  explore(startPosition);

  return 0;
}