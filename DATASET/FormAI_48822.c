//FormAI DATASET v1.0 Category: Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10

char board[BOARD_SIZE][BOARD_SIZE];

/* Function to initialize the game board with random ships */
void initializeBoard() {
    int i, j;

    /* Set everything on the board to ocean */
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 'O';
        }
    }

    srand((unsigned)time(NULL));

    /* Randomly place three ships on the board */
    for (i = 0; i < 3; i++) {
        int row = rand() % BOARD_SIZE;
        int col = rand() % BOARD_SIZE;

        /* Make sure we don't place the ship on top of another one */
        while (board[row][col] != 'O') {
            row = rand() % BOARD_SIZE;
            col = rand() % BOARD_SIZE;
        }

        /* Place the ship on the board */
        board[row][col] = 'S';
    }
}

/* Function to display the game board */
void displayBoard() {
    int i, j;

    printf("   ");

    /* Print column labels */
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i+1);
    }

    printf("\n");

    /* Print row labels and board contents */
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%c  ", 'A' + i);

        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }

        printf("\n");
    }
}

int main() {
    int row, col;

    initializeBoard();

    while (1) {
        displayBoard();

        printf("Enter a row (A-J): ");
        scanf(" %c", &row);

        printf("Enter a column (1-10): ");
        scanf("%d", &col);

        row = row - 'A';
        col = col - 1;

        if (board[row][col] == 'S') {
            printf("You hit a ship!\n");
            board[row][col] = 'X';
        } else {
            printf("You missed!\n");
            board[row][col] = '-';
        }
    }

    return 0;
}