//FormAI DATASET v1.0 Category: Poker Game ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CARDS_PER_SUIT 13
#define NUM_SUITS 4
#define NUM_PLAYERS 4
#define HAND_SIZE 5

int deck[CARDS_PER_SUIT * NUM_SUITS];
int hands[NUM_PLAYERS][HAND_SIZE];

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void shuffle() {
    int i, j;
    srand(time(NULL));
    for (i = CARDS_PER_SUIT * NUM_SUITS - 1; i >= 1; i--) {
        j = rand() % (i + 1);
        swap(&deck[i], &deck[j]);
    }
}

void deal() {
    int i, j;
    for (i = 0; i < HAND_SIZE; i++) {
        for (j = 0; j < NUM_PLAYERS; j++) {
            hands[j][i] = deck[(i * NUM_PLAYERS) + j];
        }
    }
}

void print_hand(int player) {
    int i;
    printf("Player %d's hand: ", player);
    for (i = 0; i < HAND_SIZE; i++) {
        printf("%d ", hands[player][i]);
    }
    printf("\n");
}

int is_flush(int player) {
    int i;
    int suit = hands[player][0] / CARDS_PER_SUIT;
    for (i = 1; i < HAND_SIZE; i++) {
        if (hands[player][i] / CARDS_PER_SUIT != suit) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int i;
    for (i = 0; i < CARDS_PER_SUIT * NUM_SUITS; i++) {
        deck[i] = i;
    }
    shuffle();
    deal();
    for (i = 0; i < NUM_PLAYERS; i++) {
        print_hand(i);
        if (is_flush(i)) {
            printf("Player %d has a flush!\n", i);
        }
    }
    return 0;
}