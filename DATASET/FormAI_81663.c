//FormAI DATASET v1.0 Category: Memory Game ; Style: peaceful
// C Memory Game
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 4
#define COLS 4

void shuffleArray(int* array, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        int j = rand() % size;
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

void printBoard(char board[ROWS][COLS], int* revealed) {
    printf("-----------\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (revealed[i * COLS + j] == 1) {
                printf("%c ", board[i][j]);
            }
            else {
                printf("* ");
            }
        }
        printf("\n");
    }
    printf("-----------\n");
}

int main() {
    char board[ROWS][COLS] = {
        {'A', 'B', 'C', 'D'},
        {'D', 'C', 'B', 'A'},
        {'E', 'F', 'G', 'H'},
        {'H', 'G', 'F', 'E'}
    };
    int revealed[ROWS * COLS] = { 0 };
    int moves = 0;

    int pairs[ROWS*COLS];
    for (int i = 0; i < ROWS*COLS; i++) {
        pairs[i] = i;
    }
    shuffleArray(pairs, ROWS*COLS);

    while (1) {
        printBoard(board, revealed);
        int first, second;
        do {
            printf("Enter first card (row column): ");
            scanf("%d %d", &first, &second);
        } while (revealed[first * COLS + second] == 1);
        revealed[first * COLS + second] = 1;
        printBoard(board, revealed);
        do {
            printf("Enter second card (row column): ");
            scanf("%d %d", &first, &second);
        } while (revealed[first * COLS + second] == 1);
        revealed[first * COLS + second] = 1;
        printBoard(board, revealed);
        if (board[first][second] != board[pairs[first * COLS + second] / COLS][pairs[first * COLS + second] % COLS]) {
            revealed[first * COLS + second] = 0;
            revealed[pairs[first * COLS + second]] = 0;
            printf("Sorry, not a match.\n");
        }
        else {
            printf("Match!\n");
            moves++;
            if (moves == ROWS*COLS / 2) {
                printf("Congratulations, you won in %d moves!\n", moves);
                return 0;
            }
        }
    }
    return 0;
}