//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int numbers[75];
    int num, row, col, count = 0;
    int board[5][5] = {{0}};
    int bingo = 0;
    srand(time(NULL));

    // Initialize array with numbers 1-75
    for (int i = 0; i < 75; i++) {
        numbers[i] = i+1;
    }

    // Shuffle array
    for (int i = 0; i < 75; i++) {
        int temp = numbers[i];
        int randomIndex = rand() % 75;
        numbers[i] = numbers[randomIndex];
        numbers[randomIndex] = temp;
    }

    // Print Bingo board
    printf("B   I   N   G   O\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 2 && j == 2) {
                printf("    ");
            } else {
                printf("%-3d ", board[i][j]);
            }
        }
        printf("\n");
    }

    // Generate random numbers and mark them on the board
    while (!bingo) {
        num = numbers[count];
        row = (num - 1) / 15;
        col = -1;
        if (num%15 == 0) {
            col = 4;
        } else {
            col = num%15/3;
        }
        if (board[row][col] == 0) {
            board[row][col] = num;
            count++;
            // Check for bingo
            if ((board[0][0] != 0 && board[0][1] != 0 && board[0][2] != 0 && board[0][3] != 0 && board[0][4] != 0) ||
                (board[1][0] != 0 && board[1][1] != 0 && board[1][2] != 0 && board[1][3] != 0 && board[1][4] != 0) ||
                (board[2][0] != 0 && board[2][1] != 0 && board[2][3] != 0 && board[2][3] != 0 && board[2][4] != 0) ||
                (board[3][0] != 0 && board[3][1] != 0 && board[3][2] != 0 && board[3][3] != 0 && board[3][4] != 0) ||
                (board[4][0] != 0 && board[4][1] != 0 && board[4][2] != 0 && board[4][3] != 0 && board[4][4] != 0) ||
                (board[0][0] != 0 && board[1][0] != 0 && board[2][0] != 0 && board[3][0] != 0 && board[4][0] != 0) ||
                (board[0][1] != 0 && board[1][1] != 0 && board[2][1] != 0 && board[3][1] != 0 && board[4][1] != 0) ||
                (board[0][2] != 0 && board[1][2] != 0 && board[2][2] != 0 && board[3][2] != 0 && board[4][2] != 0) ||
                (board[0][3] != 0 && board[1][3] != 0 && board[2][3] != 0 && board[3][3] != 0 && board[4][3] != 0) ||
                (board[0][4] != 0 && board[1][4] != 0 && board[2][4] != 0 && board[3][4] != 0 && board[4][4] != 0) ||
                (board[0][0] != 0 && board[1][1] != 0 && board[2][2] != 0 && board[3][3] != 0 && board[4][4] != 0) ||
                (board[0][4] != 0 && board[1][3] != 0 && board[2][2] != 0 && board[3][1] != 0 && board[4][0] != 0)) {
                bingo = 1;
            }
        }
    }

    // Print final Bingo board with winning message
    printf("\n\nB   I   N   G   O\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 2 && j == 2) {
                printf("    ");
            } else {
                printf("%-3d ", board[i][j]);
            }
        }
        printf("\n");
    }
    printf("\nBINGO!\n");

    return 0;
}