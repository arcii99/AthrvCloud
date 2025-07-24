//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10
#define EMPTY 0
#define WALL 1
#define TREASURE 2
#define PLAYER 3

int maze[WIDTH][HEIGHT];
int playerX, playerY;
bool gameWon = false;

void initializeMaze() {
    // initialize maze with walls
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            maze[i][j] = WALL;
        }
    }

    // randomly place treasure
    srand(time(NULL));
    int treasureX = rand() % WIDTH;
    int treasureY = rand() % HEIGHT;
    maze[treasureX][treasureY] = TREASURE;

    // randomly place player (not in the same location as treasure)
    do {
        playerX = rand() % WIDTH;
        playerY = rand() % HEIGHT;
    } while (playerX == treasureX && playerY == treasureY);
    maze[playerX][playerY] = PLAYER;
}

void drawMaze() {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            if (maze[i][j] == WALL) {
                printf("#");
            } else if (maze[i][j] == TREASURE) {
                printf("$");
            } else if (maze[i][j] == PLAYER) {
                printf("@");
            }
        }
        printf("\n");
    }
}

void movePlayer(int x, int y) {
    int newX = playerX + x;
    int newY = playerY + y;

    if (newX >= 0 && newX < WIDTH && newY >= 0 && newY < HEIGHT) {
        if (maze[newX][newY] == WALL) {
            printf("You hit a wall. Try again.\n");
        } else if (maze[newX][newY] == TREASURE) {
            printf("You found the treasure!\n");
            gameWon = true;
        } else {
            maze[playerX][playerY] = EMPTY;
            playerX = newX;
            playerY = newY;
            maze[playerX][playerY] = PLAYER;
        }
    } else {
        printf("You cannot move in that direction. Try again.\n");
    }
}

int main() {
    initializeMaze();

    printf("Welcome to the maze game! Find the treasure ($).\n\n");
    drawMaze();

    while (!gameWon) {
        printf("Enter your move (up, down, left, right):\n");
        char input[10];
        scanf("%s", input);

        if (strcmp(input, "up") == 0) {
            movePlayer(-1, 0);
        } else if (strcmp(input, "down") == 0) {
            movePlayer(1, 0);
        } else if (strcmp(input, "left") == 0) {
            movePlayer(0, -1);
        } else if (strcmp(input, "right") == 0) {
            movePlayer(0, 1);
        } else {
            printf("Invalid input. Try again.\n");
        }

        drawMaze();
    }

    printf("Congratulations, you won!\n");
    return 0;
}