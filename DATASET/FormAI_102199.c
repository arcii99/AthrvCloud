//FormAI DATASET v1.0 Category: Game of Life ; Style: complete
#include <stdio.h>
#define ROWS 20
#define COLS 50

void displayBoard(int board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void updateBoard(int board[ROWS][COLS]) {
    int newBoard[ROWS][COLS] = {0};

    for (int i = 1; i < ROWS - 1; i++) {
        for (int j = 1; j < COLS - 1; j++) {
            int neighbors = 0;

            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    neighbors += board[i + x][j + y];
                }
            }

            neighbors -= board[i][j];

            if (board[i][j] == 1 && neighbors < 2) {
                newBoard[i][j] = 0; 
            } else if (board[i][j] == 1 && neighbors > 3) {
                newBoard[i][j] = 0; 
            } else if (board[i][j] == 0 && neighbors == 3) {
                newBoard[i][j] = 1; 
            } else {
                newBoard[i][j] = board[i][j]; 
            }
        }
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = newBoard[i][j];
        }
    }
}

int main() {
    int board[ROWS][COLS] = {0};

    /* Initialize board with random seed */
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = rand() % 2;
        }
    }

    /* Run the game */
    while (1) {
        displayBoard(board);
        updateBoard(board);
        usleep(100000); // Wait 100ms before updating
        printf("\033[2J\033[H"); // Clear terminal screen
    }

    return 0;
}