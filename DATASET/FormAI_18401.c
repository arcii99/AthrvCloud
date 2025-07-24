//FormAI DATASET v1.0 Category: Chess AI ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 8

// Initialize the chess board
char board[BOARD_SIZE][BOARD_SIZE] = {
    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
};

// Print the board
void print_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Generate a random move
int generate_move() {
    srand(time(NULL));
    return rand() % BOARD_SIZE;
}

int main() {
    int move = generate_move();
    printf("Random move: %d\n", move);
    print_board();
    return 0;
}