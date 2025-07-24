//FormAI DATASET v1.0 Category: Poker Game ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 52
#define NUM_PLAYERS 4
#define HAND_SIZE 5

int cards[NUM_CARDS];
int players[NUM_PLAYERS][HAND_SIZE];

void initDeck() {
    int i;
    for (i = 0; i < NUM_CARDS; i++) {
        cards[i] = i;
    }
}

void shuffleDeck() {
    int i, j, temp;
    for (i = 0; i < NUM_CARDS; i++) {
        j = rand() % NUM_CARDS;
        temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
}

void dealCards() {
    int i, j;
    for (i = 0; i < HAND_SIZE; i++) {
        for (j = 0; j < NUM_PLAYERS; j++) {
            players[j][i] = cards[(i * NUM_PLAYERS) + j];
        }
    }
}

void printHand(int player) {
    int i;
    printf("Player %d's hand:\n", player + 1);
    for (i = 0; i < HAND_SIZE; i++) {
        int card = players[player][i];
        char suit;
        switch (card / 13) {
            case 0: suit = 'C'; break;
            case 1: suit = 'D'; break;
            case 2: suit = 'H'; break;
            case 3: suit = 'S'; break;
        }
        printf("%c%d ", suit, card % 13 + 1);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    initDeck();
    shuffleDeck();
    dealCards();
    int i;
    for (i = 0; i < NUM_PLAYERS; i++) {
        printHand(i);
    }
    return 0;
}