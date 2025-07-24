//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: futuristic
#include <stdio.h>

#define ROWS 5
#define COLS 10

char grid[ROWS][COLS] = { {'_', '_', '_', '_', '_', '_', '_', '_', '_', '_'},
                          {'_', '_', '_', '_', '_', '_', '_', '_', '_', '_'},
                          {'_', '_', '_', '_', '_', '_', '_', '_', '_', '_'},
                          {'_', '_', '_', '_', '_', '_', '_', '_', '_', '_'},
                          {'_', '_', '_', '_', '_', '_', '_', '_', '_', '_'} };

int score = 0;
int level = 1;
int lives = 3;
int shooter_pos = 4;

void printGrid() {
    printf("Score: %d   Level: %d   Lives: %d\n\n", score, level, lives);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

void moveShooter(int direction) {
    grid[ROWS-1][shooter_pos] = '_';
    shooter_pos += direction;
    if (shooter_pos < 0) {
        shooter_pos = 0;
    } else if (shooter_pos > COLS-1) {
        shooter_pos = COLS-1;
    }
    grid[ROWS-1][shooter_pos] = 'S';
}

void moveEnemies() {
    for (int i = 0; i < ROWS-1; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == 'E') {
                grid[i][j] = '_';
                if (i == ROWS-2) {
                    lives--;
                } else {
                    if (grid[i+1][j] == 'S') {
                        lives--;
                    } else {
                        grid[i+1][j] = 'E';
                    }
                }
            }
        }
    }
}

void shoot() {
    int row = ROWS-2;
    while (row >= 0 && grid[row][shooter_pos] != 'E') {
        grid[row+1][shooter_pos] = '_';
        grid[row][shooter_pos] = '*';
        row--;
    }
    if (row >= 0) {
        grid[row+1][shooter_pos] = '_';
        grid[row][shooter_pos] = 'E';
        score++;
    }
}

int main() {
    printf("Welcome to Space Invaders Clone!\n\n");
    printGrid();
    printf("Use left arrow (<) and right arrow (>) to move, and up arrow (^) to shoot.\n\n");

    char input = ' ';
    while (input != 'q' && lives > 0) {
        input = getchar();
        switch (input) {
            case '<':
                moveShooter(-1);
                break;
            case '>':
                moveShooter(1);
                break;
            case '^':
                shoot();
                break;
            default:
                break;
        }
        moveEnemies();
        printGrid();
    }
    printf("Game over! Final score: %d\n\n", score);

    return 0;
}