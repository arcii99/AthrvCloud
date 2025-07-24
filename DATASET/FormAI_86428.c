//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 30
#define PACMAN 'C'
#define WALL '#'
#define FOOD '.'
#define ENEMY 'E'
#define BLANK ' '

int score = 0;

// initializes the game board
void initBoard(char board[][COLS]) {
    int row, col;
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            board[row][col] = BLANK;
        }
    }

    // create walls
    for (row = 0; row < ROWS; row++) {
        board[row][0] = WALL;
        board[row][COLS-1] = WALL;
    }
    for (col = 0; col < COLS; col++) {
        board[0][col] = WALL;
        board[ROWS-1][col] = WALL;
    }

    // create food
    for (row = 1; row < ROWS-1; row++) {
        for (col = 1; col < COLS-1; col++) {
            board[row][col] = FOOD;
        }
    }

    // create enemies
    srand(time(NULL));
    int numEnemies = (int) ((double) (ROWS*COLS) / 20.0);
    int i;
    for (i = 0; i < numEnemies; i++) {
        int randRow = rand() % (ROWS-2) + 1;
        int randCol = rand() % (COLS-2) + 1;
        board[randRow][randCol] = ENEMY;
    }

    // create Pac-Man
    int pacRow = ROWS / 2;
    int pacCol = COLS / 2;
    board[pacRow][pacCol] = PACMAN;
}

// prints the game board
void printBoard(char board[][COLS]) {
    int row, col;
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            printf("%c ", board[row][col]);
        }
        printf("\n");
    }
    printf("Score: %d\n", score);
}

// moves Pac-Man to the specified row and column
void movePacMan(char board[][COLS], int row, int col) {
    if (board[row][col] == FOOD) {
        score++;
    } else if (board[row][col] == ENEMY) {
        printf("You lost!\n");
        exit(0);
    }

    board[row][col] = PACMAN;
}

// moves the specified enemy
void moveEnemy(char board[][COLS], int enemyRow, int enemyCol) {
    int randRow = rand() % 3 - 1;
    int randCol = rand() % 3 - 1;

    if (board[enemyRow+randRow][enemyCol+randCol] == BLANK) {
        board[enemyRow][enemyCol] = BLANK;
        board[enemyRow+randRow][enemyCol+randCol] = ENEMY;
    }
}

int main() {
    char board[ROWS][COLS];
    initBoard(board);
    printBoard(board);

    while (1) {
        // get user input
        char direction;
        printf("Enter a direction (w, a, s, d): ");
        scanf(" %c", &direction);

        // move Pac-Man
        int pacRow, pacCol;
        int row, col;
        for (row = 0; row < ROWS; row++) {
            for (col = 0; col < COLS; col++) {
                if (board[row][col] == PACMAN) {
                    pacRow = row;
                    pacCol = col;
                    board[row][col] = BLANK;
                }
                if (board[row][col] == ENEMY) {
                    moveEnemy(board, row, col);
                }
            }
        }

        switch (direction) {
            case 'w':
                movePacMan(board, pacRow-1, pacCol);
                break;
            case 'a':
                movePacMan(board, pacRow, pacCol-1);
                break;
            case 's':
                movePacMan(board, pacRow+1, pacCol);
                break;
            case 'd':
                movePacMan(board, pacRow, pacCol+1);
                break;
            default:
                printf("Invalid direction\n");
                continue;
        }

        printBoard(board);
    }

    return 0;
}