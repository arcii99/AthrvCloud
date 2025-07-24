//FormAI DATASET v1.0 Category: Table Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 9

// Function to print the game board
void printBoard(int board[]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("| %d ", board[i]);
        if ((i + 1) % 3 == 0) {
            printf("|\n");
        }
    }
    printf("\n");
}

// Function to check if the game has ended
int checkEnd(int board[]) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i += 3) {
        if (board[i] != 0 && board[i] == board[i+1] && board[i+1] == board[i+2]) {
            return board[i];
        }
    }
    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[i] != 0 && board[i] == board[i+3] && board[i+3] == board[i+6]) {
            return board[i];
        }
    }
    // Check diagonal
    if (board[0] != 0 && board[0] == board[4] && board[4] == board[8]) {
        return board[0];
    }
    if (board[2] != 0 && board[2] == board[4] && board[4] == board[6]) {
        return board[2];
    }
    // Check if all slots are filled
    int emptySlots = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i] == 0) {
            emptySlots++;
        }
    }
    if (emptySlots == 0) {
        return -1;
    }
    // Game has not ended
    return 0;
}

int main() {
    printf("Welcome to Tic Tac Toe!\n");
    printf("Player 1 will be X and Player 2 will be O.\n");
    int board[BOARD_SIZE] = {0}; // Initialize board with all zeroes 
    srand(time(NULL)); // Seed the random number generator
    int currentPlayer = rand() % 2 + 1; // Randomly select starting player (1 or 2)
    while (1) {
        printf("\n");
        printBoard(board);
        if (currentPlayer == 1) {
            printf("Player 1's turn (X): ");
        } else {
            printf("Player 2's turn (O): ");
        }
        int slot;
        scanf("%d", &slot);
        if (slot < 1 || slot > 9) {
            printf("Invalid slot number, please choose a number between 1 to 9.\n");
            continue;
        }
        if (board[slot-1] != 0) {
            printf("Slot already filled, please choose another slot.\n");
            continue;
        }
        board[slot-1] = currentPlayer;
        int winner = checkEnd(board);
        if (winner != 0) {
            printf("\n");
            printBoard(board);
            if (winner == -1) {
                printf("Game Drawn!\n");
            } else {
                printf("Congratulations Player %d (", winner);
                printf("%c", winner == 1 ? 'X' : 'O');
                printf("), You Won!\n");
            }
            break;
        }
        currentPlayer = currentPlayer == 1 ? 2 : 1; // Switch player
    }
    return 0;
}