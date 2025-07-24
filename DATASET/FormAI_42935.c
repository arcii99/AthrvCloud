//FormAI DATASET v1.0 Category: Memory Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4

void print_board(int board[SIZE][SIZE], int opened[SIZE][SIZE]) {
    printf("  1 2 3 4 \n");
    for (int i = 0; i < SIZE; i++) {
        printf("%c ", i + 'A');
        for (int j = 0; j < SIZE; j++) {
            if (opened[i][j] == 1) {
                printf("%d ", board[i][j]);
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }
}

int main(void) {
    int board[SIZE][SIZE] = {0};
    int opened[SIZE][SIZE] = {0};
    int count = 0;
    srand(time(NULL));
    for (int n = 1; n <= 8; n++) {
        for (int c = 1; c <= 2; c++) {
            int i, j;
            do {
                i = rand() % SIZE;
                j = rand() % SIZE;
            } while (board[i][j] != 0);
            board[i][j] = n;
        }
    }
    printf("Welcome to the Memory Game!\n");
    printf("Match all pairs of numbers to win the game.\n");
    print_board(board, opened);
    while (count < SIZE*SIZE/2) {
        printf("Enter the location of the first card (e.g. A1): ");
        char c1, c2;
        int r1, r2;
        scanf(" %c%d", &c1, &r1);
        r1--;
        c1 = c1 - 'A';
        while (opened[c1][r1] == 1) {
            printf("This card is already opened. Enter the location of another card: ");
            scanf(" %c%d", &c1, &r1);
            r1--;
            c1 = c1 - 'A';
        }
        opened[c1][r1] = 1;
        print_board(board, opened);
        printf("Enter the location of the second card (e.g. B2): ");
        scanf(" %c%d", &c2, &r2);
        r2--;
        c2 = c2 - 'A';
        while (opened[c2][r2] == 1) {
            printf("This card is already opened. Enter the location of another card: ");
            scanf(" %c%d", &c2, &r2);
            r2--;
            c2 = c2 - 'A';
        }
        opened[c2][r2] = 1;
        print_board(board, opened);
        if (board[c1][r1] == board[c2][r2]) {
            printf("Match!\n");
            count++;
        } else {
            printf("Not a match!\n");
            opened[c1][r1] = 0;
            opened[c2][r2] = 0;
        }
    }
    printf("Congratulations! You won the game!\n");
    return 0;
}