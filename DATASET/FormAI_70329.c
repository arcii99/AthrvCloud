//FormAI DATASET v1.0 Category: Poker Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int NUM_CARDS = 52;
const int NUM_RANKS = 13;
const int NUM_SUITS = 4;
const int HAND_SIZE = 5;

typedef struct {
    int rank;
    int suit;
} card;

void shuffle_deck(card* deck) {
    srand(time(NULL));
    for (int i = 0; i < NUM_CARDS; ++i) {
        int j = rand() % NUM_CARDS;
        card temp = deck[j];
        deck[j] = deck[i];
        deck[i] = temp;
    }
}

void print_card(card c) {
    char* ranks[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    char* suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    printf("%s of %s\n", ranks[c.rank], suits[c.suit]);
}

void print_hand(card* hand) {
    for (int i = 0; i < HAND_SIZE; ++i) {
        print_card(hand[i]);
    }
}

int is_pair(card* hand) {
    for (int i = 0; i < HAND_SIZE - 1; ++i) {
        for (int j = i + 1; j < HAND_SIZE; ++j) {
            if (hand[i].rank == hand[j].rank) {
                return 1;
            }
        }
    }
    return 0;
}

int is_two_pair(card* hand) {
    int pairs = 0;
    for (int i = 0; i < HAND_SIZE - 1; ++i) {
        for (int j = i + 1; j < HAND_SIZE; ++j) {
            if (hand[i].rank == hand[j].rank) {
                ++pairs;
            }
        }
    }
    return pairs == 2;
}

int is_three_of_a_kind(card* hand) {
    for (int i = 0; i < HAND_SIZE - 2; ++i) {
        int matches = 1;
        for (int j = i + 1; j < HAND_SIZE; ++j) {
            if (hand[i].rank == hand[j].rank) {
                ++matches;
            }
        }
        if (matches == 3) {
            return 1;
        }
    }
    return 0;
}

int is_straight(card* hand) {
    for (int i = 0; i < HAND_SIZE - 1; ++i) {
        if (hand[i].rank != hand[i+1].rank - 1) {
            return 0;
        }
    }
    return 1;
}

int is_flush(card* hand) {
    int suit = hand[0].suit;
    for (int i = 1; i < HAND_SIZE; ++i) {
        if (hand[i].suit != suit) {
            return 0;
        }
    }
    return 1;
}

int is_full_house(card* hand) {
    int counts[NUM_RANKS];
    for (int i = 0; i < NUM_RANKS; ++i) {
        counts[i] = 0;
    }
    for (int i = 0; i < HAND_SIZE; ++i) {
        ++counts[hand[i].rank];
    }
    int has_pair = 0;
    int has_three = 0;
    for (int i = 0; i < NUM_RANKS; ++i) {
        if (counts[i] == 2) {
            has_pair = 1;
        } else if (counts[i] == 3) {
            has_three = 1;
        }
    }
    return has_pair && has_three;
}

int is_four_of_a_kind(card* hand) {
    for (int i = 0; i < HAND_SIZE - 3; ++i) {
        int matches = 1;
        for (int j = i + 1; j < HAND_SIZE; ++j) {
            if (hand[i].rank == hand[j].rank) {
                ++matches;
            }
        }
        if (matches == 4) {
            return 1;
        }
    }
    return 0;
}

int is_straight_flush(card* hand) {
    return is_straight(hand) && is_flush(hand);
}

int is_royal_flush(card* hand) {
    int expected_rank = 10;
    for (int i = 0; i < HAND_SIZE; ++i) {
        if (hand[i].rank != expected_rank++) {
            return 0;
        }
    }
    return is_flush(hand);
}

int main() {
    card deck[NUM_CARDS];
    for (int i = 0; i < NUM_SUITS; ++i) {
        for (int j = 0; j < NUM_RANKS; ++j) {
            deck[NUM_RANKS*i + j].rank = j;
            deck[NUM_RANKS*i + j].suit = i;
        }
    }
    shuffle_deck(deck);

    printf("Welcome to C Poker!\n");

    while (1) {
        card hand[HAND_SIZE];
        for (int i = 0; i < HAND_SIZE; ++i) {
            hand[i] = deck[i];
        }

        printf("\nYour hand:\n");
        print_hand(hand);

        if (is_royal_flush(hand)) {
            printf("Royal flush!!!\n");
        } else if (is_straight_flush(hand)) {
            printf("Straight flush!\n");
        } else if (is_four_of_a_kind(hand)) {
            printf("Four of a kind!\n");
        } else if (is_full_house(hand)) {
            printf("Full house!\n");
        } else if (is_flush(hand)) {
            printf("Flush!\n");
        } else if (is_straight(hand)) {
            printf("Straight!\n");
        } else if (is_three_of_a_kind(hand)) {
            printf("Three of a kind.\n");
        } else if (is_two_pair(hand)) {
            printf("Two pair!\n");
        } else if (is_pair(hand)) {
            printf("Pair.\n");
        } else {
            printf("High card.\n");
        }
    }

    return 0;
}