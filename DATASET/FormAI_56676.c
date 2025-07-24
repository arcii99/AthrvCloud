//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 5
#define MAX_NUM 75

int main()
{
    int board[BOARD_SIZE][BOARD_SIZE];
    int numCalls = 0;
    int numCalled[MAX_NUM] = {0};

    // Initialize random number generator
    srand(time(NULL));

    // Fill the board with zeros
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }

    // Generate random numbers and mark them on board
    while (numCalls < MAX_NUM) {
        int num = rand() % MAX_NUM + 1;
        numCalled[num - 1]++;
        printf("Number called: %d\n", num);

        // Mark the number on the board
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == num) {
                    board[i][j] = -num;
                }
            }
        }

        // Check for bingo
        for (int i = 0; i < BOARD_SIZE; i++) {
            int rowSum = 0;
            int colSum = 0;
            int diagSum1 = 0;
            int diagSum2 = 0;

            for (int j = 0; j < BOARD_SIZE; j++) {
                // Check row
                rowSum += board[i][j];

                // Check column
                colSum += board[j][i];

                // Check diagonal 1
                if (i == j) {
                    diagSum1 += board[i][j];
                }

                // Check diagonal 2
                if (i + j == BOARD_SIZE - 1) {
                    diagSum2 += board[i][j];
                }
            }

            // Check if any row, column or diagonal is completed
            if (rowSum == -5 || colSum == -5 || diagSum1 == -5 || diagSum2 == -5) {
                printf("Bingo!\n");
                return 0;
            }
        }

        // Print the board
        printf("Board:\n");
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                printf("%3d ", board[i][j]);
            }
            printf("\n");
        }
        printf("\n");

        numCalls++;
    }

    // Print the number of times each number was called
    printf("Number of times each number was called:\n");
    for (int i = 0; i < MAX_NUM; i++) {
        printf("%3d: %d\n", i+1, numCalled[i]);
    }

    printf("No Bingo!\n");
    return 0;
}