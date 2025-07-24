//FormAI DATASET v1.0 Category: Memory Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4
#define NUM_PAIRS 8

enum CardStatus {HIDDEN, REVEALED, MATCHED};

typedef struct {
    int value;
    enum CardStatus status;
} Card;

void init_cards(Card deck[]) {
    int values[NUM_PAIRS] = {1, 2, 3, 4, 5, 6, 7, 8};
    int i, j;

    // set up each card with a unique value and hidden status
    for (i = 0; i < NUM_PAIRS; i++) {
        for (j = 0; j < 2; j++) {
            int index = i * 2 + j;
            deck[index].value = values[i];
            deck[index].status = HIDDEN;
        }
    }
}

void shuffle_cards(Card deck[]) {
    int i;

    // seed the random number generator
    srand(time(NULL));

    // Fisher-Yates shuffle
    for (i = SIZE * SIZE - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void print_board(Card board[]) {
    int row, col;

    printf("\n");

    // print column headers
    printf("  ");
    for (col = 0; col < SIZE; col++) {
        printf("%d ", col + 1);
    }
    printf("\n");

    // print row headers and card values
    for (row = 0; row < SIZE; row++) {
        printf("%d ", row + 1);
        for (col = 0; col < SIZE; col++) {
            int index = row * SIZE + col;
            if (board[index].status == HIDDEN) {
                printf("* ");
            } else {
                printf("%d ", board[index].value);
            }
        }
        printf("\n");
    }
}

void reveal_card(Card board[], int row, int col) {
    int index = (row - 1) * SIZE + col - 1;
    board[index].status = REVEALED;
}

int get_card_value(Card board[], int row, int col) {
    int index = (row - 1) * SIZE + col - 1;
    return board[index].value;
}

void hide_cards(Card board[], int row1, int col1, int row2, int col2) {
    int index1 = (row1 - 1) * SIZE + col1 - 1;
    int index2 = (row2 - 1) * SIZE + col2 - 1;
    board[index1].status = HIDDEN;
    board[index2].status = HIDDEN;
}

int all_cards_matched(Card board[]) {
    int i;

    for (i = 0; i < SIZE * SIZE; i++) {
        if (board[i].status != MATCHED) {
            return 0;
        }
    }

    return 1;
}

int main() {
    Card deck[SIZE * SIZE];
    Card board[SIZE * SIZE];
    int num_guesses = 0;

    init_cards(deck);
    shuffle_cards(deck);

    // set up the game board
    int i;
    for (i = 0; i < SIZE * SIZE; i++) {
        board[i] = deck[i];
    }

    while (!all_cards_matched(board)) {
        print_board(board);

        int row1, col1, row2, col2;

        // get first card
        printf("\nEnter first card (row column): ");
        scanf("%d %d", &row1, &col1);

        while (row1 < 1 || row1 > SIZE || col1 < 1 || col1 > SIZE || board[(row1 - 1) * SIZE + col1 - 1].status != HIDDEN) {
            printf("Invalid selection. Try again.\n");
            printf("Enter first card (row column): ");
            scanf("%d %d", &row1, &col1);
        }

        reveal_card(board, row1, col1);
        print_board(board);

        // get second card
        printf("\nEnter second card (row column): ");
        scanf("%d %d", &row2, &col2);

        while (row2 < 1 || row2 > SIZE || col2 < 1 || col2 > SIZE || board[(row2 - 1) * SIZE + col2 - 1].status != HIDDEN) {
            printf("Invalid selection. Try again.\n");
            printf("Enter second card (row column): ");
            scanf("%d %d", &row2, &col2);
        }

        reveal_card(board, row2, col2);
        print_board(board);

        // check for match
        if (get_card_value(board, row1, col1) == get_card_value(board, row2, col2)) {
            printf("\nMatch!\n");
            board[(row1 - 1) * SIZE + col1 - 1].status = MATCHED;
            board[(row2 - 1) * SIZE + col2 - 1].status = MATCHED;
        } else {
            printf("\nNo match.\n");
            hide_cards(board, row1, col1, row2, col2);
        }

        num_guesses++;
    }

    printf("\nCongratulations, you won in %d guesses!\n", num_guesses);

    return 0;
}