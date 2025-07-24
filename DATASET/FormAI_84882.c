//FormAI DATASET v1.0 Category: Poker Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* A function to shuffle the deck */
void shuffle(int deck[]) {
    int index, temp;
    for (int i = 51; i > 0; i--) {
        index = rand() % (i + 1);
        temp = deck[index];
        deck[index] = deck[i];
        deck[i] = temp;
    }
}

/* A function to print the current hand */
void print_hand(int hand[]) {
    printf("Current hand: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", hand[i]);
    }
    printf("\n");
}

/* A function to determine the rank of the hand */
int rank_hand(int hand[]) {
    int rank = 0;
    int counts[13] = { 0 };
    int flush = 1;
    int straight = 0;
    int pairs = 0;
    int three_of_a_kind = 0;
    int four_of_a_kind = 0;

    /* Initialize count and flush arrays */
    for (int i = 0; i < 5; i++) {
        counts[hand[i] % 13]++;
        if (((hand[i] - 1) / 13) != ((hand[0] - 1) / 13)) {
            flush = 0;
        }
    }

    /* Check for pairs, three of a kind, and four of a kind */
    for (int i = 0; i < 13; i++) {
        if (counts[i] == 2) {
            pairs++;
        } else if (counts[i] == 3) {
            three_of_a_kind++;
        } else if (counts[i] == 4) {
            four_of_a_kind = 1;
        }
    }

    /* Check for straight */
    for (int i = 0; i < 9; i++) {
        if (counts[i] == 1 && counts[i+1] == 1 && 
                counts[i+2] == 1 && counts[i+3] == 1 &&
                counts[i+4] == 1) {
            straight = 1;
        }
    }
    if (counts[0] == 1 && counts[1] == 1 && counts[2] == 1 &&
            counts[3] == 1 && counts[12] == 1) {
        straight = 1;
    }

    /* Determine rank */
    if (flush && straight) {
        rank = 8;
    } else if (four_of_a_kind) {
        rank = 7;
    } else if (three_of_a_kind && pairs == 1) {
        rank = 6;
    } else if (flush) {
        rank = 5;
    } else if (straight) {
        rank = 4;
    } else if (three_of_a_kind) {
        rank = 3;
    } else if (pairs == 2) {
        rank = 2;
    } else if (pairs == 1) {
        rank = 1;
    }

    return rank;
}

/* Main function */
int main() {
    int deck[52];
    int hand[5];
    int rank = 0;

    /* Initialize deck */
    for (int i = 0; i < 52; i++) {
        deck[i] = i;
    }

    /* Seed random number generator */
    srand(time(NULL));

    /* Shuffle deck */
    shuffle(deck);

    /* Deal cards */
    for (int i = 0; i < 5; i++) {
        hand[i] = deck[i];
    }

    /* Print current hand */
    print_hand(hand);

    /* Get rank of hand */
    rank = rank_hand(hand);

    /* Print rank of hand */
    printf("Rank of hand: %d\n", rank);

    return 0;
}