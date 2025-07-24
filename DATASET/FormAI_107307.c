//FormAI DATASET v1.0 Category: Poker Game ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PLAYERS 4
#define NUM_CARDS 52
#define HAND_SIZE 5

struct card {
    int value;
    char suit;
};

typedef struct card Card;

Card deck[NUM_CARDS];
Card player_hands[NUM_PLAYERS][HAND_SIZE];

void initialize_deck() {
    int i;
    for (i = 0; i < NUM_CARDS; i++) {
        deck[i].value = i % 13 + 1;
        if (i < 13) {
            deck[i].suit = 'C';
        } else if (i < 26) {
            deck[i].suit = 'D';
        } else if (i < 39) {
            deck[i].suit = 'H';
        } else {
            deck[i].suit = 'S';
        }
    }
}

void shuffle_deck() {
    srand(time(NULL));
    int i, j;
    Card temp;
    for (i = 0; i < NUM_CARDS; i++) {
        j = rand() % NUM_CARDS;
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void deal_hands() {
    int i, j;
    for (i = 0; i < NUM_PLAYERS; i++) {
        for (j = 0; j < HAND_SIZE; j++) {
            player_hands[i][j] = deck[i * HAND_SIZE + j];
        }
    }
}

void print_hand(Card hand[HAND_SIZE]) {
    int i;
    for (i = 0; i < HAND_SIZE; i++) {
        printf("%d%c ", hand[i].value, hand[i].suit);
    }
    printf("\n");
}

void print_hands() {
    int i;
    for (i = 0; i < NUM_PLAYERS; i++) {
        printf("Player %d: ", i + 1);
        print_hand(player_hands[i]);
    }
}

int main() {
    int i;
    initialize_deck();
    shuffle_deck();
    deal_hands();
    print_hands();
    return 0;
}