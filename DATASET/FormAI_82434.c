//FormAI DATASET v1.0 Category: Game ; Style: interoperable
#include<stdio.h>

// Game board dimensions
#define ROWS 3
#define COLS 3

// Function to draw the game board
void drawBoard(char board[][COLS]) {
    printf("\n");
    printf("  %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf(" ---|---|---\n");
    printf("  %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf(" ---|---|---\n");
    printf("  %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

// Function to check if the game has been won
int checkWin(char board[][COLS], char symbol) {
    for (int i = 0; i < ROWS; i++) {
        // Check rows
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) {
            return 1;
        }
        // Check columns
        if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol) {
            return 1;
        }
    }
    // Check diagonals
    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) {
        return 1;
    }
    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) {
        return 1;
    }
    return 0;
}

int main() {
    // Initialize game board
    char board[ROWS][COLS] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

    // Declare game variables
    int player = 1;
    int row, col;
    char symbol;

    // Game loop
    while (1) {
        // Draw board
        drawBoard(board);
        
        // Get player symbol
        if (player == 1) {
            symbol = 'X';
        } else {
            symbol = 'O';
        }

        // Get player move
        printf("Player %d (%c), enter row (1-3) and column (1-3) separated by a space: ", player, symbol);
        scanf("%d %d", &row, &col);

        // Make sure move is valid
        if (row < 1 || row > 3 || col < 1 || col > 3) {
            printf("Invalid move. Please enter a row and column between 1 and 3.\n");
            continue;
        }
        if (board[row-1][col-1] != 'X' && board[row-1][col-1] != 'O') {
            board[row-1][col-1] = symbol;
        } else {
            printf("That square is already taken. Please choose a different square.\n");
            continue;
        }

        // Check if game has been won
        if (checkWin(board, symbol)) {
            printf("Player %d (%c) has won the game!\n", player, symbol);
            drawBoard(board);
            break;
        }

        // Check for a tie
        int isTie = 1;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] != 'X' && board[i][j] != 'O') {
                    isTie = 0;
                    break;
                }
            }
            if (isTie == 0) {
                break;
            }
        }
        if (isTie) {
            printf("The game is a tie!\n");
            drawBoard(board);
            break;
        }

        // Switch player
        player = (player == 1) ? 2 : 1;
    }

    return 0;
}