//FormAI DATASET v1.0 Category: Poker Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define HAND_SIZE 5

char *CARD_TYPE[] = { "Spades", "Hearts", "Diamonds", "Clubs" };
char *CARD_VALUE[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace" };

int main() {

    // initialize random seed
    srand(time(NULL));

    // define deck
    int deck[DECK_SIZE];
    for (int i = 0; i < DECK_SIZE; i++) {
        deck[i] = i;
    }

    // shuffle deck
    for (int i = DECK_SIZE - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }

    // deal hands
    int hand1[HAND_SIZE];
    int hand2[HAND_SIZE];
    for (int i = 0; i < HAND_SIZE; i++) {
        hand1[i] = deck[i];
        hand2[i] = deck[i + HAND_SIZE];
    }

    // print hands
    printf("Hand 1:\n");
    for (int i = 0; i < HAND_SIZE; i++) {
        printf("%s of %s\n", CARD_VALUE[hand1[i] % 13], CARD_TYPE[hand1[i] / 13]);
    }

    printf("\n");

    printf("Hand 2:\n");
    for (int i = 0; i < HAND_SIZE; i++) {
        printf("%s of %s\n", CARD_VALUE[hand2[i] % 13], CARD_TYPE[hand2[i] / 13]);
    }

    return 0;
}