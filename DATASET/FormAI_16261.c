//FormAI DATASET v1.0 Category: Poker Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to initialize the deck
void initializeDeck(int deck[]) {
    int i, j, k;
    k = 0;
    for (i = 0; i < 4; i++) {
        for(j = 1; j <= 13; j++) {
            deck[k++] = j;
        }
    }
}

// Function to shuffle the deck
void shuffleDeck(int deck[]) {
    int i, j, temp;
    for (i = 0; i < 52; i++) {
        j = rand() % 52;
        temp = deck[j];
        deck[j] = deck[i];
        deck[i] = temp;
    }
}

// Function to print the cards in the deck
void printDeck(int deck[]) {
    int i;
    for (i = 0; i < 52; i++) {
        printf("%d ", deck[i]);
    }
    printf("\n");
}

int main() {
    int deck[52];
    initializeDeck(deck);
    srand(time(0));
    shuffleDeck(deck);
    printDeck(deck);

    return 0;
}