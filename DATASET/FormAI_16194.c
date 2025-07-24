//FormAI DATASET v1.0 Category: Chess AI ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 8

void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE] = {
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
        {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
        {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
        {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
    };

    printf("Initial board state:\n");
    print_board(board);

    // Random move generator
    srand(time(NULL));
    int from_row = rand() % BOARD_SIZE;
    int from_col = rand() % BOARD_SIZE;
    int to_row = rand() % BOARD_SIZE;
    int to_col = rand() % BOARD_SIZE;

    printf("\nRandom move: %c%d-%c%d\n", from_col + 'a', from_row + 1, to_col + 'a', to_row + 1);
    // Make the move
    board[to_row][to_col] = board[from_row][from_col];
    board[from_row][from_col] = '.';

    printf("\nBoard after move:\n");
    print_board(board);

    return 0;
}