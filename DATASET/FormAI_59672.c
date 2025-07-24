//FormAI DATASET v1.0 Category: Poker Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 52
#define NUM_SUITS 4
#define NUM_RANKS 13

typedef enum Suit {
    HEARTS,
    SPADES,
    CLUBS,
    DIAMONDS
} Suit;

typedef enum Rank {
    TWO = 2,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    ACE
} Rank;

typedef struct Card {
    Suit suit;
    Rank rank;
} Card;

Card deck[NUM_CARDS];
Card hand[5];

int score = 0;

void shuffleDeck() {
    srand(time(NULL));
    int i, j;
    for (i = 0; i < NUM_CARDS; i++) {
        j = rand() % NUM_CARDS;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void dealHand() {
    int i;
    for (i = 0; i < 5; i++) {
        hand[i] = deck[i];
    }
}

void printHand() {
    int i;
    for (i = 0; i < 5; i++) {
        printf("%d of ", hand[i].rank);
        switch (hand[i].suit) {
            case HEARTS:
                printf("hearts\n");
                break;
            case SPADES:
                printf("spades\n");
                break;
            case CLUBS:
                printf("clubs\n");
                break;
            case DIAMONDS:
                printf("diamonds\n");
                break;
        }
    }
}

int calculateScore() {
    int i, j;
    int num_ranks[NUM_RANKS] = {0};
    int num_suits[NUM_SUITS] = {0};
    int max_rank_count = 0;
    int max_suit_count = 0;
    int straight_count = 0;
    int flush_count = 0;
    int has_pair = 0;
    int has_three_of_a_kind = 0;
    int has_four_of_a_kind = 0;

    // count the number of each rank and suit in hand
    for (i = 0; i < 5; i++) {
        num_ranks[hand[i].rank - 2]++;
        num_suits[hand[i].suit]++;
    }

    // check for pairs, three of a kind, and four of a kind
    for (i = 0; i < NUM_RANKS; i++) {
        if (num_ranks[i] == 2) {
            has_pair = 1;
        } else if (num_ranks[i] == 3) {
            has_three_of_a_kind = 1;
        } else if (num_ranks[i] == 4) {
            has_four_of_a_kind = 1;
        }
    }

    // check for flush
    for (i = 0; i < NUM_SUITS; i++) {
        if (num_suits[i] == 5) {
            flush_count++;
        }
    }

    // check for straight
    for (i = 0; i < NUM_RANKS - 4; i++) {
        straight_count = 0;
        for (j = i; j < i + 5; j++) {
            if (num_ranks[j] == 1) {
                straight_count++;
            }
        }
        if (straight_count == 5) {
            break;
        }
    }

    // find the most common rank and suit
    for (i = 0; i < NUM_RANKS; i++) {
        if (num_ranks[i] > max_rank_count) {
            max_rank_count = num_ranks[i];
        }
    }

    for (i = 0; i < NUM_SUITS; i++) {
        if (num_suits[i] > max_suit_count) {
            max_suit_count = num_suits[i];
        }
    }

    // assign a score based on hand
    if (has_four_of_a_kind) {
        score = 25;
    } else if (has_three_of_a_kind && has_pair) {
        score = 20;
    } else if (flush_count) {
        score = 15;
    } else if (straight_count) {
        score = 10;
    } else if (has_three_of_a_kind) {
        score = 5;
    } else if (has_pair == 2) {
        score = 2;
    } else if (has_pair) {
        score = 1;
    } else {
        score = 0;
    }

    return score;
}

int main() {
    int i;

    // initialize deck
    for (i = 0; i < NUM_RANKS; i++) {
        deck[i] = (Card) {
            HEARTS, i + 2
        };
        deck[13 + i] = (Card) {
            SPADES, i + 2
        };
        deck[26 + i] = (Card) {
            CLUBS, i + 2
        };
        deck[39 + i] = (Card) {
            DIAMONDS, i + 2
        };
    }

    // shuffle deck and deal hand
    shuffleDeck();
    dealHand();

    // output hand and score
    printf("Your hand:\n");
    printHand();
    printf("Your score: %d\n", calculateScore());

    return 0;
}