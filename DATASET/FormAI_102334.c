//FormAI DATASET v1.0 Category: Table Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print the game board
void printBoard(int board[], int size) {
    printf("\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", board[i]);
    }
}

// Function to determine the winner of the game
int determineWinner(int board[], int size) {
    for (int i = 0; i < size; i++) {
        if (board[i] != 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int size = 10; // Size of the board
    int board[size]; // The board
    int turn = 1; // The current turn
    int player1 = 0; // Player 1's score
    int player2 = 0; // Player 2's score

    // Initialize board with random values
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        board[i] = rand() % 10 + 1;
    }

    while (!determineWinner(board, size)) {
        printf("\n--- Turn %d ---\n", turn);

        // Print current board
        printBoard(board, size);

        // Get user input
        int selection;
        do {
            printf("\nPlayer %d: Enter a number between 1 and %d: ", turn, size);
            scanf("%d", &selection);
        } while (selection < 1 || selection > size || board[selection-1] == 0);

        // Update board and scores
        if (turn == 1) {
            player1 += board[selection-1];
        } else {
            player2 += board[selection-1];
        }
        board[selection-1] = 0;

        // Print scores
        printf("\nScores:\nPlayer 1: %d\nPlayer 2: %d", player1, player2);

        // Switch turn
        turn = turn == 1 ? 2 : 1;
    }

    // Determine winner
    int winner = player1 > player2 ? 1 : 2;

    printf("\n\n--- GAME OVER ---\nPlayer %d wins!", winner);

    return 0;
}