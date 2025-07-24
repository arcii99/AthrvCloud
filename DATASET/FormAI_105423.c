//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printBingoBoard(int board[5][5], int mode) {
    printf("\n");
    if (mode == 0) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                printf("%d\t", board[i][j]);
            }
            printf("\n");
        }
    } else {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (board[i][j] == -1) {
                    printf("X\t");
                } else {
                    printf("%d\t", board[i][j]);
                }
            }
            printf("\n");
        }
    }
}

int main() {
    int board[5][5];

    // Seed random number generator
    srand(time(NULL));

    // Initialize board with randomly generated numbers
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            board[i][j] = rand() % 25 + 1;
        }
    }

    // Set center square to -1 to represent free space
    board[2][2] = -1;

    printf("Here is your Bingo board:\n");
    printBingoBoard(board, 0);

    // Start game loop
    int numCalled = 0;
    while (1) {

        // Generate random number between 1 and 25
        int called = rand() % 25 + 1;
        printf("Number called: %d\n", called);

        // Mark called number on board
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (board[i][j] == called) {
                    board[i][j] = -1;
                    numCalled++;
                }
            }
        }

        // Print updated board
        printf("Here is your updated Bingo board:\n");
        printBingoBoard(board, 1);

        // Check if player has won
        if (board[0][0] == -1 && board[0][1] == -1 && board[0][2] == -1 && board[0][3] == -1 && board[0][4] == -1) {
            printf("BINGO! You've won!\n");
            break;
        } else if (board[1][0] == -1 && board[1][1] == -1 && board[1][2] == -1 && board[1][3] == -1 && board[1][4] == -1) {
            printf("BINGO! You've won!\n");
            break;
        } else if (board[2][0] == -1 && board[2][1] == -1 && board[2][2] == -1 && board[2][3] == -1 && board[2][4] == -1) {
            printf("BINGO! You've won!\n");
            break;
        } else if (board[3][0] == -1 && board[3][1] == -1 && board[3][2] == -1 && board[3][3] == -1 && board[3][4] == -1) {
            printf("BINGO! You've won!\n");
            break;
        } else if (board[4][0] == -1 && board[4][1] == -1 && board[4][2] == -1 && board[4][3] == -1 && board[4][4] == -1) {
            printf("BINGO! You've won!\n");
            break;
        } else if (board[0][0] == -1 && board[1][0] == -1 && board[2][0] == -1 && board[3][0] == -1 && board[4][0] == -1) {
            printf("BINGO! You've won!\n");
            break;
        } else if (board[0][1] == -1 && board[1][1] == -1 && board[2][1] == -1 && board[3][1] == -1 && board[4][1] == -1) {
            printf("BINGO! You've won!\n");
            break;
        } else if (board[0][2] == -1 && board[1][2] == -1 && board[2][2] == -1 && board[3][2] == -1 && board[4][2] == -1) {
            printf("BINGO! You've won!\n");
            break;
        } else if (board[0][3] == -1 && board[1][3] == -1 && board[2][3] == -1 && board[3][3] == -1 && board[4][3] == -1) {
            printf("BINGO! You've won!\n");
            break;
        } else if (board[0][4] == -1 && board[1][4] == -1 && board[2][4] == -1 && board[3][4] == -1 && board[4][4] == -1) {
            printf("BINGO! You've won!\n");
            break;
        } else if (board[0][0] == -1 && board[1][1] == -1 && board[2][2] == -1 && board[3][3] == -1 && board[4][4] == -1) {
            printf("BINGO! You've won!\n");
            break;
        } else if (board[0][4] == -1 && board[1][3] == -1 && board[2][2] == -1 && board[3][1] == -1 && board[4][0] == -1) {
            printf("BINGO! You've won!\n");
            break;
        }

        // Check if all numbers have been called
        if (numCalled == 25) {
            printf("Sorry, you didn't win. Better luck next time!\n");
            break;
        }

        printf("Press enter to continue...");
        getchar();
    }

    return 0;
}