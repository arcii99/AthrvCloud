//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 32
#define HEIGHT 32

void fillBoard(char board[WIDTH][HEIGHT]) {
    // Fills the board with random pixel art
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            board[i][j] = rand() % 2 == 0 ? 'X' : 'O';
        }
    }
}

void printBoard(char board[WIDTH][HEIGHT]) {
    // Prints the board to the console
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c ", board[j][i]);
        }
        printf("\n");
    }
}

int main() {
    char board[WIDTH][HEIGHT];
    srand(time(NULL));

    fillBoard(board);
    printBoard(board);

    return 0;
}