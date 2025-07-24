//FormAI DATASET v1.0 Category: Memory Game ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void initialize (int board[ROWS][COLS]) {

    int i, j, value;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = 0;
        }
    }
    
    for (value = 1; value <= 8; value++) {
        for (i = 0; i < 2; i++) {
            do {
                j = rand() % COLS;
            } while (board[i][j] != 0);
            board[i][j] = value;
        }
    }

}

void display (int board[ROWS][COLS]) {

    int i, j;

    printf("\n\n");

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (board[i][j] == 0) {
                printf("    -");
            }
            else {
                printf("%5d", board[i][j]);
            }
        }
        printf("\n");
    }

}

void playgame () {

    int board[ROWS][COLS];
    int moves[ROWS][COLS];
    int i, j, r1, c1, r2, c2, count;
    int done, correct;

    srand(time(NULL));
    initialize(board);

    done = 0;
    count = 0;

    while (!done) {

        display(board);

        printf("\n\nEnter the row and column for the first card: ");
        scanf("%d %d", &r1, &c1);
        r1--;
        c1--;
        while ((r1 < 0 || r1 >= ROWS) || (c1 < 0 || c1 >= COLS) || (moves[r1][c1] == 1)) {
            printf("Invalid move. Enter the row and column for the first card: ");
            scanf("%d %d", &r1, &c1);
            r1--;
            c1--;
        }
        moves[r1][c1] = 1;
        printf("Card %d is at position [%d][%d].\n\n", board[r1][c1], r1+1, c1+1);

        display(board);

        printf("\n\nEnter the row and column for the second card: ");
        scanf("%d %d", &r2, &c2);
        r2--;
        c2--;
        while ((r2 < 0 || r2 >= ROWS) || (c2 < 0 || c2 >= COLS) || (moves[r2][c2] == 1)) {
            printf("Invalid move. Enter the row and column for the second card: ");
            scanf("%d %d", &r2, &c2);
            r2--;
            c2--;
        }
        moves[r2][c2] = 1;
        printf("Card %d is at position [%d][%d].\n\n", board[r2][c2], r2+1, c2+1);

        if (board[r1][c1] == board[r2][c2]) {
            printf("\n\nMatch!\n\n");
            correct++;
        }
        else {
            printf("\n\nNo match.\n\n");
        }

        count++;

        if (correct == 8) {
            done = 1;
        }

    }

    printf("\n\nCongratulations! You won in %d moves!\n\n", count);

}

int main () {

    char again = 'y';

    printf("\n\nWelcome to the Memory Game!\n\n");

    while (again == 'y' || again == 'Y') {
        playgame();
        printf("Would you like to play again? (y/n): ");
        scanf("%c", &again);
    }

    printf("\n\nGoodbye!\n\n");

    return 0;

}