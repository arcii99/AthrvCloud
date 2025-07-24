//FormAI DATASET v1.0 Category: Memory Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void printBoard(char board[][COLS]) {
    printf("\n\n");

    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void generateRandomPairs(char *pairs) {
    for(int i = 0; i < ROWS * COLS / 2; i++) {
        pairs[i * 2] = 'A' + i;
        pairs[i * 2 + 1] = 'A' + i;
    }
}

void shufflePairs(char *pairs) {
    for(int i = 0; i < ROWS * COLS / 2; i++) {
        int index1 = rand() % (ROWS * COLS / 2);
        int index2 = rand() % (ROWS * COLS / 2);
        char temp = pairs[index1];
        pairs[index1] = pairs[index2];
        pairs[index2] = temp;
    }
}

void initializeBoard(char board[][COLS], char *pairs) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            board[i][j] = pairs[i * COLS + j];
        }
    }
}

int main() {
    srand(time(NULL));

    char pairs[ROWS * COLS];
    generateRandomPairs(pairs);
    shufflePairs(pairs);

    char board[ROWS][COLS];
    initializeBoard(board, pairs);
    printBoard(board);

    return 0;
}