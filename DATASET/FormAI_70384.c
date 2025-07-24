//FormAI DATASET v1.0 Category: Poker Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DECK_SIZE 52
#define HAND_SIZE 5

struct card {
    int suit;
    int rank;
};

void shuffle(struct card *deck);
void print_card(struct card c);
void print_hand(struct card hand[HAND_SIZE]);
int compare(const void * a, const void * b);

int main() {
    struct card deck[DECK_SIZE];
    struct card hand[HAND_SIZE];
    int i, j;

    // initialize deck
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 13; j++) {
            deck[i*13+j].suit = i;
            deck[i*13+j].rank = j+1;
        }
    }

    // shuffle deck
    srand(time(NULL));
    shuffle(deck);

    // deal hand
    for (i = 0; i < HAND_SIZE; i++) {
        hand[i] = deck[i];
    }

    // sort hand
    qsort(hand, HAND_SIZE, sizeof(struct card), compare);

    // print hand
    print_hand(hand);

    return 0;
}

// shuffle function
void shuffle(struct card *deck) {
    int i, j;
    struct card temp;

    for (i = DECK_SIZE - 1; i > 0; i--) {
        j = rand() % (i + 1);
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// print card function
void print_card(struct card c) {
    char *suit;
    char *rank;

    switch (c.suit) {
        case 0:
            suit = "Hearts";
            break;
        case 1:
            suit = "Diamonds";
            break;
        case 2:
            suit = "Clubs";
            break;
        case 3:
            suit = "Spades";
            break;
        default:
            suit = "Unknown";
            break;
    }

    switch (c.rank) {
        case 1:
            rank = "Ace";
            break;
        case 11:
            rank = "Jack";
            break;
        case 12:
            rank = "Queen";
            break;
        case 13:
            rank = "King";
            break;
        default:
            rank = c.rank;
            break;
    }

    printf("%s of %s\n", rank, suit);
}

// print hand function
void print_hand(struct card hand[HAND_SIZE]) {
    int i;
    for (i = 0; i < HAND_SIZE; i++) {
        print_card(hand[i]);
    }
}

// compare function for qsort
int compare(const void * a, const void * b) {
    struct card *ca = (struct card *)a;
    struct card *cb = (struct card *)b;
    
    // compare rank
    if (ca->rank < cb->rank) return -1;
    if (ca->rank > cb->rank) return 1;
    
    // compare suit if rank is equal
    if (ca->suit < cb->suit) return -1;
    if (ca->suit > cb->suit) return 1;
    
    // cards are equal
    return 0;
}