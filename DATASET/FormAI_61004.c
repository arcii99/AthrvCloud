//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 21
#define COLS 19

int board[ROWS][COLS] = {0};  // initialize board to all zeros
int ghosts[4][2] = {0};  // initialize ghost positions to all zeros
int score = 0;

void clearScreen() {
    printf("\033[2J\033[1;1H");  // clear the console screen
}

void printBoard() {
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (board[i][j] == 0) {
                printf(" ");
            } else if (board[i][j] == 1) {
                printf("P");  // Pac-Man
            } else if (board[i][j] == 2) {
                printf("G");  // Ghost
            } else if (board[i][j] == 3) {
                printf(".");  // pellet
            } else if (board[i][j] == 4) {
                printf("o");  // power pellet
            }
        }
        printf("\n");
    }
}

void movePacMan(int row, int col) {
    if (board[row][col] == 3) {
        score += 10;  // add 10 to the score for eating a pellet
    } else if (board[row][col] == 4) {
        score += 50;  // add 50 to the score for eating a power pellet
        // turn ghosts blue and make them vulnerable for 5 seconds
        int i;
        for (i = 0; i < 4; i++) {
            board[ghosts[i][0]][ghosts[i][1]] = 5;
        }
    }

    // move Pac-Man to the new location
    board[row][col] = 1;
}

void moveGhosts() {
    int i;
    for (i = 0; i < 4; i++) {
        // generate a random direction for each ghost
        int direction = rand() % 4;
        int newRow = ghosts[i][0];
        int newCol = ghosts[i][1];

        switch (direction) {
            case 0:  // move up
                newRow--;
                break;
            case 1:  // move right
                newCol++;
                break;
            case 2:  // move down
                newRow++;
                break;
            case 3:  // move left
                newCol--;
                break;
        }

        // check if the new location is valid
        if (board[newRow][newCol] == 0 || board[newRow][newCol] == 3 || board[newRow][newCol] == 4) {
            board[ghosts[i][0]][ghosts[i][1]] = 0;
            ghosts[i][0] = newRow;
            ghosts[i][1] = newCol;
            board[newRow][newCol] = 2;
        }
    }
}

void checkCollision() {
    // check for collision between Pac-Man and ghosts
    int i;
    for (i = 0; i < 4; i++) {
        if (ghosts[i][0] == board[1][1] && ghosts[i][1] == board[1][1]) {
            printf("Game over! You were caught by a ghost.\n");
            exit(0);
        }
    }

    // check if all pellets have been eaten
    int j, pelletsRemaining = 0;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (board[i][j] == 3 || board[i][j] == 4) {
                pelletsRemaining++;
            }
        }
    }
    if (pelletsRemaining == 0) {
        printf("Congratulations! You won the game with a score of %d.\n", score);
        exit(0);
    }
}

int main() {
    // set up the game board
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (i == 0 || i == ROWS-1 || j == 0 || j == COLS-1) {
                board[i][j] = 9;  // set border wall
            } else if ((i == 1 && j == 1) || (i == ROWS-2 && j == COLS-2) || (i == ROWS-2 && j == 1) || (i == 1 && j == COLS-2)) {
                board[i][j] = 1;  // set Pac-Man starting location
            } else if ((i == 2 && j == 1) || (i == ROWS-3 && j == COLS-2) || (i == ROWS-3 && j == 1) || (i == 2 && j == COLS-2)) {
                board[i][j] = 2;  // set ghost starting location
                int index = (i == 2 && j == 1) ? 0 : (i == ROWS-3 && j == COLS-2) ? 1 : (i == ROWS-3 && j == 1) ? 2 : 3;
                ghosts[index][0] = i;
                ghosts[index][1] = j;
            } else {
                board[i][j] = (rand() % 5 == 0) ? 4 : 3;  // randomly place pellets and power pellets
            }
        }
    }

    // main game loop
    while (1) {
        clearScreen();
        printBoard();

        int direction = getchar();
        getchar();  // consume extra newline character

        // move Pac-Man in the desired direction
        int newRow = ghosts[0][0];
        int newCol = ghosts[0][1];
        if (direction == 'w') {
            newRow--;
        } else if (direction == 'd') {
            newCol++;
        } else if (direction == 's') {
            newRow++;
        } else if (direction == 'a') {
            newCol--;
        }

        // check if the new location is valid
        if (board[newRow][newCol] == 0 || board[newRow][newCol] == 3 || board[newRow][newCol] == 4) {
            board[ghosts[0][0]][ghosts[0][1]] = 0;
            movePacMan(newRow, newCol);
        }

        moveGhosts();
        checkCollision();

        // wait for a half second before continuing
        struct timespec ts = {0, 500000000L};
        nanosleep(&ts, NULL);
    }

    return 0;
}