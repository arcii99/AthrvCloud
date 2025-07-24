//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 21
#define MAP_HEIGHT 21
#define MAX_GHOSTS 4
#define EMPTY 0
#define BLOCKED 1
#define PACMAN 2
#define GHOST 3
#define PELLET 4

int map[MAP_WIDTH][MAP_HEIGHT];
int pellets = 0;

// Initialize the game map
void initializeMap()
{
    int i, j;

    for (i = 0; i < MAP_WIDTH; i++) {
        for (j = 0; j < MAP_HEIGHT; j++) {
            if (i == 0 || i == MAP_WIDTH - 1 || j == 0 || j == MAP_HEIGHT - 1 || (i == 10 && j > 8 && j < 12)) {
                map[i][j] = BLOCKED;
            } else {
                map[i][j] = EMPTY;
            }
        }
    }

    map[1][1] = PACMAN;

    srand(time(NULL));

    for (i = 0; i < MAX_GHOSTS; i++) {
        int x = rand() % MAP_WIDTH;
        int y = rand() % MAP_HEIGHT;
        while (map[x][y] != EMPTY) {
            x = rand() % MAP_WIDTH;
            y = rand() % MAP_HEIGHT;
        }
        map[x][y] = GHOST;
    }

    for (i = 1; i < MAP_WIDTH - 1; i++) {
        for (j = 1; j < MAP_HEIGHT - 1; j++) {
            if (map[i][j] != BLOCKED && map[i][j] != PACMAN && map[i][j] != GHOST) {
                if (rand() % 4 == 0) {
                    map[i][j] = PELLET;
                    pellets++;
                }
            }
        }
    }
}

// Print the game map
void printMap()
{
    int i, j;

    printf("\n");
    for (i = 0; i < MAP_WIDTH; i++) {
        for (j = 0; j < MAP_HEIGHT; j++) {
            switch (map[i][j]) {
                case BLOCKED:
                    printf("#");
                    break;
                case PACMAN:
                    printf("C");
                    break;
                case GHOST:
                    printf("G");
                    break;
                case PELLET:
                    printf(".");
                    break;
                default:
                    printf(" ");
                    break;
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Move Pac-Man or a ghost to a new location
void move(int fromX, int fromY, int toX, int toY)
{
    if (map[fromX][fromY] == PACMAN || map[fromX][fromY] == GHOST) {
        int temp = map[toX][toY];
        map[toX][toY] = map[fromX][fromY];
        map[fromX][fromY] = temp;
    }
}

// Move Pac-Man
void movePacman(char input)
{
    int x, y;

    for (x = 0; x < MAP_WIDTH; x++) {
        for (y = 0; y < MAP_HEIGHT; y++) {
            if (map[x][y] == PACMAN) {
                int nextX = x;
                int nextY = y;
                switch (input) {
                    case 'a':
                        nextY--;
                        break;
                    case 'd':
                        nextY++;
                        break;
                    case 'w':
                        nextX--;
                        break;
                    case 's':
                        nextX++;
                        break;
                }
                if (map[nextX][nextY] == BLOCKED) {
                    return;
                } else if (map[nextX][nextY] == GHOST) {
                    printf("\nGame Over!\n");
                    exit(0);
                } else if (map[nextX][nextY] == PELLET) {
                    pellets--;
                }

                move(x, y, nextX, nextY);

                if (pellets == 0) {
                    printf("\nYou Win!\n");
                    exit(0);
                }
            }
        }
    }
}

// Move ghosts
void moveGhosts()
{
    int x, y;

    for (x = 0; x < MAP_WIDTH; x++) {
        for (y = 0; y < MAP_HEIGHT; y++) {
            if (map[x][y] == GHOST) {
                int nextX = x;
                int nextY = y;
                if (rand() % 2 == 0) {
                    if (rand() % 2 == 0) {
                        nextX++;
                    } else {
                        nextX--;
                    }
                } else {
                    if (rand() % 2 == 0) {
                        nextY++;
                    } else {
                        nextY--;
                    }
                }
                if (map[nextX][nextY] == BLOCKED || map[nextX][nextY] == GHOST) {
                    continue;
                }
                move(x, y, nextX, nextY);
            }
        }
    }
}

int main()
{
    char input;
    initializeMap();
    while (1) {
        printMap();
        printf("Enter a direction (a, d, w, s): ");
        scanf(" %c", &input);
        movePacman(input);
        moveGhosts();
    }
    return 0;
}