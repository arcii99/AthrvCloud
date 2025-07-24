//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: scalable
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define BOARD_SIZE 5

typedef struct {
    int value;
    bool marked;
} Cell;

typedef struct {
    Cell board[BOARD_SIZE][BOARD_SIZE];
} Board;

bool checkBingo(Board* board);
bool checkRow(Board* board, int row);
bool checkColumn(Board* board, int column);
bool checkDiagonal(Board* board);

int main() {
    // Seed random number generator
    srand((unsigned int) time(NULL));
    
    // Initialize board
    Board board;
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int col = 0; col < BOARD_SIZE; ++col) {
            board.board[row][col].value = rand() % 15 + (col * 15) + 1;
            board.board[row][col].marked = false;
        }
    }
    
    // Print initial board
    printf("Welcome to Bingo Simulator!\n");
    printf("Here's your Bingo board:\n");
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int col = 0; col < BOARD_SIZE; ++col) {
            printf("%2d ", board.board[row][col].value);
        }
        printf("\n");
    }
    
    // Play game
    int numDrawn = 0;
    int drawn[BOARD_SIZE * BOARD_SIZE];
    while (!checkBingo(&board)) {
        int nextNum = rand() % 75 + 1;
        
        // Check if number has already been drawn
        bool alreadyDrawn = false;
        for (int i = 0; i < numDrawn; ++i) {
            if (drawn[i] == nextNum) {
                alreadyDrawn = true;
                break;
            }
        }
        
        if (!alreadyDrawn) {
            printf("Number drawn: %d\n", nextNum);
            drawn[numDrawn++] = nextNum;
            
            // Mark cell on board if applicable
            for (int row = 0; row < BOARD_SIZE; ++row) {
                for (int col = 0; col < BOARD_SIZE; ++col) {
                    if (board.board[row][col].value == nextNum) {
                        board.board[row][col].marked = true;
                        break;
                    }
                }
            }
            
            // Print updated board
            printf("Updated board:\n");
            for (int row = 0; row < BOARD_SIZE; ++row) {
                for (int col = 0; col < BOARD_SIZE; ++col) {
                    if (board.board[row][col].marked) {
                        printf("** ");
                    } else {
                        printf("%2d ", board.board[row][col].value);
                    }
                }
                printf("\n");
            }
        }
    }
    
    printf("BINGO!!!\n");
    return 0;
}

bool checkBingo(Board* board) {
    for (int row = 0; row < BOARD_SIZE; ++row) {
        if (checkRow(board, row)) {
            return true;
        }
    }
    for (int col = 0; col < BOARD_SIZE; ++col) {
        if (checkColumn(board, col)) {
            return true;
        }
    }
    if (checkDiagonal(board)) {
        return true;
    }
    return false;
}

bool checkRow(Board* board, int row) {
    for (int col = 0; col < BOARD_SIZE; ++col) {
        if (!board->board[row][col].marked) {
            return false;
        }
    }
    return true;
}

bool checkColumn(Board* board, int column) {
    for (int row = 0; row < BOARD_SIZE; ++row) {
        if (!board->board[row][column].marked) {
            return false;
        }
    }
    return true;
}

bool checkDiagonal(Board* board) {
    bool leftToRight = true;
    bool rightToLeft = true;
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if (!board->board[i][i].marked) {
            leftToRight = false;
        }
        if (!board->board[i][BOARD_SIZE-1-i].marked) {
            rightToLeft = false;
        }
    }
    return leftToRight || rightToLeft;
}