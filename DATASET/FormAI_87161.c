//FormAI DATASET v1.0 Category: Poker Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 52
#define NUM_SUITS 4
#define NUM_RANKS 13

void shuffle_deck(int deck[]) {
    int i, j, temp;
    for (i = NUM_CARDS - 1; i > 0; i--) {
        j = rand() % (i + 1);
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void print_card(int card) {
    int rank = card % NUM_RANKS;
    int suit = card / NUM_RANKS;
    char ranks[] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
    char suits[] = {'C', 'D', 'H', 'S'};
    printf("%c%c ", ranks[rank], suits[suit]);
}

void print_hand(int hand[]) {
    int i;
    for (i = 0; i < 5; i++) {
        print_card(hand[i]);
    }
}

int main() {
    int deck[NUM_CARDS];
    int i, j;
    for (i = 0; i < NUM_CARDS; i++) {
        deck[i] = i;
    }
    srand(time(NULL));
    shuffle_deck(deck);
    int hand[5];
    for (i = 0; i < 5; i++) {
        hand[i] = deck[i];
    }
    printf("Your hand: ");
    print_hand(hand);
    return 0;
}