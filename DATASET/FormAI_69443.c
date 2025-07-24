//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define BOMB_PROBABILITY 0.15
#define EMPTY_CELL ' '
#define BOMB_CELL '*'

char gameBoard[ROWS][COLS];
int revealedCellsCount = 0;

void setupGame() {
    srand(time(NULL));

    // Initialize game board with empty cells
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            gameBoard[i][j] = EMPTY_CELL;
        }
    }

    // Place bombs on the board randomly
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if ((float)rand() / RAND_MAX < BOMB_PROBABILITY) {
                gameBoard[i][j] = BOMB_CELL;
            }
        }
    }
}

void printGameBoard() {
    printf("\n");
    printf("  ");
    for (int i = 0; i < COLS; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (int i = 0; i < ROWS; i++) {
        printf("%d ", i);
        for (int j = 0; j < COLS; j++) {
            printf("%c ", gameBoard[i][j]);
        }
        printf("\n");
    }
}

int getCellStatus(int row, int col) {
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        return -1; // Out of bounds
    }

    if (gameBoard[row][col] == BOMB_CELL) {
        return -2; // Bomb cell
    }

    int count = 0;
    if (row > 0 && gameBoard[row - 1][col] == BOMB_CELL) {
        count++;
    }
    if (row < ROWS - 1 && gameBoard[row + 1][col] == BOMB_CELL) {
        count++;
    }
    if (col > 0 && gameBoard[row][col - 1] == BOMB_CELL) {
        count++;
    }
    if (col < COLS - 1 && gameBoard[row][col + 1] == BOMB_CELL) {
        count++;
    }
    if (row > 0 && col > 0 && gameBoard[row - 1][col - 1] == BOMB_CELL) {
        count++;
    }
    if (row > 0 && col < COLS - 1 && gameBoard[row - 1][col + 1] == BOMB_CELL) {
        count++;
    }
    if (row < ROWS - 1 && col > 0 && gameBoard[row + 1][col - 1] == BOMB_CELL) {
        count++;
    }
    if (row < ROWS - 1 && col < COLS - 1 && gameBoard[row + 1][col + 1] == BOMB_CELL) {
        count++;
    }

    return count;
}

void revealCell(int row, int col) {
    int status = getCellStatus(row, col);

    if (status == -1) {
        printf("Invalid cell coordinates. Please enter valid coordinates.\n");
    } else if (status == -2) {
        printf("You hit a bomb! Game over.\n");
        exit(0);
    } else {
        gameBoard[row][col] = '0' + status;
        revealedCellsCount++;

        if (revealedCellsCount == ROWS * COLS - (int)(BOMB_PROBABILITY * ROWS * COLS)) {
            printf("You won! Congratulations!\n");
            exit(0);
        }

        if (status == 0) {
            revealCell(row - 1, col);
            revealCell(row + 1, col);
            revealCell(row, col - 1);
            revealCell(row, col + 1);
            revealCell(row - 1, col - 1);
            revealCell(row - 1, col + 1);
            revealCell(row + 1, col - 1);
            revealCell(row + 1, col + 1);
        }
    }
}

int main() {
    setupGame();

    while (1) {
        printGameBoard();

        int row, col;
        printf("Enter row and column to reveal cell (separated by space): ");
        scanf("%d %d", &row, &col);

        revealCell(row, col);
    }

    return 0;
}