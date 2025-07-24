//FormAI DATASET v1.0 Category: Memory Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int main() {
    int board[SIZE][SIZE];  // the game board
    int pairs_found = 0;  // number of pairs found by the player
    int x1, y1, x2, y2;   // the coordinates of the cards selected by the player
    int i, j;

    srand(time(NULL));    // seed the random number generator

    // randomly place the cards on the board
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            board[i][j] = rand() % (SIZE * SIZE / 2) + 1;  // each card has a unique value from 1 to SIZE * SIZE / 2
        }
    }

    // print the initial board
    printf("Welcome to the Memory Game!\n\n");
    printf("Find all the pairs of cards by selecting two cards at a time.\n");
    printf("The goal is to match each card with its corresponding card with the same value.\n\n");
    printf("   ");
    for (i = 0; i < SIZE; i++) {
        printf("%2d ", i + 1);
    }
    printf("\n");
    for (i = 0; i < SIZE; i++) {
        printf("%2d ", i + 1);
        for (j = 0; j < SIZE; j++) {
            printf("[ ]");
        }
        printf("\n");
    }

    // play the game
    while (pairs_found < SIZE * SIZE / 2) {
        // get first card selection from the player
        printf("Enter the coordinates of your first card selection: ");
        scanf("%d %d", &x1, &y1);
        printf("\n");
        if (x1 < 1 || x1 > SIZE || y1 < 1 || y1 > SIZE) {
            printf("Invalid input. Please try again.\n\n");
            continue;
        }
        if (board[x1 - 1][y1 - 1] == -1) {
            printf("That card has already been matched. Please try again.\n\n");
            continue;
        }
        if (board[x1 - 1][y1 - 1] == 0) {
            printf("Sorry, there is no card at that location. Please try again.\n\n");
            continue;
        }
        printf("You chose card [%d][%d]: [%d]\n\n", x1, y1, board[x1 - 1][y1 - 1]);

        // get second card selection from the player
        printf("Enter the coordinates of your second card selection: ");
        scanf("%d %d", &x2, &y2);
        printf("\n");
        if (x2 < 1 || x2 > SIZE || y2 < 1 || y2 > SIZE) {
            printf("Invalid input. Please try again.\n\n");
            continue;
        }
        if (board[x2 - 1][y2 - 1] == -1) {
            printf("That card has already been matched. Please try again.\n\n");
            continue;
        }
        if (board[x2 - 1][y2 - 1] == 0) {
            printf("Sorry, there is no card at that location. Please try again.\n\n");
            continue;
        }
        printf("You chose card [%d][%d]: [%d]\n\n", x2, y2, board[x2 - 1][y2 - 1]);

        // check if the selected cards match
        if (board[x1 - 1][y1 - 1] == board[x2 - 1][y2 - 1]) {
            printf("Congratulations! You found a matching pair.\n\n");
            board[x1 - 1][y1 - 1] = board[x2 - 1][y2 - 1] = -1;  // mark the cards as matched
            pairs_found++;
        } else {
            printf("Sorry, the selected cards do not match. Please try again.\n\n");
        }

        // print the current board
        printf("   ");
        for (i = 0; i < SIZE; i++) {
            printf("%2d ", i + 1);
        }
        printf("\n");
        for (i = 0; i < SIZE; i++) {
            printf("%2d ", i + 1);
            for (j = 0; j < SIZE; j++) {
                if (board[i][j] == -1) {
                    printf("[X]");  // the card has been matched
                } else if (i == x1 - 1 && j == y1 - 1) {
                    printf("[%d]", board[i][j]);  // the first selected card
                } else if (i == x2 - 1 && j == y2 - 1) {
                    printf("[%d]", board[i][j]);  // the second selected card
                } else {
                    printf("[ ]");  // the card has not been matched and is not selected
                }
            }
            printf("\n");
        }
    }

    printf("Congratulations! You found all the pairs of cards.\n");

    return 0;
}