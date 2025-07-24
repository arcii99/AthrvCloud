//FormAI DATASET v1.0 Category: Poker Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum suits {HEARTS, SPADES, CLUBS, DIAMONDS};
enum ranks {ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};

struct card {
    enum suits suit;
    enum ranks rank;
};

void shuffle(struct card deck[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        int j = rand() % size;
        struct card tmp = deck[i];
        deck[i] = deck[j];
        deck[j] = tmp;
    }
}

void print_card(struct card c) {
    switch (c.rank) {
        case ACE:
            printf("Ace");
            break;
        case TWO:
            printf("Two");
            break;
        case THREE:
            printf("Three");
            break;
        case FOUR:
            printf("Four");
            break;
        case FIVE:
            printf("Five");
            break;
        case SIX:
            printf("Six");
            break;
        case SEVEN:
            printf("Seven");
            break;
        case EIGHT:
            printf("Eight");
            break;
        case NINE:
            printf("Nine");
            break;
        case TEN:
            printf("Ten");
            break;
        case JACK:
            printf("Jack");
            break;
        case QUEEN:
            printf("Queen");
            break;
        case KING:
            printf("King");
            break;
    }
    printf(" of ");
    switch (c.suit) {
        case HEARTS:
            printf("Hearts\n");
            break;
        case SPADES:
            printf("Spades\n");
            break;
        case CLUBS:
            printf("Clubs\n");
            break;
        case DIAMONDS:
            printf("Diamonds\n");
            break;
    }
}

int main() {
    struct card deck[52];
    int n = 0;
    for (int s = HEARTS; s <= DIAMONDS; s++) {
        for (int r = ACE; r <= KING; r++) {
            deck[n].suit = s;
            deck[n].rank = r;
            n++;
        }
    }
    shuffle(deck, 52);
    printf("Your hand:\n");
    for (int i = 0; i < 5; i++) {
        print_card(deck[i]);
    }
    return 0;
}