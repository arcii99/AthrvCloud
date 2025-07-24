//FormAI DATASET v1.0 Category: Poker Game ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52

int main() {
    char *ranks[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    char *suits[] = {"Clubs", "Diamonds", "Hearts", "Spades"};
    char deck[DECK_SIZE][20];
    int i, j;

    // initialize deck
    for (i = 0; i < DECK_SIZE; i++) {
        sprintf(deck[i], "%s of %s", ranks[i % 13], suits[i / 13]);
    }

    // shuffle deck
    srand(time(NULL));

    for (i = DECK_SIZE - 1; i >= 0; i--) {
        j = rand() % (i + 1);
        char temp[20];
        strcpy(temp, deck[i]);
        strcpy(deck[i], deck[j]);
        strcpy(deck[j], temp);
    }

    // print shuffled deck
    for (i = 0; i < DECK_SIZE; i++) {
        printf("%s\n", deck[i]);
    }

    return 0;
}