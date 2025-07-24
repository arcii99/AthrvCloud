//FormAI DATASET v1.0 Category: Poker Game ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define HAND_SIZE 5

typedef struct {
    int value; // 1 = Ace, 11 = Jack, 12 = Queen, 13 = King
    char suit; // 'H' = Hearts, 'D' = Diamonds, 'C' = Clubs, 'S' = Spades
} Card;

void shuffle(Card *deck) {
    srand(time(NULL));
    for (int i = DECK_SIZE - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void printHand(Card *hand) {
    for (int i = 0; i < HAND_SIZE; i++) {
        printf("%d%c ", hand[i].value, hand[i].suit);
    }
    printf("\n");
}

int getHandValue(Card *hand) {
    int value = 0;
    for (int i = 0; i < HAND_SIZE; i++) {
        if (hand[i].value > 10) {
            value += 10;
        } else {
            value += hand[i].value;
        }
    }
    return value;
}

void game() {
    Card deck[DECK_SIZE];
    for (int i = 0; i < DECK_SIZE; i++) {
        deck[i].value = i % 13 + 1;
        if (i < 13) {
            deck[i].suit = 'H';
        } else if (i < 26) {
            deck[i].suit = 'D';
        } else if (i < 39) {
            deck[i].suit = 'C';
        } else {
            deck[i].suit = 'S';
        }
    }
    shuffle(deck);
    printf("Your hand:\n");
    Card hand[HAND_SIZE];
    for (int i = 0; i < HAND_SIZE; i++) {
        hand[i] = deck[i];
    }
    printHand(hand);
    int value = getHandValue(hand);
    printf("Your hand value: %d\n", value);
}

int main() {
    game();
    return 0;
}