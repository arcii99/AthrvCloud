//FormAI DATASET v1.0 Category: Memory Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4 // size of the game board
#define CARD_COUNT 8 // number of pairs of cards in the game

// function to print the game board
void printBoard(int board[][BOARD_SIZE], int revealed[][BOARD_SIZE]) {
    printf("\n\n");
    // print column headers
    printf("\t");
    for (int c = 0; c < BOARD_SIZE; c++) {
        printf("%d\t", c+1);
    }
    printf("\n");
    // print rows
    for (int r = 0; r < BOARD_SIZE; r++) {
        printf("%d\t", r+1);
        for (int c = 0; c < BOARD_SIZE; c++) {
            if (revealed[r][c]) { // if the card is revealed, print its value
                printf("%d\t", board[r][c]);
            } else { // if the card is not revealed, print an asterisk
                printf("*\t");
            }
        }
        printf("\n");
    }
}

// function to check if all cards have been revealed
int allRevealed(int revealed[][BOARD_SIZE]) {
    for (int r = 0; r < BOARD_SIZE; r++) {
        for (int c = 0; c < BOARD_SIZE; c++) {
            if (!revealed[r][c]) {
                return 0; // if any card is not revealed, return 0 (false)
            }
        }
    }
    return 1; // if all cards are revealed, return 1 (true)
}

// main function
int main() {
    int board[BOARD_SIZE][BOARD_SIZE]; // array to hold the values of the cards
    int revealed[BOARD_SIZE][BOARD_SIZE]; // array to hold whether each card is revealed or not
    int cardIndices[CARD_COUNT*2]; // array to hold indices of the cards in the board array
    int cardsRemaining = CARD_COUNT; // number of card pairs remaining to be matched

    srand(time(NULL)); // initialize random seed

    // populate cardIndices with randomly ordered indices
    for (int i = 0; i < CARD_COUNT*2; i++) {
        cardIndices[i] = i;
    }
    for (int i = 0; i < CARD_COUNT*2; i++) {
        int j = rand() % (i+1);
        int temp = cardIndices[i];
        cardIndices[i] = cardIndices[j];
        cardIndices[j] = temp;
    }

    // initialize board and revealed arrays
    for (int r = 0; r < BOARD_SIZE; r++) {
        for (int c = 0; c < BOARD_SIZE; c++) {
            board[r][c] = cardIndices[r*BOARD_SIZE+c]/2 + 1; // each pair of cards is represented by the same number (1-8)
            revealed[r][c] = 0;
        }
    }

    // print instructions and initial game board
    printf("Welcome to the Memory Game!\n\n");
    printf("Instructions:\n");
    printf("- There are %d pairs of cards. Your goal is to reveal all of them.\n", CARD_COUNT);
    printf("- On each turn, you will choose two cards to reveal. If they match, they will stay revealed. If they do not match, they will be covered again.\n");
    printf("- The game will end when you have revealed all the pairs.\n\n");
    printf("This is the initial game board:\n");
    printBoard(board, revealed);

    // main game loop
    while (!allRevealed(revealed)) {
        int row1, col1, row2, col2;
        do { // get the user's choice of cards to reveal
            printf("Enter the row and column numbers of the first card: ");
            scanf("%d %d", &row1, &col1);
            printf("Enter the row and column numbers of the second card: ");
            scanf("%d %d", &row2, &col2);
            if (row1 < 1 || row1 > BOARD_SIZE || row2 < 1 || row2 > BOARD_SIZE ||
                col1 < 1 || col1 > BOARD_SIZE || col2 < 1 || col2 > BOARD_SIZE) { // check that the user input is within the board
                printf("Invalid input. Please enter row and column numbers between 1 and %d.\n", BOARD_SIZE);
            } else if (row1-1 == row2-1 && col1-1 == col2-1) { // check that the user has not chosen the same card twice
                printf("You cannot choose the same card twice.\n");
            } else if (revealed[row1-1][col1-1] || revealed[row2-1][col2-1]) { // check that both cards are covered (not already revealed)
                printf("Those cards have already been revealed.\n");
            }
        } while (row1 < 1 || row1 > BOARD_SIZE || row2 < 1 || row2 > BOARD_SIZE ||
                 col1 < 1 || col1 > BOARD_SIZE || col2 < 1 || col2 > BOARD_SIZE ||
                 row1-1 == row2-1 && col1-1 == col2-1 ||
                 revealed[row1-1][col1-1] || revealed[row2-1][col2-1]);

        // reveal the chosen cards
        revealed[row1-1][col1-1] = 1;
        revealed[row2-1][col2-1] = 1;

        // print the updated game board
        printBoard(board, revealed);

        if (board[row1-1][col1-1] == board[row2-1][col2-1]) { // if the chosen cards match, decrement cardsRemaining
            cardsRemaining--;
        } else { // if the chosen cards do not match, cover them again
            printf("Those cards do not match.\n");
            revealed[row1-1][col1-1] = 0;
            revealed[row2-1][col2-1] = 0;
        }
    }

    // game over
    printf("Congratulations, you have revealed all the pairs!\n");

    return 0;
}