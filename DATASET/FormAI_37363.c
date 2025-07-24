//FormAI DATASET v1.0 Category: Poker Game ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 52
#define NUM_SUITS 4
#define NUM_RANKS 13
#define HAND_SIZE 5

void initialize_deck(int deck[]);
void shuffle_deck(int deck[]);
void print_deck(int deck[]);
void deal(int deck[], int hand[]);
void print_hand(int hand[]);
int evaluate_hand(int hand[]);
void print_winner(int winner);

int main() {
    int deck[NUM_CARDS];
    int hand1[HAND_SIZE], hand2[HAND_SIZE];
    int winner, score1, score2;

    initialize_deck(deck);
    shuffle_deck(deck);

    deal(deck, hand1);
    deal(deck, hand2);

    printf("Player 1's hand:\n");
    print_hand(hand1);
    printf("\n");

    printf("Player 2's hand:\n");
    print_hand(hand2);
    printf("\n");

    score1 = evaluate_hand(hand1);
    score2 = evaluate_hand(hand2);

    if (score1 > score2) {
        winner = 1;
    } else if (score2 > score1) {
        winner = 2;
    } else {
        winner = 0;
    }

    print_winner(winner);

    return 0;
}

void initialize_deck(int deck[]) {
    int i, j, index;

    for (i = 0; i < NUM_SUITS; i++) {
        for (j = 0; j < NUM_RANKS; j++) {
            index = i * NUM_RANKS + j;
            deck[index] = j + 1;
        }
    }
}

void shuffle_deck(int deck[]) {
    int i, j, temp;

    srand(time(NULL));

    for (i = 0; i < NUM_CARDS; i++) {
        j = rand() % NUM_CARDS;

        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void print_deck(int deck[]) {
    int i;

    for (i = 0; i < NUM_CARDS; i++) {
        printf("%d ", deck[i]);
    }

    printf("\n");
}

void deal(int deck[], int hand[]) {
    int i;

    for (i = 0; i < HAND_SIZE; i++) {
        hand[i] = deck[i];
    }
}

void print_hand(int hand[]) {
    int i;

    for (i = 0; i < HAND_SIZE; i++) {
        switch (hand[i]) {
            case 1:
                printf("Ace ");
                break;
            case 11:
                printf("Jack ");
                break;
            case 12:
                printf("Queen ");
                break;
            case 13:
                printf("King ");
                break;
            default:
                printf("%d ", hand[i]);
                break;
        }
    }
}

int evaluate_hand(int hand[]) {
    int i, j;
    int pairs = 0, three_of_a_kind = 0, four_of_a_kind = 0, flush = 1, straight = 1;
    int ranks[NUM_RANKS] = {0};

    for (i = 0; i < HAND_SIZE; i++) {
        ranks[hand[i] - 1]++;
    }

    for (i = 0; i < NUM_RANKS; i++) {
        if (ranks[i] == 2) {
            pairs++;
        } else if (ranks[i] == 3) {
            three_of_a_kind++;
        } else if (ranks[i] == 4) {
            four_of_a_kind++;
        }
    }

    for (i = 0; i < HAND_SIZE - 1; i++) {
        if (hand[i] + 1 != hand[i+1]) {
            straight = 0;
        }

        if (hand[i] / 13 != hand[i+1] / 13) {
            flush = 0;
        }
    }

    if (straight && flush) {
        return 9; // straight flush
    } else if (four_of_a_kind) {
        return 8; // four of a kind
    } else if (pairs == 1 && three_of_a_kind == 1) {
        return 7; // full house
    } else if (flush) {
        return 6; // flush
    } else if (straight) {
        return 5; // straight
    } else if (three_of_a_kind) {
        return 4; // three of a kind
    } else if (pairs == 2) {
        return 3; // two pairs
    } else if (pairs == 1) {
        return 2; // one pair
    } else {
        return 1; // high card
    }
}

void print_winner(int winner) {
    switch (winner) {
        case 0:
            printf("It's a tie!\n");
            break;
        case 1:
            printf("Player 1 wins!\n");
            break;
        case 2:
            printf("Player 2 wins!\n");
            break;
    }
}