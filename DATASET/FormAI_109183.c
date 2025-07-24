//FormAI DATASET v1.0 Category: Checkers Game ; Style: satisfied
#include <stdio.h>
#define BOARD_SIZE 8

int board[BOARD_SIZE][BOARD_SIZE] = {{0}, {0}}; // Initializing the board to be empty

// Function to print the current state of the board
void printBoard() {
    printf("     0   1   2   3   4   5   6   7\n");  // Column coordinates
    printf("   +---+---+---+---+---+---+---+---+\n");
    for(int i = 0; i < BOARD_SIZE; i++) {
        printf(" %d |", i);  // Row coordinates
        for(int j = 0; j < BOARD_SIZE; j++) {
            if(board[i][j] == 1)
                printf(" O |");   // O denotes player 1's checkers
            else if(board[i][j] == 2)
                printf(" X |");   // X denotes player 2's checkers
            else
                printf("   |");   // Empty space
        }
        printf("\n");
        printf("   +---+---+---+---+---+---+---+---+\n");
    }
}

// Function to initialize the board with player 1 and player 2's checkers
void initializeBoard() {
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            if((i + j) % 2 == 0 && i < 3)
                board[i][j] = 1;   // Player 1's checkers
            else if((i + j) % 2 == 0 && i > 4)
                board[i][j] = 2;   // Player 2's checkers
        }
    }
}

// Function to move a checker from (x1, y1) to (x2, y2)
void moveChecker(int player, int x1, int y1, int x2, int y2) {
    if(player == 1 && board[x1][y1] == 1) {  // Check if player 1 is moving their own checker
        if(x2 < BOARD_SIZE && y2 < BOARD_SIZE && board[x2][y2] == 0) {  // Check if the move is valid
            if(x2 == x1 + 1 && (y2 == y1 - 1 || y2 == y1 + 1)) {  // Player 1 can only move diagonally forward
                board[x1][y1] = 0;   // Remove the checker from the original position
                board[x2][y2] = 1;   // Place the checker in the new position
            }
            else if(x2 == x1 + 2 && ((y2 == y1 - 2 && board[x1+1][y1-1] == 2) || (y2 == y1 + 2 && board[x1+1][y1+1] == 2))) {
                // Player 1 can also capture an opponent's checker by jumping over it
                board[x1][y1] = 0;   // Remove the checker from the original position
                board[x1+1][(y1+y2)/2] = 0;   // Remove the opponent's checker
                board[x2][y2] = 1;   // Place the checker in the new position
            }
            else {
                printf("Invalid move\n");
            }
        }
        else {
            printf("Invalid position\n");
        }
    }
    else if(player == 2 && board[x1][y1] == 2) {  // Check if player 2 is moving their own checker
        if(x2 < BOARD_SIZE && y2 < BOARD_SIZE && board[x2][y2] == 0) {  // Check if the move is valid
            if(x2 == x1 - 1 && (y2 == y1 - 1 || y2 == y1 + 1)) {  // Player 2 can only move diagonally backward
                board[x1][y1] = 0;   // Remove the checker from the original position
                board[x2][y2] = 2;   // Place the checker in the new position
            }
            else if(x2 == x1 - 2 && ((y2 == y1 - 2 && board[x1-1][y1-1] == 1) || (y2 == y1 + 2 && board[x1-1][y1+1] == 1))) {
                // Player 2 can also capture an opponent's checker by jumping over it
                board[x1][y1] = 0;   // Remove the checker from the original position
                board[x1-1][(y1+y2)/2] = 0;   // Remove the opponent's checker
                board[x2][y2] = 2;   // Place the checker in the new position
            }
            else {
                printf("Invalid move\n");
            }
        }
        else {
            printf("Invalid position\n");
        }
    }
    else {
        printf("Invalid player or position\n");
    }
}

int main() {
    initializeBoard();      // Initialize the board with the checkers
    printBoard();           // Display the initial state of the board

    // Player 1's turn
    moveChecker(1, 2, 1, 3, 2);
    printBoard();

    // Player 2's turn
    moveChecker(2, 5, 2, 4, 3);
    printBoard();

    // Player 1's turn
    moveChecker(1, 3, 2, 4, 3);
    printBoard();

    // Player 2's turn
    moveChecker(2, 4, 3, 3, 2);
    printBoard();

    // Player 1's turn
    moveChecker(1, 2, 3, 4, 1);
    printBoard();

    return 0;
}