//FormAI DATASET v1.0 Category: Funny ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 8

int main() {
    // Initialize board with random integers between 0 and 9
    int board[BOARD_SIZE][BOARD_SIZE];
    srand(time(NULL));
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = rand() % 10;
        }
    }

    // Print the initial board
    printf("Initial board:\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    // Flip all numbers in row 3
    for (int j = 0; j < BOARD_SIZE; j++) {
        board[2][j] = 9 - board[2][j];
    }
    
    // Print the board after flipping row 3
    printf("\nBoard after flipping row 3:\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    // Replace all even numbers with the sum of their neighbors
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] % 2 == 0) {
                int sum_neighbors = 0;
                if (i > 0) {
                    sum_neighbors += board[i-1][j];
                }
                if (i < BOARD_SIZE-1) {
                    sum_neighbors += board[i+1][j];
                }
                if (j > 0) {
                    sum_neighbors += board[i][j-1];
                }
                if (j < BOARD_SIZE-1) {
                    sum_neighbors += board[i][j+1];
                }
                board[i][j] = sum_neighbors;
            }
        }
    }

    // Print the final board
    printf("\nFinal board:\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}