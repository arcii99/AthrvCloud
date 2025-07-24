//FormAI DATASET v1.0 Category: Chess engine ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8
#define WHITE 'w'
#define BLACK 'b'

// Struct for storing the position of a piece
typedef struct {
    int row;
    int col;
} Position;

// Struct for storing a Chess piece
typedef struct {
    char type;
    char color;
    Position pos;
} Piece;

// Initialize the Chess board with starting positions
Piece board[SIZE][SIZE] = {
        {'R', WHITE, {8, 1}}, {'N', WHITE, {8, 2}}, {'B', WHITE, {8, 3}}, {'Q', WHITE, {8, 4}},
        {'K', WHITE, {8, 5}}, {'B', WHITE, {8, 6}}, {'N', WHITE, {8, 7}}, {'R', WHITE, {8, 8}},
        {'P', WHITE, {7, 1}}, {'P', WHITE, {7, 2}}, {'P', WHITE, {7, 3}}, {'P', WHITE, {7, 4}},
        {'P', WHITE, {7, 5}}, {'P', WHITE, {7, 6}}, {'P', WHITE, {7, 7}}, {'P', WHITE, {7, 8}},
        {'R', BLACK, {1, 1}}, {'N', BLACK, {1, 2}}, {'B', BLACK, {1, 3}}, {'Q', BLACK, {1, 4}},
        {'K', BLACK, {1, 5}}, {'B', BLACK, {1, 6}}, {'N', BLACK, {1, 7}}, {'R', BLACK, {1, 8}},
        {'P', BLACK, {2, 1}}, {'P', BLACK, {2, 2}}, {'P', BLACK, {2, 3}}, {'P', BLACK, {2, 4}},
        {'P', BLACK, {2, 5}}, {'P', BLACK, {2, 6}}, {'P', BLACK, {2, 7}}, {'P', BLACK, {2, 8}}
};

/**
 * Print the Chess board
 */
void printBoard() {
    for(int row=0; row<SIZE; row++) {
        for(int col=0; col<SIZE; col++) {
            printf("%c ", board[row][col].type);
        }
        printf("\n");
    }
}

/**
 * Main function to run the program
 */
int main() {
    printf("== Welcome to the Chess engine ==\n\n");
    printBoard();
    return 0;
}