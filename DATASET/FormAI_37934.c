//FormAI DATASET v1.0 Category: Poker Game ; Style: complete
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define HAND_SIZE 5
#define RANK_SIZE 14

typedef enum {
    UNKNOWN,
    HIGH_CARD,
    ONE_PAIR,
    TWO_PAIR,
    THREE_KIND,
    STRAIGHT,
    FLUSH,
    FULL_HOUSE,
    FOUR_KIND,
    STRAIGHT_FLUSH,
    ROYAL_FLUSH
} HAND_RANK;

typedef struct {
    int rank;
    int suit;
} CARD;

HAND_RANK check_hand_rank(CARD hand[]) {
    bool is_flush = true;
    bool is_straight = true;
    int num_ranks[RANK_SIZE] = {0};

    // Check for flush
    for (int i = 1; i < HAND_SIZE; i++) {
        if (hand[i].suit != hand[0].suit) {
            is_flush = false;
            break;
        }
    }

    // Check for straight
    for (int i = 0; i < HAND_SIZE; i++) {
        num_ranks[hand[i].rank]++;
    }
    for (int i = 1; i < RANK_SIZE; i++) {
        if (num_ranks[i] != 1) {
            is_straight = false;
            break;
        }
    }
    if (num_ranks[1] && num_ranks[10] && num_ranks[11] && num_ranks[12] && num_ranks[13]) {
        is_straight = true; // Ace high straight qualifies
    }

    // Check for rank combinations
    int pairs = 0;
    int three_of_kind = 0;
    int four_of_kind = 0;
    for (int i = 1; i < RANK_SIZE; i++) {
        if (num_ranks[i] == 2) {
            pairs++;
        }
        else if (num_ranks[i] == 3) {
            three_of_kind++;
        }
        else if (num_ranks[i] == 4) {
            four_of_kind++;
        }
    }

    // Determine hand rank
    if (is_straight && is_flush && num_ranks[1] && num_ranks[10] && num_ranks[11] && num_ranks[12] && num_ranks[13]) {
        return ROYAL_FLUSH;
    } else if (is_straight && is_flush) {
        return STRAIGHT_FLUSH;
    } else if (four_of_kind) {
        return FOUR_KIND;
    } else if (pairs && three_of_kind) {
        return FULL_HOUSE;
    } else if (is_flush) {
        return FLUSH;
    } else if (is_straight) {
        return STRAIGHT;
    } else if (three_of_kind) {
        return THREE_KIND;
    } else if (pairs == 2) {
        return TWO_PAIR;
    } else if (pairs) {
        return ONE_PAIR;
    } else {
        return HIGH_CARD;
    }
}

void print_card(CARD card) {
    const char* ranks[] = {"", "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    const char* suits[] = {"Diamonds", "Clubs", "Hearts", "Spades"};
    printf("%s of %s\n", ranks[card.rank], suits[card.suit]);
}

void print_hand(CARD hand[]) {
    for (int i = 0; i < HAND_SIZE; i++) {
        print_card(hand[i]);
    }
}

void shuffle_deck(CARD deck[]) {
    for (int i = 0; i < DECK_SIZE; i++) {
        int j = rand() % DECK_SIZE;
        CARD temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void deal_hand(CARD deck[], CARD hand[], int num_cards) {
    for (int i = 0; i < num_cards; i++) {
        hand[i] = deck[i];
    }
}

int main() {
    CARD deck[DECK_SIZE];
    CARD hand[HAND_SIZE];
    HAND_RANK rank;

    // Initialize deck
    for (int i = 0; i < DECK_SIZE; i++) {
        deck[i].rank = i % RANK_SIZE;
        deck[i].suit = i / RANK_SIZE;
    }

    srand(time(NULL));
    shuffle_deck(deck);

    deal_hand(deck, hand, HAND_SIZE);
    printf("\nYour Hand:\n");
    print_hand(hand);

    rank = check_hand_rank(hand);
    printf("\nYour Hand Rank: ");
    switch (rank) {
        case ROYAL_FLUSH:
            printf("Royal Flush\n");
            break;
        case STRAIGHT_FLUSH:
            printf("Straight Flush\n");
            break;
        case FOUR_KIND:
            printf("Four of a Kind\n");
            break;
        case FULL_HOUSE:
            printf("Full House\n");
            break;
        case FLUSH:
            printf("Flush\n");
            break;
        case STRAIGHT:
            printf("Straight\n");
            break;
        case THREE_KIND:
            printf("Three of a Kind\n");
            break;
        case TWO_PAIR:
            printf("Two Pair\n");
            break;
        case ONE_PAIR:
            printf("One Pair\n");
            break;
        case HIGH_CARD:
            printf("High Card\n");
            break;
        default:
            printf("Unknown\n");
            break;
    }

    return 0;
}