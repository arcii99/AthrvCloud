//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 25
#define COLUMNS 25

#define PACMAN 'C'
#define WALL '#'
#define FOOD '.'
#define ENEMY 'E'

const int MAX_FOOD = 500;

struct Node {
    int x, y;
};

char grid[ROWS][COLUMNS];
int foodCount = 0;

struct Node pacman, enemy;

void initGrid() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLUMNS; j++) {
            if(i == 0 || i == ROWS - 1 || j == 0 || j == COLUMNS - 1) {
                grid[i][j] = WALL;
            } else {
                grid[i][j] = FOOD;
                foodCount++;
            }
        }
    }

    pacman.x = ROWS / 2;
    pacman.y = COLUMNS / 2;

    enemy.x = ROWS / 4;
    enemy.y = COLUMNS / 4;

    grid[pacman.x][pacman.y] = PACMAN;
    grid[enemy.x][enemy.y] = ENEMY;
}

void printGrid() {
    printf("\n");
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLUMNS; j++) {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool isFood(int x, int y) {
    return grid[x][y] == FOOD;
}

bool isValidMove(int x, int y) {
    return x >= 0 && x < ROWS && y >= 0 && y < COLUMNS && grid[x][y] != WALL && (x != enemy.x || y != enemy.y);
}

void movePacman(int x, int y) {
    if(isValidMove(x, y)) {
        if(isFood(x, y)) {
            foodCount--;
        }
        grid[pacman.x][pacman.y] = FOOD;
        pacman.x = x;
        pacman.y = y;
        grid[pacman.x][pacman.y] = PACMAN;
    }
}

void moveEnemy() {
    int nextX = enemy.x, nextY = enemy.y;
    if(pacman.x > enemy.x) {
        nextX++;
    } else if(pacman.x < enemy.x) {
        nextX--;
    }
    if(pacman.y > enemy.y) {
        nextY++;
    } else if(pacman.y < enemy.y) {
        nextY--;
    }
    if(isValidMove(nextX, nextY)) {
        grid[enemy.x][enemy.y] = FOOD;
        enemy.x = nextX;
        enemy.y = nextY;
        grid[enemy.x][enemy.y] = ENEMY;
    }
}

int main() {
    srand(time(NULL));
    initGrid();

    while(foodCount > 0) {
        printGrid();

        printf("Enter direction (up = 1, down = 2, left = 3, right = 4): ");
        int dir;
        scanf("%d", &dir);

        int newX = pacman.x, newY = pacman.y;
        switch(dir) {
            case 1:
                newX--;
                break;
            case 2:
                newX++;
                break;
            case 3:
                newY--;
                break;
            case 4:
                newY++;
                break;
        }

        movePacman(newX, newY);
        moveEnemy();
    }

    printf("You win!\n");
    return 0;
}