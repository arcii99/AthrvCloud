//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>

#define ROWS 5
#define COLUMNS 10
#define ALIEN 'A'
#define SHIP 'S'
#define BLANK ' '
#define LASER '|'
#define TRUE 1
#define FALSE 0

void displayGrid(char grid[][COLUMNS]);
void initializeGrid(char grid[][COLUMNS]);
void moveAliens(char grid[][COLUMNS]);
void moveShip(char grid[][COLUMNS], int position);
void fireLaser(char grid[][COLUMNS], int position);
int checkCollision(char grid[][COLUMNS]);

int main() {
    char grid[ROWS][COLUMNS];
    int shipPosition = COLUMNS / 2;
    int gameOver = FALSE;
    int score = 0;
    char input;

    srand(time(NULL));

    initializeGrid(grid);
    displayGrid(grid);

    while (!gameOver) {
        moveAliens(grid);
        moveShip(grid, shipPosition);

        if (toupper(input) == 'F') {
            fireLaser(grid, shipPosition);
        }

        gameOver = checkCollision(grid);
        score++;

        displayGrid(grid);
        printf("Score: %d\n", score);
        printf("Move (L)eft, (R)ight or (F)ire laser: ");
        scanf(" %c", &input);

        if (toupper(input) == 'L') {
            if (shipPosition > 0) {
                shipPosition--;
            }
        }
        else if (toupper(input) == 'R') {
            if (shipPosition < COLUMNS - 1) {
                shipPosition++;
            }
        }
    }

    printf("Game Over!\n");
    printf("Final Score: %d\n", score);

    return 0;
}

void displayGrid(char grid[][COLUMNS]) {
    int row, column;

    for (row = 0; row < ROWS; row++) {
        for (column = 0; column < COLUMNS; column++) {
            printf("%c ", grid[row][column]);
        }

        printf("\n");
    }

    printf("\n");
}

void initializeGrid(char grid[][COLUMNS]) {
    int row, column;

    for (row = 0; row < ROWS; row++) {
        for (column = 0; column < COLUMNS; column++) {
            if (row == 0) {
                grid[row][column] = ALIEN;
            }
            else {
                grid[row][column] = BLANK;
            }
        }
    }

    grid[ROWS - 1][COLUMNS / 2] = SHIP;
}

void moveAliens(char grid[][COLUMNS]) {
    int row, column;

    for (row = ROWS - 1; row >= 0; row--) {
        for (column = 0; column < COLUMNS; column++) {
            if (grid[row][column] == ALIEN) {
                grid[row][column] = BLANK;

                if (row + 1 < ROWS) {
                    grid[row + 1][column] = ALIEN;
                }
                else {
                    grid[row][column] = BLANK;
                }
            }
        }
    }

    if (rand() % 2 == 0) {
        grid[0][rand() % COLUMNS] = ALIEN;
    }
}

void moveShip(char grid[][COLUMNS], int position) {
    int row;

    for (row = ROWS - 1; row >= 0; row--) {
        if (grid[row][position] == SHIP) {
            grid[row][position] = BLANK;

            if (row + 1 < ROWS) {
                grid[row + 1][position] = SHIP;
            }
            else {
                grid[row][position] = SHIP;
            }

            break;
        }
    }
}

void fireLaser(char grid[][COLUMNS], int position) {
    int row;

    for (row = ROWS - 2; row >= 0; row--) {
        if (grid[row][position] == ALIEN) {
            grid[row][position] = BLANK;
            break;
        }
        else if (grid[row][position] == LASER) {
            break;
        }
        else {
            grid[row][position] = LASER;
        }
    }
}

int checkCollision(char grid[][COLUMNS]) {
    int row, column;

    for (row = ROWS - 1; row >= 0; row--) {
        for (column = 0; column < COLUMNS; column++) {
            if (grid[row][column] == LASER) {
                grid[row][column] = BLANK;

                if (row > 0) {
                    if (grid[row - 1][column] == ALIEN) {
                        grid[row - 1][column] = BLANK;
                        return FALSE;
                    }
                    else {
                        grid[row - 1][column] = LASER;
                    }
                }
            }
            else if (grid[row][column] == ALIEN && row == ROWS - 1) {
                return TRUE;
            }
        }
    }

    return FALSE;
}