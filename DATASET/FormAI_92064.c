//FormAI DATASET v1.0 Category: Memory Game ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4
#define NUM_CARDS ((BOARD_SIZE * BOARD_SIZE) / 2)

void shuffle(int deck[], int n);

int main(void) {
    int board[BOARD_SIZE][BOARD_SIZE];
    int cards[NUM_CARDS * 2];
    int i, j, k;
    int card_index;
    int first_selection[2];
    int second_selection[2];
    int matches_remaining = NUM_CARDS;

    /* Initialize deck with pairs of numbers */
    for (i = 0; i < NUM_CARDS; i++) {
        cards[i*2] = i;
        cards[i*2+1] = i;
    }

    /* Shuffle deck */
    srand(time(NULL));
    shuffle(cards, NUM_CARDS*2);

    /* Initialize board with shuffled cards */
    card_index = 0;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = cards[card_index++];
        }
    }

    /* Play game */
    while (matches_remaining > 0) {

        /* Display current board */
        printf("Current Board:\n");
        for (i = 0; i < BOARD_SIZE; i++) {
            for (j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == -1) {
                    printf("X ");
                } else {
                    printf("%d ", board[i][j]);
                }
            }
            printf("\n");
        }

        /* Get first selection */
        printf("Enter the row and column of the first card to flip: ");
        scanf("%d %d", &first_selection[0], &first_selection[1]);

        /* Flip first card */
        board[first_selection[0]][first_selection[1]] = cards[board[first_selection[0]][first_selection[1]]];
        printf("\n");

        /* Display updated board */
        printf("Current Board:\n");
        for (i = 0; i < BOARD_SIZE; i++) {
            for (j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == -1) {
                    printf("X ");
                } else {
                    printf("%d ", board[i][j]);
                }
            }
            printf("\n");
        }

        /* Get second selection */
        printf("Enter the row and column of the second card to flip: ");
        scanf("%d %d", &second_selection[0], &second_selection[1]);

        /* Flip second card */
        board[second_selection[0]][second_selection[1]] = cards[board[second_selection[0]][second_selection[1]]];
        printf("\n");

        /* Display updated board */
        printf("Current Board:\n");
        for (i = 0; i < BOARD_SIZE; i++) {
            for (j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == -1) {
                    printf("X ");
                } else {
                    printf("%d ", board[i][j]);
                }
            }
            printf("\n");
        }

        /* Check for match */
        if (board[first_selection[0]][first_selection[1]] == board[second_selection[0]][second_selection[1]]) {
            printf("Match found!\n");
            board[first_selection[0]][first_selection[1]] = -1;
            board[second_selection[0]][second_selection[1]] = -1;
            matches_remaining--;
        } else {
            printf("No match.\n");
            board[first_selection[0]][first_selection[1]] = -1;
            board[second_selection[0]][second_selection[1]] = -1;
        }

        printf("\n");
    }

    printf("Congratulations, you win!\n");

    return 0;
}

/* Fisher-Yates shuffle */
void shuffle(int deck[], int n) {
    int i, j, temp;
    for (i = n-1; i > 0; i--) {
        j = rand() % (i+1);
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}