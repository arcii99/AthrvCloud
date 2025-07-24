//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_NUM 75

int main() {

    // Initialize the bingo board array
    int board[ROWS][COLS] = { 0 };

    // Initialize the B, I, N, G, O arrays
    int b[15], i[15], n[15], g[15], o[15];
    for (int j = 0; j < 15; j++) {
        b[j] = j + 1;
        i[j] = j + 16;
        n[j] = j + 31;
        g[j] = j + 46;
        o[j] = j + 61;
    }

    // Shuffle the arrays randomly
    srand(time(NULL));
    for (int k = 0; k < 15; k++) {

        // Swap a random element with a random element
        int bIndex = rand() % 15;
        int iIndex = rand() % 15;
        int nIndex = rand() % 15;
        int gIndex = rand() % 15;
        int oIndex = rand() % 15;

        int temp = b[bIndex];
        b[bIndex] = b[k];
        b[k] = temp;

        temp = i[iIndex];
        i[iIndex] = i[k];
        i[k] = temp;

        temp = n[nIndex];
        n[nIndex] = n[k];
        n[k] = temp;

        temp = g[gIndex];
        g[gIndex] = g[k];
        g[k] = temp;

        temp = o[oIndex];
        o[oIndex] = o[k];
        o[k] = temp;

    }

    // Main game loop
    int numCalled = 0;
    while (numCalled < MAX_NUM) {

        // Print the current board
        printf("\n===================\n\n");
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (board[r][c] != 0) {
                    printf("%3d ", board[r][c]);
                } else {
                    printf(" -- ");
                }
            }
            printf("\n");
        }

        // Generate a random number and check if it has been called
        int num = rand() % MAX_NUM + 1;
        int isValid = 0;
        for (int j = 0; j < 15; j++) {
            if (b[j] == num || i[j] == num || n[j] == num || g[j] == num || o[j] == num) {
                isValid = 1;
                break;
            }
        }
        if (!isValid) {
            continue;
        }

        numCalled++;

        // Mark the number on the board if it is present
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (board[r][c] == num) {
                    board[r][c] = -num;
                }
            }
        }

        // Print the called number
        printf("\n\nNumber called: %d\n\n", num);

        // Check for a bingo
        int bingo = 0;

        // Check rows
        for (int r = 0; r < ROWS; r++) {
            int rowSum = 0;
            for (int c = 0; c < COLS; c++) {
                rowSum += board[r][c];
            }
            if (rowSum == -5*num || rowSum == 0) {
                bingo = 1;
            }
        }

        // Check columns
        for (int c = 0; c < COLS; c++) {
            int colSum = 0;
            for (int r = 0; r < ROWS; r++) {
                colSum += board[r][c];
            }
            if (colSum == -5*num || colSum == 0) {
                bingo = 1;
            }
        }

        // Check diagonals
        int diag1Sum = board[0][0] + board[1][1] + board[2][2] + board[3][3] + board[4][4];
        int diag2Sum = board[0][4] + board[1][3] + board[2][2] + board[3][1] + board[4][0];
        if (diag1Sum == -5*num || diag1Sum == 0 || diag2Sum == -5*num || diag2Sum == 0) {
            bingo = 1;
        }

        if (bingo) {
            printf("\n\n!!! BINGO !!!\n\n");
            break;
        }

    }

    printf("\n\nGame over!\n\n");

    return 0;
}