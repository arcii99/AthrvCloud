//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 30
#define DIRS 4
#define MAX_GHOSTS 3
#define START_ROW 10
#define START_COL 15

const char maze[ROWS][COLS+1] = {
  "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
  "X  XXXXXX       XXXXXXXXXXXXX",
  "X  XXXXXXXXXX   XXXXXXXXXXXXX",
  "X  XXXXXXXXXX   XXXXXXXXXXXXX",
  "X  XXXXXXXXXX   XXXXXXXXXXXXX",
  "X              XXXXXXXXXXXXX",
  "XXXXXXX  XXXXXXXXXXXXXXXXXXX",
  "XXXXXXX  XXXXXXXXXXXXXXXXXXX",
  "XXXXXXX  XXXXXXXXXXXXXXXXXXX",
  "XXXXXXX            XXXXXXXXX",
  "XXXXXXX  XXXXXXXXXXXXXXXXXX",
  "XXXXXXX  XXXXXXXXXXXXXXXXXX",
  "XXXXXXX  XXXXXXXXXXXXXXXXXX",
  "X                    XXXXXX",
  "XXXXXXX  XXXXXXXXXXXXXXXXXX",
  "XXXXXXX  XXXXXXXXXXXXXXXXXX",
  "XXXXXXX  XXXXXXXXXXXXXXXXXX",
  "X   XXX  XXXXXXXXXXXXXXXXXX",
  "X                       XXX",
  "XXXXXXXXXXXXXXXXXXXXXXXXXXX"
};

enum direction {
  UP,
  DOWN,
  LEFT,
  RIGHT
};

typedef struct {
  int row;
  int col;
} pos;

typedef struct {
  pos location;
  enum direction preferredDirection; // ghost's preferred direction
  int alive; // 1 if alive, 0 if dead
} ghost;

void displayMaze(pos, ghost[MAX_GHOSTS]);
void movePlayer(pos *);
void moveGhost(ghost *, pos, int);
int inMaze(pos);
void printGhost(char, char, char, char);
void printPlayer(char, char, char, char);
void clearScreen(void);

int main() {
  pos player = { START_ROW, START_COL };
  ghost ghosts[MAX_GHOSTS] = {
    { {16,1}, LEFT, 1 },
    { {1,28}, DOWN, 1 },
    { {14,28}, LEFT, 1 }
  };
  srand(time(NULL)); // seed random number generator

  displayMaze(player, ghosts);
  while (1) {
    movePlayer(&player);
    if (!inMaze(player)) {
      printf("You won!\n");
      break;
    }
    for (int i = 0; i < MAX_GHOSTS; i++) {
      moveGhost(&ghosts[i], player, i);
    }
    displayMaze(player, ghosts);
    if (!ghosts[0].alive && !ghosts[1].alive && !ghosts[2].alive) {
      printf("Game over!\n");
      break;
    }
  }
  return 0;
}

void displayMaze(pos p, ghost g[MAX_GHOSTS]) {
  clearScreen();
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      if (i == p.row && j == p.col) {
        printPlayer('\\', '/', '/', '\\');
      } else {
        int isGhost = 0;
        for (int k = 0; k < MAX_GHOSTS; k++) {
          if (i == g[k].location.row && j == g[k].location.col) {
            printGhost('(', '_', '_', ')');
            isGhost = 1;
          }
        }
        if (!isGhost) {
          printf("%c", maze[i][j]);
        }
      }
    }
    printf("\n");
  }
}

void movePlayer(pos *p) {
  char input;
  printf("Move: ");
  scanf(" %c", &input);
  if (input == 'w' && maze[p->row-1][p->col] == ' ') {
    p->row--;
  } else if (input == 's' && maze[p->row+1][p->col] == ' ') {
    p->row++;
  } else if (input == 'a' && maze[p->row][p->col-1] == ' ') {
    p->col--;
  } else if (input == 'd' && maze[p->row][p->col+1] == ' ') {
    p->col++;
  }
}

void moveGhost(ghost *g, pos p, int index) {
  if (g->alive) {
    enum direction dirs[DIRS] = { UP, DOWN, LEFT, RIGHT };
    int oppositeDir;
    switch (g->preferredDirection) {
      case UP:
        oppositeDir = DOWN;
        break;
      case DOWN:
        oppositeDir = UP;
        break;
      case LEFT:
        oppositeDir = RIGHT;
        break;
      case RIGHT:
        oppositeDir = LEFT;
        break;
    }
    int canMove[DIRS] = { 1, 1, 1, 1 };
    int numDirs = DIRS;
    pos nextPos[DIRS] = {
      { g->location.row-1, g->location.col },
      { g->location.row+1, g->location.col },
      { g->location.row, g->location.col-1 },
      { g->location.row, g->location.col+1 }
    };
    for (int i = 0; i < DIRS; i++) { // remove opposite direction and illegal moves
      if (!inMaze(nextPos[i])) {
        canMove[i] = 0;
        numDirs--;
      } else if (i == oppositeDir) {
        canMove[i] = 0;
        numDirs--;
      } else if (maze[nextPos[i].row][nextPos[i].col] != ' ') {
        canMove[i] = 0;
        numDirs--;
      }
    }
    if (numDirs == 0) { // nowhere to move
      return;
    } else if (numDirs == 1) { // only one option
      for (int i = 0; i < DIRS; i++) {
        if (canMove[i] == 1) {
          g->location = nextPos[i];
        }
      }
    } else { // multiple options
      int availDirs[DIRS]; // available directions
      int numAvailDirs = 0;
      for (int i = 0; i < DIRS; i++) {
        if (canMove[i] == 1) {
          availDirs[numAvailDirs] = dirs[i];
          numAvailDirs++;
        }
      }
      int chooseDir = availDirs[rand() % numAvailDirs]; // random direction
      g->location = nextPos[chooseDir];
    }
    if (g->location.row == p.row && g->location.col == p.col) {
      printf("\nGhost %d caught you!\n", index+1);
      exit(0);
    }
  }
}

int inMaze(pos p) {
  return (p.row >= 0 && p.row < ROWS && p.col >= 0 && p.col < COLS && maze[p.row][p.col] == ' ');
}

void printGhost(char topLeft, char topRight, char bottomLeft, char bottomRight) {
  printf("\033[1;33m"); // set color to yellow
  printf("%c%c%c%c", topLeft, topRight, bottomLeft, bottomRight);
  printf("\033[0m"); // reset color
}

void printPlayer(char topLeft, char topRight, char bottomLeft, char bottomRight) {
  printf("\033[1;31m"); // set color to red
  printf("%c%c%c%c", topLeft, topRight, bottomLeft, bottomRight);
  printf("\033[0m"); // reset color
}

void clearScreen() {
  printf("\033[2J\033[1;1H"); // clear screen and move cursor to top left
}