//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void print_board(int board[3][3]);
int game_over(int board[3][3]);
void ai_move(int board[3][3]);

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Initialize the board to all zeros
    int board[3][3] = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };

    // Player one is X, player two (AI) is O
    int player = 1;

    // Main game loop
    while (game_over(board) == 0) {
        // Print the board
        printf("\n");
        print_board(board);

        // If it's the player's turn
        if (player == 1) {
            // Get the player's move
            int row, col;
            printf("\nPlayer 1 (X) enter row number (0-2): ");
            scanf("%d", &row);
            printf("Player 1 (X) enter column number (0-2): ");
            scanf("%d", &col);

            // Check for invalid move
            if (board[row][col] != 0) {
                printf("That spot is already taken. Try again.\n");
                continue;
            }

            // Mark the spot with an X
            board[row][col] = 1;

            // Switch to AI's turn
            player = 2;
        }

        // If it's the AI's turn
        else {
            // Make the AI's move
            ai_move(board);

            // Switch back to player's turn
            player = 1;
        }
    }

    // Print the final board
    printf("\n");
    print_board(board);

    // Print the result of the game
    if (game_over(board) == 1) {
        printf("\nPlayer 1 (X) win!\n");
    }
    else if (game_over(board) == 2) {
        printf("\nAI player (O) win!\n");
    }
    else {
        printf("\nIt's a tie!\n");
    }

    return 0;
}

// Function to print the Tic Tac Toe board
void print_board(int board[3][3]) {
    printf("   0   1   2\n");
    printf("0  %c | %c | %c \n", (board[0][0] == 0) ? '.' : ((board[0][0] == 1) ? 'X' : 'O'), (board[0][1] == 0) ? '.' : ((board[0][1] == 1) ? 'X' : 'O'), (board[0][2] == 0) ? '.' : ((board[0][2] == 1) ? 'X' : 'O'));
    printf("  ---+---+---\n");
    printf("1  %c | %c | %c \n", (board[1][0] == 0) ? '.' : ((board[1][0] == 1) ? 'X' : 'O'), (board[1][1] == 0) ? '.' : ((board[1][1] == 1) ? 'X' : 'O'), (board[1][2] == 0) ? '.' : ((board[1][2] == 1) ? 'X' : 'O'));
    printf("  ---+---+---\n");
    printf("2  %c | %c | %c \n", (board[2][0] == 0) ? '.' : ((board[2][0] == 1) ? 'X' : 'O'), (board[2][1] == 0) ? '.' : ((board[2][1] == 1) ? 'X' : 'O'), (board[2][2] == 0) ? '.' : ((board[2][2] == 1) ? 'X' : 'O'));
}

// Function to check if the game is over
int game_over(int board[3][3]) {
    int i, j;

    // Check rows
    for (i = 0; i < 3; i++) {
        if (board[i][0] == 1 && board[i][1] == 1 && board[i][2] == 1) {
            return 1;
        }
        else if (board[i][0] == 2 && board[i][1] == 2 && board[i][2] == 2) {
            return 2;
        }
    }

    // Check columns
    for (j = 0; j < 3; j++) {
        if (board[0][j] == 1 && board[1][j] == 1 && board[2][j] == 1) {
            return 1;
        }
        else if (board[0][j] == 2 && board[1][j] == 2 && board[2][j] == 2) {
            return 2;
        }
    }

    // Check diagonals
    if (board[0][0] == 1 && board[1][1] == 1 && board[2][2] == 1) {
        return 1;
    }
    else if (board[0][0] == 2 && board[1][1] == 2 && board[2][2] == 2) {
        return 2;
    }
    else if (board[0][2] == 1 && board[1][1] == 1 && board[2][0] == 1) {
        return 1;
    }
    else if (board[0][2] == 2 && board[1][1] == 2 && board[2][0] == 2) {
        return 2;
    }

    // Check for tie
    int tie = 1;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == 0) {
                tie = 0;
            }
        }
    }
    if (tie) {
        return 3;
    }

    return 0;
}

// Function for AI to make move
void ai_move(int board[3][3]) {
    // Check if AI can win in this move
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == 0) {
                board[i][j] = 2;
                if (game_over(board) == 2) {
                    return;
                }
                board[i][j] = 0;
            }
        }
    }

    // Check if player can win next move, and block them
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == 0) {
                board[i][j] = 1;
                if (game_over(board) == 1) {
                    board[i][j] = 2;
                    return;
                }
                board[i][j] = 0;
            }
        }
    }

    // If AI can't win and player can't win next move, pick a random spot
    do {
        i = rand() % 3;
        j = rand() % 3;
    } while (board[i][j] != 0);

    board[i][j] = 2;
}