//FormAI DATASET v1.0 Category: Poker Game ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define HAND_SIZE 5

enum suit {
    HEARTS, DIAMONDS, CLUBS, SPADES
};

enum rank {
    ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING
};

typedef struct {
    enum suit suit;
    enum rank rank;
} card;

void init_deck(card deck[]);
void shuffle_deck(card deck[]);
void print_hand(card hand[]);
int rank_hand(card hand[]);
void swap_cards(card *a, card *b);

int main(void) {
    srand(time(NULL));
    card deck[DECK_SIZE];
    card hand[HAND_SIZE];
    int num_players = 2;
    int i, j, k;
    int winner, max_rank = 0;

    init_deck(deck);
    shuffle_deck(deck);

    for (i = 0; i < num_players; i++) {
        for (j = 0; j < HAND_SIZE; j++) {
            hand[j] = deck[i * HAND_SIZE + j];
        }

        printf("Player %d's hand:\n", i+1);
        print_hand(hand);

        int rank = rank_hand(hand);

        if (rank > max_rank) {
            max_rank = rank;
            winner = i;
        }

        printf("Rank: %d\n\n", rank);
    }

    printf("Player %d wins with rank %d!\n", winner+1, max_rank);

    return 0;
}

void init_deck(card deck[]) {
    int i, j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 13; j++) {
            deck[i*13+j].suit = i;
            deck[i*13+j].rank = j;
        }
    }
}

void shuffle_deck(card deck[]) {
    int i;
    for (i = 0; i < DECK_SIZE; i++) {
        int j = rand() % DECK_SIZE;
        swap_cards(&deck[i], &deck[j]);
    }
}

void print_hand(card hand[]) {
    int i;
    for (i = 0; i < HAND_SIZE; i++) {
        printf("%d of %d\n", hand[i].rank+1, hand[i].suit+1);
    }
}

int rank_hand(card hand[]) {
    int i, j;

    // Check for flush
    for (i = 0; i < HAND_SIZE-1; i++) {
        if (hand[i].suit != hand[i+1].suit) {
            break;
        }
    }
    if (i == HAND_SIZE-1) {
        return 6; // Flush rank
    }

    // Check for straight
    int straight = 1;
    for (i = 0; i < HAND_SIZE-1; i++) {
        if (hand[i].rank+1 != hand[i+1].rank) {
            if (hand[i].rank == 0 && hand[i+1].rank == KING) { // Ace can also be at end of straight
                continue;
            }
            straight = 0;
            break;
        }
    }
    if (straight) {
        return 5; // Straight rank
    }

    // Check for pairs
    int num_pairs = 0;
    int pair_rank = -1;
    for (i = 0; i < HAND_SIZE-1; i++) {
        for (j = i+1; j < HAND_SIZE; j++) {
            if (hand[i].rank == hand[j].rank) {
                num_pairs++;
                if (hand[i].rank > pair_rank) {
                    pair_rank = hand[i].rank;
                }
            }
        }
    }
    if (num_pairs == 1) {
        return 2; // One pair rank
    }
    if (num_pairs == 2) {
        return 3; // Two pairs rank
    }

    // Default rank (highest card)
    return 1;
}

void swap_cards(card *a, card *b) {
    card temp = *a;
    *a = *b;
    *b = temp;
}