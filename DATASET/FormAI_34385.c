//FormAI DATASET v1.0 Category: Chess AI ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// Global array for Chess board
char board[8][8];

// Function to initialize the Chess board
void init_board() {
    char position[] = "RNBQKBNRPPPPPPPP                                pppppppprnbqkbnr";
    int i, j, index;
    for (i=0; i<8; ++i) {
        for (j=0; j<8; ++j) {
            index = i*8+j;
            board[i][j] = position[index];
        }
    }
}

// Function to print the Chess board
void print_board() {
    int i, j;
    for (i=0; i<8; ++i) {
        for (j=0; j<8; ++j) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a given position is empty
bool is_empty(int row, int col) {
    return board[row][col] == ' ';
}

// Function to check if a given position contains a White piece
bool is_white(int row, int col) {
    return isupper(board[row][col]);
}

// Function to check if a given position contains a Black piece
bool is_black(int row, int col) {
    return islower(board[row][col]);
}

// Function to check if a given position is out of bounds
bool out_of_bounds(int row, int col) {
    return row < 0 || row > 7 || col < 0 || col > 7;
}

// Main function for the Chess AI program
int main() {
    printf("Welcome to the cheerful Chess AI program!\n");
    printf("Let's play Chess!\n\n");
    init_board();
    print_board();
    return 0;
}