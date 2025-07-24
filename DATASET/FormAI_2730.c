//FormAI DATASET v1.0 Category: Chess AI ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 8

int board[BOARD_SIZE][BOARD_SIZE]; // the board
int turn = 1; // turn tracker, 1 is white, -1 is black

// function to print the board
void printBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// function to check if a move is valid
int isValidMove(int fromX, int fromY, int toX, int toY) {
    // check if move is out of bounds
    if (fromX < 0 || fromY < 0 || toX < 0 || toY < 0 || fromX >= BOARD_SIZE || fromY >= BOARD_SIZE || toX >= BOARD_SIZE || toY >= BOARD_SIZE) {
        return 0;
    }
    // check if piece being moved belongs to the correct player
    if (board[fromX][fromY] * turn < 0) {
        return 0;
    }
    // check if the destination square contains a piece of the same color
    if (board[toX][toY] * turn > 0) {
        return 0;
    }
    // check if move follows rules of chess
    // for simplicity, assume all pieces move like pawns
    if (abs(toX - fromX) == 1 && toY - fromY == turn && board[toX][toY] == 0) {
        return 1;
    }
    return 0;
}

// function to make a move
int makeMove(int fromX, int fromY, int toX, int toY) {
    if (isValidMove(fromX, fromY, toX, toY)) {
        board[toX][toY] = board[fromX][fromY];
        board[fromX][fromY] = 0;
        turn *= -1;
        return 1;
    }
    return 0;
}

// main game loop
int main() {
    srand(time(NULL));
    // initialize board with pieces
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i][1] = 1; // white pawns
        board[i][6] = -1; // black pawns
    }
    // print initial board
    printf("Starting position:\n");
    printBoard();
    
    // game loop
    while (1) {
        // generate a random valid move for the current player
        int fromX, fromY, toX, toY;
        do {
            fromX = rand() % BOARD_SIZE;
            fromY = rand() % BOARD_SIZE;
            toX = rand() % BOARD_SIZE;
            toY = rand() % BOARD_SIZE;
        } while (!isValidMove(fromX, fromY, toX, toY) || board[fromX][fromY] * turn < 0);
        printf("Player %d moves: (%d,%d) -> (%d,%d)\n", turn, fromX, fromY, toX, toY);
        makeMove(fromX, fromY, toX, toY);
        // print updated board
        printBoard();
        // check for end of game
        int whiteCount = 0, blackCount = 0;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] > 0) {
                    whiteCount++;
                } else if (board[i][j] < 0) {
                    blackCount++;
                }
            }
        }
        if (whiteCount == 0) {
            printf("Game over! Black wins!\n");
            break;
        } else if (blackCount == 0) {
            printf("Game over! White wins!\n");
            break;
        }
    }
    return 0;
}