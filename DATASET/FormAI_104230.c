//FormAI DATASET v1.0 Category: Chess AI ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the board
char board[8][8] = {
    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
};

// Function to print the board
void print_board() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to get a random move
void get_random_move(int *from_row, int *from_col, int *to_row, int *to_col) {
    *from_row = rand() % 8;
    *from_col = rand() % 8;
    *to_row = rand() % 8;
    *to_col = rand() % 8;
}

// Function to make a move
void make_move(int from_row, int from_col, int to_row, int to_col) {
    board[to_row][to_col] = board[from_row][from_col];
    board[from_row][from_col] = ' ';
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Print the initial board
    print_board();

    // Get a random move
    int from_row, from_col, to_row, to_col;
    get_random_move(&from_row, &from_col, &to_row, &to_col);

    // Make the move and print the board again
    make_move(from_row, from_col, to_row, to_col);
    print_board();

    return 0;
}