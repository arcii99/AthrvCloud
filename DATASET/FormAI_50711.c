//FormAI DATASET v1.0 Category: Poker Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define HAND_SIZE 5

char* faces[13] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven",
                    "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

char* suits[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};

typedef struct Card {
    int face;
    int suit;
} Card;

void printDeck(Card *deck, int size) {
    for (int i = 0; i < size; i++) {
        printf("%s of %s\n", faces[deck[i].face], suits[deck[i].suit]);
    }
}

void shuffleDeck(Card *deck, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        int j = rand() % size;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void dealHand(Card *deck, Card *hand, int size) {
    for (int i = 0; i < size; i++) {
        hand[i] = deck[i];
    }
}

int main() {
    Card deck[DECK_SIZE];
    int ndx = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            deck[ndx].face = j;
            deck[ndx].suit = i;
            ndx++;
        }
    }
    shuffleDeck(deck, DECK_SIZE);
    Card hand[HAND_SIZE];
    dealHand(deck, hand, HAND_SIZE);
    printf("Your hand:\n");
    printDeck(hand, HAND_SIZE);
    return 0;
}