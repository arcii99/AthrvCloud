//FormAI DATASET v1.0 Category: Memory Game ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int BOARD_SIZE = 4;

void generateBoard(int board[][BOARD_SIZE]) {
    int numPairs = (BOARD_SIZE * BOARD_SIZE) / 2;
    int pairs[numPairs];
    for (int i = 0; i < numPairs; i++) {
        pairs[i] = i;
    }

    srand(time(NULL));
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            int index = rand() % numPairs;
            board[i][j] = pairs[index];
            pairs[index] = pairs[numPairs - 1];
            numPairs--;
        }
    }
}

void printBoard(int board[][BOARD_SIZE], int revealed[][BOARD_SIZE]) {
    printf("   0 1 2 3\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (revealed[i][j]) {
                printf("%d ", board[i][j]);
            } else {
                printf("X ");
            }
        }
        printf("\n");
    }
}

int main(void) {
    int board[BOARD_SIZE][BOARD_SIZE];
    int revealed[BOARD_SIZE][BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            revealed[i][j] = 0;
        }
    }
    generateBoard(board);

    int numPairsFound = 0;
    while (numPairsFound < (BOARD_SIZE * BOARD_SIZE) / 2) {
        printBoard(board, revealed);

        int x1, y1, x2, y2;
        printf("Enter first card coordinates: ");
        scanf("%d %d", &x1, &y1);

        while (revealed[x1][y1] == 1) {
            printf("That card has already been revealed. Enter new coordinates: ");
            scanf("%d %d", &x1, &y1);
        }

        revealed[x1][y1] = 1;
        printBoard(board, revealed);

        printf("Enter second card coordinates: ");
        scanf("%d %d", &x2, &y2);

        while (revealed[x2][y2] == 1) {
            printf("That card has already been revealed. Enter new coordinates: ");
            scanf("%d %d", &x2, &y2);
        }

        revealed[x2][y2] = 1;
        printBoard(board, revealed);

        if (board[x1][y1] == board[x2][y2]) {
            printf("Pair found!\n");
            numPairsFound++;
        } else {
            printf("No pair found.\n");
            revealed[x1][y1] = 0;
            revealed[x2][y2] = 0;
        }
    }

    printf("Congratulations! You have found all pairs.\n");
    return 0;
}