//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum {
    EMPTY,
    WALL,
    DOT,
    POWERUP,
    PACMAN,
    GHOST
};

enum {
    LEFT = 'a',
    RIGHT = 'd',
    UP = 'w',
    DOWN = 's',
    QUIT = 'q'
};

int maze[20][20] = {
    {WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL},
    {WALL,DOT,DOT,DOT,DOT,WALL,DOT,DOT,DOT,WALL,DOT,DOT,DOT,DOT,WALL,DOT,DOT,DOT,DOT,WALL},
    {WALL,DOT,WALL,WALL,DOT,DOT,DOT,WALL,DOT,WALL,DOT,WALL,WALL,DOT,DOT,DOT,WALL,WALL,DOT,WALL},
    {WALL,DOT,WALL,WALL,DOT,WALL,WALL,WALL,DOT,WALL,DOT,WALL,WALL,WALL,WALL,DOT,WALL,WALL,DOT,WALL},
    {WALL,DOT,DOT,DOT,DOT,WALL,WALL,WALL,DOT,WALL,DOT,WALL,WALL,WALL,WALL,DOT,DOT,DOT,DOT,WALL},
    {WALL,DOT,WALL,WALL,DOT,WALL,WALL,WALL,DOT,WALL,DOT,WALL,WALL,WALL,WALL,DOT,WALL,WALL,DOT,WALL},
    {WALL,DOT,DOT,DOT,WALL,DOT,DOT,DOT,DOT,DOT,DOT,DOT,DOT,DOT,WALL,DOT,DOT,DOT,DOT,WALL},
    {WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,DOT,WALL,WALL,WALL,WALL,WALL,WALL},
    {DOT,DOT,DOT,DOT,DOT,DOT,DOT,DOT,DOT,DOT,DOT,DOT,DOT,DOT,WALL,DOT,DOT,DOT,DOT,DOT},
    {WALL,WALL,WALL,WALL,WALL,WALL,WALL,DOT,WALL,WALL,WALL,DOT,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL},
    {DOT,DOT,DOT,DOT,DOT,DOT,DOT,DOT,DOT,DOT,DOT,DOT,DOT,DOT,WALL,DOT,DOT,DOT,DOT,DOT},
    {WALL,WALL,WALL,WALL,WALL,WALL,WALL,DOT,WALL,WALL,WALL,DOT,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL},
    {DOT,DOT,DOT,DOT,DOT,DOT,DOT,DOT,DOT,DOT,DOT,DOT,DOT,DOT,WALL,DOT,DOT,DOT,DOT,DOT},
    {WALL,WALL,WALL,WALL,WALL,WALL,WALL,DOT,WALL,WALL,WALL,DOT,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL},
    {WALL,DOT,DOT,DOT,DOT,DOT,DOT,DOT,DOT,DOT,DOT,DOT,DOT,DOT,DOT,DOT,DOT,DOT,DOT,WALL},
    {WALL,DOT,WALL,WALL,DOT,WALL,WALL,WALL,DOT,WALL,DOT,WALL,WALL,WALL,WALL,DOT,WALL,WALL,DOT,WALL},
    {WALL,DOT,DOT,WALL,DOT,DOT,DOT,WALL,DOT,DOT,DOT,DOT,DOT,DOT,WALL,DOT,DOT,WALL,DOT,WALL},
    {WALL,WALL,DOT,WALL,WALL,WALL,DOT,WALL,WALL,WALL,WALL,WALL,WALL,DOT,WALL,WALL,DOT,WALL,WALL,WALL},
    {WALL,DOT,DOT,DOT,WALL,DOT,DOT,DOT,DOT,DOT,DOT,DOT,DOT,DOT,WALL,DOT,DOT,DOT,DOT,WALL},
    {WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL},
};

int get_random_direction() {
    return (rand() % 4) + LEFT;
}

void move_pacman(int *x, int *y, int direction) {
    switch (direction) {
      case LEFT:
          if (maze[*y][(*x) - 1] != WALL) {
              (*x)--;
          }
          break;
      case RIGHT:
          if (maze[*y][(*x) + 1] != WALL) {
              (*x)++;
          }
          break;
      case UP:
          if (maze[(*y) - 1][*x] != WALL) {
              (*y)--;
          }
          break;
      case DOWN:
          if (maze[(*y) + 1][*x] != WALL) {
              (*y)++;
          }
          break;
      default:
          break;
    }
}

void move_ghost(int *x, int *y) {
    if (maze[*y][(*x) - 1] != WALL && maze[*y][(*x) - 1] != GHOST) {
        (*x)--;
    } else if (maze[*y][(*x) + 1] != WALL && maze[*y][(*x) + 1] != GHOST) {
        (*x)++;
    } else if (maze[(*y) - 1][*x] != WALL && maze[(*y) - 1][*x] != GHOST) {
        (*y)--;
    } else if (maze[(*y) + 1][*x] != WALL && maze[(*y) + 1][*x] != GHOST) {
        (*y)++;
    }
}

void display_maze(int x_pacman, int y_pacman, int x_ghost, int y_ghost) {
    system("clear");
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if (i == y_pacman && j == x_pacman) {
                printf("P");
            } else if (i == y_ghost && j == x_ghost) {
                printf("G");
            } else if (maze[i][j] == WALL) {
                printf("#");
            } else if (maze[i][j] == DOT) {
                printf(".");
            } else if (maze[i][j] == POWERUP) {
                printf("O");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int x_pacman = 10;
    int y_pacman = 17;
    int x_ghost = 9;
    int y_ghost = 9;
    char input = LEFT;
    int score = 0;

    while (input != QUIT) {
        if (maze[y_pacman][x_pacman] == DOT) {
            score++;
        } else if (maze[y_pacman][x_pacman] == POWERUP) {
            score += 10;
        }

        maze[y_pacman][x_pacman] = EMPTY;

        input = get_random_direction();

        move_pacman(&x_pacman, &y_pacman, input);
        move_ghost(&x_ghost, &y_ghost);

        if (x_pacman == x_ghost && y_pacman == y_ghost) {
            printf("\nGame Over\nYou Scored: %d Points\n", score);
            return 0;
        }

        display_maze(x_pacman, y_pacman, x_ghost, y_ghost);
    }

    return 0;
}