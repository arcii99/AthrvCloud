//FormAI DATASET v1.0 Category: Poker Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 52
#define NUM_PLAYERS 5

int deck[NUM_CARDS];
int hands[NUM_PLAYERS][5];

void shuffle(int *deck) {
    int i, j, temp;
    for(i = NUM_CARDS - 1; i > 0; i--) {
        j = rand() % (i + 1);
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void deal(int *deck, int hands[][5]) {
    int i, j, card = 0;
    for(i = 0; i < NUM_PLAYERS; i++) {
        for(j = 0; j < 5; j++) {
            hands[i][j] = deck[card];
            card++;
        }
    }
}

int main() {
    int i, j;
    srand(time(NULL));
    for(i = 0; i < NUM_CARDS; i++) {
        deck[i] = i;
    }
    shuffle(deck);
    deal(deck, hands);
    for(i = 0; i < NUM_PLAYERS; i++) {
        printf("Player %d's hand:\n", i + 1);
        for(j = 0; j < 5; j++) {
            printf("\t%d\n", hands[i][j]);
        }
    }
    return 0;
}