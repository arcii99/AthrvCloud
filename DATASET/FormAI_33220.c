//FormAI DATASET v1.0 Category: Poker Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 52
#define HAND_SIZE 5

int main() {
    // Initialize deck with four suits and 13 cards per suit
    char *suits[] = {"hearts", "diamonds", "clubs", "spades"};
    char *ranks[] = {"ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "jack", "queen", "king"};
    int deck[NUM_CARDS];
    for (int i = 0; i < NUM_CARDS; i++) {
        deck[i] = i;
    }

    // Shuffle deck
    srand(time(NULL));
    for (int i = 0; i < NUM_CARDS; i++) {
        int j = rand() % NUM_CARDS;
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }

    // Deal five-card hand to player
    int hand[HAND_SIZE];
    for (int i = 0; i < HAND_SIZE; i++) {
        hand[i] = deck[i];
    }

    // Print player's hand
    printf("Your hand:\n");
    for (int i = 0; i < HAND_SIZE; i++) {
        int suit = hand[i] / 13;
        int rank = hand[i] % 13;
        printf("%s of %s\n", ranks[rank], suits[suit]);
    }
    
    return 0;
}