//FormAI DATASET v1.0 Category: Poker Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define NUM_PLAYERS 4
#define HAND_SIZE 5

typedef enum { HEARTS, DIAMONDS, CLUBS, SPADES } suit_t;
typedef enum { TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE } rank_t;

typedef struct {
    suit_t suit;
    rank_t rank;
} card_t;

typedef struct {
    card_t hand[HAND_SIZE];
    int score;
} player_t;

card_t deck[DECK_SIZE];
player_t players[NUM_PLAYERS];

void shuffle_deck() {
    for (int i = 0; i < DECK_SIZE; i++) {
        int j = rand() % DECK_SIZE;
        card_t temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void deal_cards() {
    for (int i = 0; i < HAND_SIZE; i++) {
        for (int j = 0; j < NUM_PLAYERS; j++) {
            players[j].hand[i] = deck[NUM_PLAYERS*i + j];
        }
    }
}

int compare_cards(const void* a, const void* b) {
    card_t* card_a = (card_t*)a;
    card_t* card_b = (card_t*)b;

    if (card_a->rank > card_b->rank) {
        return -1;
    } else if (card_a->rank < card_b->rank) {
        return 1;
    } else {
        return 0;
    }
}

int get_score(card_t hand[HAND_SIZE]) {
    qsort(hand, HAND_SIZE, sizeof(card_t), compare_cards);

    int score = 0;
    int straight = 0;
    int flush = 0;
    int n_of_a_kind = 0;
    int i = 0;

    // Check for flush
    while (i < HAND_SIZE && hand[i].suit == hand[0].suit) {
        i++;
    }
    if (i == HAND_SIZE) {
        flush = 1;
    }

    // Check for straight
    i = 0;
    while (i < HAND_SIZE - 1 && hand[i].rank - hand[i+1].rank == 1) {
        i++;
    }
    if (i == HAND_SIZE - 1) {
        straight = 1;
    }

    // Check for n of a kind
    i = 0;
    while (i < HAND_SIZE - 1 && n_of_a_kind == 0) {
        if (hand[i].rank == hand[i+1].rank) {
            n_of_a_kind++;
        }
        i++;
    }

    if (straight && flush) {
        score = 8; // Straight flush
    } else if (n_of_a_kind == 3) {
        score = 7; // Four of a kind
    } else if (n_of_a_kind == 2) {
        if (i < HAND_SIZE - 1 && hand[i].rank == hand[i+1].rank) {
            score = 6; // Full house
        } else {
            score = 3; // Three of a kind
        }
    } else if (flush) {
        score = 5; // Flush
    } else if (straight) {
        score = 4; // Straight
    } else if (n_of_a_kind == 1) {
        score = 2; // Two pairs
    } else {
        score = 1; // High card
    }

    return score;
}

void print_card(card_t card) {
    switch (card.rank) {
        case TWO:
            printf("2");
            break;
        case THREE:
            printf("3");
            break;
        case FOUR:
            printf("4");
            break;
        case FIVE:
            printf("5");
            break;
        case SIX:
            printf("6");
            break;
        case SEVEN:
            printf("7");
            break;
        case EIGHT:
            printf("8");
            break;
        case NINE:
            printf("9");
            break;
        case TEN:
            printf("10");
            break;
        case JACK:
            printf("J");
            break;
        case QUEEN:
            printf("Q");
            break;
        case KING:
            printf("K");
            break;
        case ACE:
            printf("A");
            break;
    }
    switch (card.suit) {
        case HEARTS:
            printf("H");
            break;
        case DIAMONDS:
            printf("D");
            break;
        case CLUBS:
            printf("C");
            break;
        case SPADES:
            printf("S");
            break;
    }
}

void print_hand(card_t hand[HAND_SIZE]) {
    for (int i = 0; i < HAND_SIZE; i++) {
        print_card(hand[i]);
        printf(" ");
    }
}

int main() {
    // Initialize deck
    for (int i = 0; i < DECK_SIZE; i++) {
        deck[i].suit = i / 13;
        deck[i].rank = i % 13;
    }

    // Seed random number generator
    srand(time(NULL));

    // Shuffle deck
    shuffle_deck();

    // Deal cards
    deal_cards();

    // Score hands
    for (int i = 0; i < NUM_PLAYERS; i++) {
        players[i].score = get_score(players[i].hand);
    }

    // Print hands and scores
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("Player %d: ", i);
        print_hand(players[i].hand);
        printf("(%d)\n", players[i].score);
    }

    return 0;
}