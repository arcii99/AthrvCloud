//FormAI DATASET v1.0 Category: Game of Life ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 15
#define M 40

void generateInitialBoard(int board[N][M]) {
    srand(time(NULL)); // Seed random number generator
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            int r = rand() % 4; // Randomly generate a number between 0 and 3
            if(r == 0) board[i][j] = 1; // Set cell to be alive
            else board[i][j] = 0; // Set cell to be dead
        }
    }
}

void printBoard(int board[N][M]) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(board[i][j] == 1) printf("\u25A0 "); // Print a filled square for alive cells
            else printf("\u25A1 "); // Print an empty square for dead cells
        }
        printf("\n");
    }
    printf("\n");
}

void updateBoard(int board[N][M]) {
    int tempBoard[N][M];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            int count = 0;
            for(int k = -1; k <= 1; k++) { // Check all adjacent cells
                for(int l = -1; l <= 1; l++) {
                    if(k == 0 && l == 0) continue; // Skip current cell
                    if(i+k < 0 || i+k >= N || j+l < 0 || j+l >= M) continue; // Skip out-of-bounds cells
                    if(board[i+k][j+l] == 1) count++; // Increment count for alive cells
                }
            }
            if(board[i][j] == 1) { // Cell is alive
                if(count < 2 || count > 3) tempBoard[i][j] = 0; // Cell dies due to under/overpopulation
                else tempBoard[i][j] = 1; // Cell survives
            } else { // Cell is dead
                if(count == 3) tempBoard[i][j] = 1; // Cell becomes alive due to reproduction
                else tempBoard[i][j] = 0; // Cell remains dead
            }
        }
    }
    // Copy tempBoard to board
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            board[i][j] = tempBoard[i][j];
        }
    }
}

int main() {
    int board[N][M];
    generateInitialBoard(board);
    
    while(1) { // Infinite loop
        printBoard(board);
        updateBoard(board);
        sleep(1);
    }
    return 0;
}