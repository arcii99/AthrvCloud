//FormAI DATASET v1.0 Category: Memory Game ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

char cards[ROWS][COLS];
char cardsFlipped[ROWS][COLS];
char cardsMatched[ROWS][COLS];

void initCards() {
    char curCardValue = 'A';
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cards[i][j] = curCardValue;
            curCardValue++;
        }
    }
}

void shuffleCards() {
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int newI = rand() % ROWS;
            int newJ = rand() % COLS;
            char tmp = cards[i][j];
            cards[i][j] = cards[newI][newJ];
            cards[newI][newJ] = tmp;
        }
    }
}

void printCards() {
    printf("  1 2 3 4\n");
    for (int i = 0; i < ROWS; i++) {
        printf("%d ", i+1);
        for (int j = 0; j < COLS; j++) {
            if (cardsMatched[i][j]) {
                printf("%c ", cards[i][j]);
            } else if (cardsFlipped[i][j]) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int findMatches(int row1, int col1, int row2, int col2) {
    if (cards[row1][col1] == cards[row2][col2]) {
        printf("You found a match!\n");
        cardsMatched[row1][col1] = 1;
        cardsMatched[row2][col2] = 1;
        return 1;
    } else {
        printf("Sorry, those cards don't match.\n");
        cardsFlipped[row1][col1] = 0;
        cardsFlipped[row2][col2] = 0;
        return 0;
    }
}

int main() {
    printf("Welcome to the Memory Game!\n\n");
    printf("The goal of the game is to find all the matching pairs of cards.\n");
    printf("To flip a card, enter the row and column numbers (e.g. '1 2').\n");
    printf("The game ends when all matching pairs are found.\n");

    initCards();
    shuffleCards();

    int numMatches = 0;

    while (numMatches < ROWS*COLS/2) {
        printCards();
        int row1, col1, row2, col2;
        printf("\nEnter the row and column numbers of the first card to flip: ");
        scanf("%d %d", &row1, &col1);
        row1--;
        col1--;
        while (cardsFlipped[row1][col1] || cardsMatched[row1][col1]) {
            printf("That card is already revealed. Please choose a different card.\n");
            printf("\nEnter the row and column numbers of the first card to flip: ");
            scanf("%d %d", &row1, &col1);
            row1--;
            col1--;
        }
        cardsFlipped[row1][col1] = 1;

        printCards();
        printf("\nEnter the row and column numbers of the second card to flip: ");
        scanf("%d %d", &row2, &col2);
        row2--;
        col2--;
        while (cardsFlipped[row2][col2] || cardsMatched[row2][col2] || (row1 == row2 && col1 == col2)) {
            if (row1 == row2 && col1 == col2) {
                printf("You cannot flip the same card twice. Please choose a different card.\n");
            } else {
                printf("That card is already revealed. Please choose a different card.\n");
            }
            printf("\nEnter the row and column numbers of the second card to flip: ");
            scanf("%d %d", &row2, &col2);
            row2--;
            col2--;
        }
        cardsFlipped[row2][col2] = 1;

        numMatches += findMatches(row1, col1, row2, col2);
    }

    printf("Congratulations, you found all the matching pairs!\n");

    return 0;
}