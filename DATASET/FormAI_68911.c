//FormAI DATASET v1.0 Category: Table Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to get user input for row and column number
void getInput(int* row, int* col) {
    printf("Enter number of rows (minimum 3, maximum 10): ");
    scanf("%d", row);

    printf("Enter number of columns (minimum 3, maximum 10): ");
    scanf("%d", col);

    // Make sure row and column numbers are within range
    while (*row < 3 || *row > 10 || *col < 3 || *col > 10) {
        printf("Invalid input. Please enter numbers between 3 and 10: ");
        scanf("%d %d", row, col);
    }
}

// Function to print the game board
void printBoard(int** board, int row, int col) {
    printf(" ");
    for (int j = 0; j < col; j++) {
        printf(" %d", j+1);
    }

    printf("\n");

    for (int i = 0; i < row; i++) {
        printf("%d", i+1);
        for (int j = 0; j < col; j++) {
            printf(" %c", board[i][j] == 0 ? '-' : board[i][j] == 1 ? 'X' : 'O');
        }
        printf("\n");
    }
}

// Function to check if there is a winner
int checkWinner(int** board, int row, int col, int player) {
    // Check rows
    for (int i = 0; i < row; i++) {
        int count = 0;
        for (int j = 0; j < col; j++) {
            if (board[i][j] == player) {
                count++;
            }
        }
        if (count == col) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < col; j++) {
        int count = 0;
        for (int i = 0; i < row; i++) {
            if (board[i][j] == player) {
                count++;
            }
        }
        if (count == row) {
            return 1;
        }
    }

    // Check diagonals
    int count1 = 0, count2 = 0;
    for (int i = 0, j = 0; i < row && j < col; i++, j++) {
        if (board[i][j] == player) {
            count1++;
        }
    }
    if (count1 == col) {
        return 1;
    }

    for (int i = 0, j = col-1; i < row && j >= 0; i++, j--) {
        if (board[i][j] == player) {
            count2++;
        }
    }
    if (count2 == col) {
        return 1;
    }

    return 0;
}

// Main function
int main() {
    int row, col, turn = 0, winner = 0;

    // Get user input for game board size
    getInput(&row, &col);

    // Allocate memory for game board
    int** board = (int**) malloc(sizeof(int*) * row);
    for (int i = 0; i < row; i++) {
        board[i] = (int*) malloc(sizeof(int) * col);
    }

    // Initialize game board with empty cells
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            board[i][j] = 0;
        }
    }

    // Start game with random player
    srand(time(NULL));
    turn = rand() % 2 + 1;

    // Game loop
    while (!winner) {
        // Print game board
        printBoard(board, row, col);

        // Get player input for row and column number
        int r, c;
        printf("Player %d's turn (X/O)\n", turn);
        printf("Enter row number: ");
        scanf("%d", &r);
        printf("Enter column number: ");
        scanf("%d", &c);

        // Check if cell is already taken or input is invalid
        while (r <= 0 || r > row || c <= 0 || c > col || board[r-1][c-1] != 0) {
            printf("Invalid input or cell already taken. Please try again.\n");
            printf("Enter row number: ");
            scanf("%d", &r);
            printf("Enter column number: ");
            scanf("%d", &c);
        }

        // Update game board with player's move
        board[r-1][c-1] = turn;

        // Check if there is a winner
        winner = checkWinner(board, row, col, turn);
        if (winner) {
            printf("Player %d wins!\n", turn);
            printBoard(board, row, col);
            break;
        }

        // Switch turn to other player
        turn = turn == 1 ? 2 : 1;
    }

    // Free memory
    for (int i = 0; i < row; i++) {
        free(board[i]);
    }
    free(board);

    return 0;
}