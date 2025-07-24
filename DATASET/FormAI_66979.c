//FormAI DATASET v1.0 Category: Memory Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLUMNS 4

void initializeBoard(int board[ROWS][COLUMNS]);
void shuffleBoard(int board[ROWS][COLUMNS]);
void printBoard(int board[ROWS][COLUMNS]);
void playGame(int board[ROWS][COLUMNS]);

int main() {
    int board[ROWS][COLUMNS];
    
    srand(time(NULL));

    initializeBoard(board);
    shuffleBoard(board);
    printBoard(board);
    playGame(board);

    return 0;
}

void initializeBoard(int board[ROWS][COLUMNS]) {
    int count = 1;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            board[i][j] = count;
            count++;
        }
    }
}

void shuffleBoard(int board[ROWS][COLUMNS]) {
    int temp, row1, col1, row2, col2;

    for(int i = 0; i < 100; i++) {
        row1 = rand() % ROWS;
        col1 = rand() % COLUMNS;
        row2 = rand() % ROWS;
        col2 = rand() % COLUMNS;

        temp = board[row1][col1];
        board[row1][col1] = board[row2][col2];
        board[row2][col2] = temp;
    }
}

void printBoard(int board[ROWS][COLUMNS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            printf("%d\t", board[i][j]);
        }
        printf("\n");
    }
}

void playGame(int board[ROWS][COLUMNS]) {
    int row1, col1, row2, col2;
    int revealed[ROWS][COLUMNS] = {0};
    int count = 0;

    while (count < ROWS * COLUMNS) {
        printf("Enter the row and column of two cards: ");
        scanf("%d %d %d %d", &row1, &col1, &row2, &col2);

        if (row1 < 0 || row1 >= ROWS || col1 < 0 || col1 >= COLUMNS ||
            row2 < 0 || row2 >= ROWS || col2 < 0 || col2 >= COLUMNS) {
            printf("Invalid input\n");
            continue;
        }

        if (revealed[row1][col1] || revealed[row2][col2]) {
            printf("Already revealed\n");
            continue;
        }

        printf("Card 1: %d\n", board[row1][col1]);
        printf("Card 2: %d\n", board[row2][col2]);

        if (board[row1][col1] == board[row2][col2]) {
            printf("Match found\n");
            revealed[row1][col1] = revealed[row2][col2] = 1;
            count += 2;

            if (count == ROWS * COLUMNS) {
                printf("Game over. You won!\n");
                return;
            }
        } else {
            printf("No match\n");
        }
    }
}