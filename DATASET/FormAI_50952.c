//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 18
#define GHOSTS 4

enum direction {UP, DOWN, LEFT, RIGHT};

char maze[HEIGHT][WIDTH] = {
    "+-----------------+",
    "|                 |",
    "| +--+ +--+ +--+ |",
    "| |  | |  | |  | |",
    "| +--+ +--+ +--+ |",
    "|                 |",
    "| +--+ +--+ +--+ |",
    "| |  | |  | |  | |",
    "| +--+ +--+ +--+ |",
    "|                 |",
    "| +--+ +--+ +--+ |",
    "| |  | |  | |  | |",
    "| +--+ +--+ +--+ |",
    "|                 |",
    "| +--+ +--+ +--+ |",
    "| |  | |  | |  | |",
    "| +--+ +--+ +--+ |",
    "|                 |",
    "+-----------------+"
};

int pacmanX, pacmanY;
int ghostX[GHOSTS], ghostY[GHOSTS];
int ghostDir[GHOSTS];
int score;

int isGhost(int x, int y) {
    int i;
    for (i = 0; i < GHOSTS; i++) {
        if (ghostX[i] == x && ghostY[i] == y) {
            return 1;
        }
    }
    return 0;
}

void clearScreen() {
    system("clear");
}

void printScreen() {
    clearScreen();
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (i == pacmanY && j == pacmanX) {
                printf("C");
            } else if (maze[i][j] == '+' || maze[i][j] == '-' || maze[i][j] == '|') {
                printf("%c", maze[i][j]);
            } else if (isGhost(j, i)) {
                printf("G");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("Score: %d\n", score);
}

void moveGhost(int i) {
    int x = ghostX[i], y = ghostY[i];
    switch (ghostDir[i]) {
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
    }
    if (maze[y][x] != '+') {
        ghostX[i] = x;
        ghostY[i] = y;
    } else {
        ghostDir[i] = rand() % 4;
    }
}

int main() {
    srand(time(NULL));
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (maze[i][j] == 'C') {
                pacmanX = j;
                pacmanY = i;
            } else if (maze[i][j] == 'G') {
                ghostX[score] = j;
                ghostY[score] = i;
                ghostDir[score] = rand() % 4;
                score++;
            }
        }
    }
    while (score < GHOSTS) {
        ghostX[score] = rand() % (WIDTH-2) + 1;
        ghostY[score] = rand() % (HEIGHT-2) + 1;
        if (!isGhost(ghostX[score], ghostY[score]) && maze[ghostY[score]][ghostX[score]] != '+') {
            ghostDir[score] = rand() % 4;
            score++;
        }
    }
    char input;
    while (1) {
        printScreen();
        input = getchar();
        switch (input) {
            case 'w':
                if (maze[pacmanY-1][pacmanX] != '+') {
                    pacmanY--;
                }
                break;
            case 's':
                if (maze[pacmanY+1][pacmanX] != '+') {
                    pacmanY++;
                }
                break;
            case 'a':
                if (maze[pacmanY][pacmanX-1] != '+') {
                    pacmanX--;
                }
                break;
            case 'd':
                if (maze[pacmanY][pacmanX+1] != '+') {
                    pacmanX++;
                }
                break;
        }
        for (i = 0; i < GHOSTS; i++) {
            moveGhost(i);
        }
        for (i = 0; i < GHOSTS; i++) {
            if (ghostX[i] == pacmanX && ghostY[i] == pacmanY) {
                printf("Game Over!\n");
                return 0;
            }
        }
        score += 10;
    }
    return 0;
}