//FormAI DATASET v1.0 Category: Checkers Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

// Define the board size as a constant
#define BOARD_SIZE 8

// Define the pieces as constants
#define EMPTY 0
#define BLACK 1
#define RED 2

// Global variables
int board[BOARD_SIZE][BOARD_SIZE];
int player = BLACK; // BLACK player starts the game

// Function prototypes
void initBoard();
void printBoard();
int isValidMove(int x, int y, int newX, int newY);
void makeMove(int x, int y, int newX, int newY);
int isGameOver();
int countPieces(int piece);

// Main function
int main() {
    int x = 0, y = 0, newX = 0, newY = 0;
    initBoard();
    while (!isGameOver()) {
        printf("Player %d's turn\n", player);
        printBoard();
        printf("Enter x and y coordinates: ");
        scanf("%d %d", &x, &y);
        printf("Enter new x and y coordinates: ");
        scanf("%d %d", &newX, &newY);
        if (isValidMove(x, y, newX, newY)) {
            makeMove(x, y, newX, newY);
            if (player == BLACK) {
                player = RED;
            } else {
                player = BLACK;
            }
        } else {
            printf("Invalid move, try again!\n");
        }
    }
    printf("Game over!\n");
    printf("Player %d won!\n", player == BLACK ? RED : BLACK);
    return 0;
}

// Function to initialize the board
void initBoard() {
    // Set all squares to EMPTY
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }
    // Set BLACK pieces
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i+j) % 2 == 0) {
                board[i][j] = BLACK;
            }
        }
    }
    // Set RED pieces
    for (int i = BOARD_SIZE-3; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i+j) % 2 == 0) {
                board[i][j] = RED;
            }
        }
    }
}

// Function to print the board
void printBoard() {
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            switch (board[i][j]) {
                case EMPTY:
                    printf(". ");
                    break;
                case BLACK:
                    printf("B ");
                    break;
                case RED:
                    printf("R ");
                    break;
            }
        }
        printf("%d\n", i);
    }
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");
}

// Function to check if a move is valid
int isValidMove(int x, int y, int newX, int newY) {
    // Check if start and end squares are within the board
    if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE
        || newX < 0 || newX >= BOARD_SIZE || newY < 0 || newY >= BOARD_SIZE) {
            return 0;
    }
    // Check if end square is empty
    if (board[newX][newY] != EMPTY) {
        return 0;
    }
    // Check if the right player is moving
    if (board[x][y] != player) {
        return 0;
    }
    // Check if the move is diagonal
    if (abs(newX-x) != abs(newY-y)) {
        return 0;
    }
    // Check if the move is a single step
    if (abs(newX-x) > 2) {
        return 0;
    }
    // Check if the move is a capture
    if (abs(newX-x) == 2) {
        int captureX = (newX+x)/2;
        int captureY = (newY+y)/2;
        if (board[captureX][captureY] == EMPTY || board[captureX][captureY] == player) {
            return 0;
        }
    }
    return 1;
}

// Function to make a move
void makeMove(int x, int y, int newX, int newY) {
    board[newX][newY] = board[x][y];
    board[x][y] = EMPTY;
    // Check if the move is a capture
    if (abs(newX-x) == 2) {
        int captureX = (newX+x)/2;
        int captureY = (newY+y)/2;
        board[captureX][captureY] = EMPTY;
    }
    // Check if a piece has reached the end of the board
    if (board[newX][newY] == BLACK && newX == BOARD_SIZE-1) {
        board[newX][newY] = BLACK+1;
    }
    if (board[newX][newY] == RED && newX == 0) {
        board[newX][newY] = RED+1;
    }
}

// Function to check if the game is over
int isGameOver() {
    // Check if a player has no pieces left
    if (countPieces(player) == 0) {
        return 1;
    }
    // Check if a player cannot make any more moves
    int canMove = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == player || board[i][j] == player+1) {
                for (int k = -2; k <= 2; k++) {
                    for (int l = -2; l <= 2; l++) {
                        if (isValidMove(i, j, i+k, j+l)) {
                            canMove = 1;
                        }
                    }
                }
            }
        }
    }
    if (canMove == 0) {
        return 1;
    }
    return 0;
}

// Function to count the number of pieces of a certain type
int countPieces(int piece) {
    int count = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == piece) {
                count++;
            }
        }
    }
    return count;
}