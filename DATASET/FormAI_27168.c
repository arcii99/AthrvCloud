//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to select a random move for the AI
int randomMove(int board[]) {
    int moves[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    int numMoves = 9;

    // Remove any occupied spots from possible moves
    for (int i=0; i<9; i++) {
        if (board[i] != ' ') {
            for (int j=i; j<numMoves-1; j++) {
                moves[j] = moves[j+1];
            }
            numMoves--;
        }
    }

    // Pick a random move from remaining possibilities
    int i = rand() % numMoves;
    return moves[i];
}

// Function to check if game is over
int gameOver(int board[]) {
    // Check for horizontal wins
    for (int i=0; i<=6; i+=3) {
        if (board[i] == board[i+1] && board[i+1] == board[i+2]) {
            return 1;
        }
    }

    // Check for vertical wins
    for (int i=0; i<=2; i++) {
        if (board[i] == board[i+3] && board[i+3] == board[i+6]) {
            return 1;
        }
    }

    // Check for diagonal wins
    if ((board[0] == board[4] && board[4] == board[8]) ||
        (board[2] == board[4] && board[4] == board[6])) {
        return 1;
    }

    // Check for tie game
    for (int i=0; i<9; i++) {
        if (board[i] == ' ') {
            return 0;
        }
    }
    return 2;
}

// Function to print the game board
void printBoard(int board[]) {
    printf(" %c | %c | %c \n", board[0], board[1], board[2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[3], board[4], board[5]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[6], board[7], board[8]);
}

// Main function
int main() {
    // Seed random number generator
    srand(time(NULL));

    // Initialize game board and variables
    int board[9];
    int playerTurn = 1;
    int gameOverStatus = 0;

    // Initialize game board to empty spaces
    for (int i=0; i<9; i++) {
        board[i] = ' ';
    }

    // Main game loop
    while (gameOverStatus == 0) {
        system("clear");  // Clear terminal window
        printf("Tic Tac Toe\n\n");
        printBoard(board);

        // Determine player and AI moves
        int move;
        if (playerTurn) {
            printf("Enter move (1-9): ");
            scanf("%d", &move);
            move--;  // Convert move to zero-indexed
            while (board[move] != ' ') {
                printf("Invalid move. Try again: ");
                scanf("%d", &move);
                move--;  // Convert move to zero-indexed
            }
            board[move] = 'X';
        } else {
            printf("AI move: ");
            move = randomMove(board);
            board[move] = 'O';
        }

        // Check if game is over
        gameOverStatus = gameOver(board);
        playerTurn = !playerTurn;
    }

    // Print final board and game over message
    system("clear");  // Clear terminal window
    printf("Tic Tac Toe\n\n");
    printBoard(board);
    if (gameOverStatus == 1) {
        printf("Game over. Player %d wins!\n", playerTurn+1);
    } else {
        printf("Game over. Tie game.\n");
    }

    return 0;
}