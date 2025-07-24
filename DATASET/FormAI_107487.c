//FormAI DATASET v1.0 Category: Poker Game ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define HAND_SIZE 5

enum suits {
    HEARTS,
    CLUBS,
    DIAMONDS,
    SPADES,
};

enum ranks {
    ACE,
    TWO,
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
};

struct card {
    enum suits suit;
    enum ranks rank;
};

void init_deck(struct card deck[]) {
    int i, j, k;

    k = 0;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 13; j++) {
            deck[k].suit = i;
            deck[k].rank = j;
            k++;
        }
    }
}

void shuffle_deck(struct card deck[]) {
    int i, j;
    struct card temp;

    srand(time(NULL));
    for (i = DECK_SIZE - 1; i > 0; i--) {
        j = rand() % (i + 1);
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void print_card(struct card c) {
    const char *suits_str[] = {"Hearts", "Clubs", "Diamonds", "Spades"};
    const char *ranks_str[] = {"Ace", "Two", "Three", "Four", "Five", "Six",
            "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

    printf("%s of %s", ranks_str[c.rank], suits_str[c.suit]);
}

void deal(struct card deck[], struct card hand[]) {
    int i;

    for (i = 0; i < HAND_SIZE; i++) {
        hand[i] = deck[i];
    }
}

int count_pairs(struct card hand[], int ncards) {
    int i, j;
    int npairs = 0;

    for (i = 0; i < ncards; i++) {
        for (j = i + 1; j < ncards; j++) {
            if (hand[i].rank == hand[j].rank) {
                npairs++;
            }
        }
    }

    return npairs;
}

int main(void) {
    struct card deck[DECK_SIZE];
    struct card hand[HAND_SIZE];
    int npairs;

    init_deck(deck);
    shuffle_deck(deck);
    deal(deck, hand);

    printf("Your hand: ");
    for (int i = 0; i < HAND_SIZE; i++) {
        print_card(hand[i]);
        printf(" ");
    }
    printf("\n");

    npairs = count_pairs(hand, HAND_SIZE);
    if (npairs > 0) {
        printf("You have %d pair(s)!\n", npairs);
    } else {
        printf("Sorry, you have no pairs.\n");
    }

    return 0;
}