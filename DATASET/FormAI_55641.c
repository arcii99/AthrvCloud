//FormAI DATASET v1.0 Category: Memory Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLUMNS 4

void shuffle(int board[ROWS][COLUMNS]) {
    int i, j, k, l;

    srand(time(NULL));

    for (i = ROWS - 1; i > 0; i--) {
        for (j = COLUMNS - 1; j > 0; j--) {
            k = rand() % (i + 1);
            l = rand() % (j + 1);

            int temp = board[i][j];
            board[i][j] = board[k][l];
            board[k][l] = temp;
        }
    }
}

void print_board(int board[ROWS][COLUMNS], int revealed[ROWS][COLUMNS]) {
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            if (revealed[i][j]) {
                printf("%2d ", board[i][j]);
            } else {
                printf("?? ");
            }
        }
        printf("\n");
    }
}

int main() {
    int board[ROWS][COLUMNS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    int revealed[ROWS][COLUMNS] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    shuffle(board);

    printf("Welcome to Memory Game!\n\n");

    int i, j, count = 0;
    int firstRow, firstColumn, secondRow, secondColumn;

    while (1) {
        printf("Turn %d\n", count + 1);
        print_board(board, revealed);

        printf("Enter the coordinates of the first card (row column): ");
        scanf("%d %d", &firstRow, &firstColumn);

        while (revealed[firstRow][firstColumn]) {
            printf("This card has already been revealed. Please try again.\n");
            printf("Enter the coordinates of the first card (row column): ");
            scanf("%d %d", &firstRow, &firstColumn);
        }

        revealed[firstRow][firstColumn] = 1;

        print_board(board, revealed);

        printf("Enter the coordinates of the second card (row column): ");
        scanf("%d %d", &secondRow, &secondColumn);

        while (revealed[secondRow][secondColumn]) {
            printf("This card has already been revealed. Please try again.\n");
            printf("Enter the coordinates of the second card (row column): ");
            scanf("%d %d", &secondRow, &secondColumn);
        }

        revealed[secondRow][secondColumn] = 1;

        print_board(board, revealed);

        if (board[firstRow][firstColumn] != board[secondRow][secondColumn]) {
            printf("Sorry, those cards do not match. Try again.\n");
            revealed[firstRow][firstColumn] = 0;
            revealed[secondRow][secondColumn] = 0;
        } else {
            printf("Congratulations, you found a match!\n");
        }

        count++;

        if (count == ROWS * COLUMNS / 2) {
            printf("You win! You matched all the cards in %d turns.\n", count);
            break;
        }
    }

    return 0;
}