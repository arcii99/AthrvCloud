//FormAI DATASET v1.0 Category: Poker Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CARDS_PER_SUIT 13
#define NUM_SUITS 4
#define DECK_SIZE (CARDS_PER_SUIT * NUM_SUITS)
#define HAND_SIZE 5

enum suit {
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES
};

enum face {
    ACE = 1,
    JACK = 11,
    QUEEN,
    KING
};

struct card {
    enum suit suit;
    int face;
};

void shuffle_deck(struct card *deck) {
    srand(time(NULL));
    for (int i = 0; i < DECK_SIZE; i++) {
        int j = rand() % DECK_SIZE;
        struct card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void print_hand(struct card *hand) {
    for (int i = 0; i < HAND_SIZE; i++) {
        enum suit s = hand[i].suit;
        int f = hand[i].face;
        printf("%d of ", f);
        switch (s) {
            case CLUBS:
                printf("clubs\n");
                break;
            case DIAMONDS:
                printf("diamonds\n");
                break;
            case HEARTS:
                printf("hearts\n");
                break;
            case SPADES:
                printf("spades\n");
                break;
            default:
                break;
        }
    }
}

int cmp_card(const void *p1, const void *p2) {
    struct card *c1 = (struct card *)p1;
    struct card *c2 = (struct card *)p2;
    int f1 = c1->face;
    int f2 = c2->face;
    return f1 - f2;
}

int is_royal_flush(struct card *hand) {
    int i;
    enum suit s = hand[0].suit;
    for (i = 1; i < HAND_SIZE; i++) {
        if (hand[i].suit != s || hand[i].face < JACK)
            return 0;
    }
    return 1;
}

int is_straight_flush(struct card *hand) {
    int i;
    enum suit s = hand[0].suit;
    int f = hand[0].face;
    for (i = 1; i < HAND_SIZE; i++) {
        if (hand[i].suit != s || hand[i].face != f + i)
            return 0;
    }
    return 1;
}

int is_four_of_a_kind(struct card *hand) {
    return hand[0].face == hand[1].face
        && hand[1].face == hand[2].face
        && hand[2].face == hand[3].face
        || hand[1].face == hand[2].face
        && hand[2].face == hand[3].face
        && hand[3].face == hand[4].face;
}

int is_full_house(struct card *hand) {
    return hand[0].face == hand[1].face
        && hand[1].face == hand[2].face
        && hand[3].face == hand[4].face
        || hand[0].face == hand[1].face
        && hand[2].face == hand[3].face
        && hand[3].face == hand[4].face;
}

int is_flush(struct card *hand) {
    enum suit s = hand[0].suit;
    for (int i = 1; i < HAND_SIZE; i++) {
        if (hand[i].suit != s)
            return 0;
    }
    return 1;
}

int is_straight(struct card *hand) {
    int f = hand[0].face;
    for (int i = 1; i < HAND_SIZE; i++) {
        if (hand[i].face != f + i)
            return 0;
    }
    return 1;
}

int is_three_of_a_kind(struct card *hand) {
    return hand[0].face == hand[1].face
        && hand[1].face == hand[2].face
        || hand[1].face == hand[2].face
        && hand[2].face == hand[3].face
        || hand[2].face == hand[3].face
        && hand[3].face == hand[4].face;
}

int is_two_pair(struct card *hand) {
    return hand[0].face == hand[1].face
        && hand[2].face == hand[3].face
        || hand[0].face == hand[1].face
        && hand[3].face == hand[4].face
        || hand[1].face == hand[2].face
        && hand[3].face == hand[4].face;
}

int is_pair(struct card *hand) {
    return hand[0].face == hand[1].face
        || hand[1].face == hand[2].face
        || hand[2].face == hand[3].face
        || hand[3].face == hand[4].face;
}

int main() {
    struct card deck[DECK_SIZE];
    for (int i = 0; i < NUM_SUITS; i++) {
        for (int j = 1; j <= CARDS_PER_SUIT; j++) {
            int index = i * CARDS_PER_SUIT + j - 1;
            deck[index].suit = i;
            deck[index].face = j;
        }
    }
    shuffle_deck(deck);
    struct card hand[HAND_SIZE];
    for (int i = 0; i < HAND_SIZE; i++) {
        hand[i] = deck[i];
    }
    qsort(hand, HAND_SIZE, sizeof(struct card), cmp_card);
    print_hand(hand);
    if (is_royal_flush(hand)) {
        printf("Royal flush!\n");
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
        printf("Three of a kind!\n");
    } else if (is_two_pair(hand)) {
        printf("Two pair!\n");
    } else if (is_pair(hand)) {
        printf("Pair!\n");
    } else {
        printf("High card!\n");
    }
    return 0;
}