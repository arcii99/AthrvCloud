//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

/* Constants */
#define GRID_SIZE 10
#define SHIP_COUNT 3
#define HIT_CHAR 'X'
#define MISS_CHAR 'O'
#define SHIP_CHAR 'S'

/* Game state */
enum gameState {
  START,
  PLAYING,
  LOSE,
  WIN
};

/* Globals */
char grid[GRID_SIZE][GRID_SIZE];
int missedShots = 0;
int hitShots = 0;
bool hasShip[GRID_SIZE][GRID_SIZE] = { false };
bool isGameOver = false;
enum gameState state = START;

/* Prototypes */
void printGrid(bool showShips);
void generateShips();
bool checkShipOverlap(int x, int y);
bool isValidShot(int x, int y);
bool isHit(int x, int y);
bool isWin();
void startGame(char shipChar);

int main() {
  startGame(SHIP_CHAR);

  while (!isGameOver) {
    int x = 0, y = 0;

    printf("Enter position to shoot (x,y): ");
    scanf("%d,%d", &x, &y);

    x--;
    y--;

    if (!isValidShot(x, y)) {
      printf("Invalid shot! Try again.\n");
      continue;
    }

    if (isHit(x, y)) {
      printf("Hit!\n");
    } else {
      printf("Miss!\n");
    }

    if (isWin()) {
      state = WIN;
      isGameOver = true;
      printf("Congratulations! You won!\n");
    } else if (hitShots == SHIP_COUNT) {
      state = LOSE;
      isGameOver = true;
      printf("Game over! You lost!\n");
    }

    printGrid(state == START);
  }

  return 0;
}

void generateShips() {
  for (int i = 0; i < SHIP_COUNT; i++) {
    int x = rand() % GRID_SIZE;
    int y = rand() % GRID_SIZE;

    while (checkShipOverlap(x, y)) {
      x = rand() % GRID_SIZE;
      y = rand() % GRID_SIZE;
    }

    hasShip[x][y] = true;
  }
}

bool checkShipOverlap(int x, int y) {
  if (hasShip[x][y] == true) {
    return true;
  }

  if (x > 0 && hasShip[x - 1][y] == true) {
    return true;
  }

  if (x < GRID_SIZE - 1 && hasShip[x + 1][y] == true) {
    return true;
  }

  if (y > 0 && hasShip[x][y - 1] == true) {
    return true;
  }

  if (y < GRID_SIZE - 1 && hasShip[x][y + 1] == true) {
    return true;
  }

  return false;
}

bool isValidShot(int x, int y) {
  if (state == START) {
    return true;
  }

  if (x < 0 || x >= GRID_SIZE || y < 0 || y >= GRID_SIZE) {
    return false;
  }

  if (grid[x][y] != 0) {
    return false;
  }

  return true;
}

bool isHit(int x, int y) {
  if (hasShip[x][y] == true) {
    hitShots++;
    grid[x][y] = HIT_CHAR;
    return true;
  } else {
    missedShots++;
    grid[x][y] = MISS_CHAR;
    return false;
  }
}

bool isWin() {
  if (hitShots == SHIP_COUNT) {
    return true;
  }

  return false;
}

void printGrid(bool showShips) {
  system("clear");
  printf("%s\n", "Welcome to the game of Battleship!\n");

  for (int i = -1; i < GRID_SIZE; i++) {
    for (int j = -1; j < GRID_SIZE; j++) {
      if (i == -1 && j == -1) {
        printf("   ");
      } else if (i == -1) {
        printf("%d ", j + 1);
      } else if (j == -1) {
        printf("%c ", 'A' + i);
      } else {
        if (showShips == true && hasShip[i][j] == true) {
          printf("%c ", SHIP_CHAR);
        } else {
          printf("%c ", grid[i][j] == 0 ? ' ' : grid[i][j]);
        }
      }
    }

    printf("\n");
  }

  printf("\nMissed Shots: %d\n", missedShots);
  printf("Hit Shots: %d\n", hitShots);
}

void startGame(char shipChar) {
  srand(time(0));

  // Initialize grid
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      grid[i][j] = 0;
    }
  }

  generateShips();

  state = PLAYING;
  printGrid(state == START);
}