//FormAI DATASET v1.0 Category: Poker Game ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define NUM_PLAYERS 4
#define HAND_SIZE 5

int deck[DECK_SIZE];

int draw_card() {
    int index = rand() % DECK_SIZE;
    while (deck[index] == -1) {  // card has already been drawn
        index = rand() % DECK_SIZE;
    }
    int card = deck[index];
    deck[index] = -1;  // mark card as drawn
    return card;
}

void init_deck() {
    for (int i = 0; i < DECK_SIZE; i++) {
        deck[i] = i;
    }
}

void shuffle_deck() {
    srand(time(NULL));
    for (int i = DECK_SIZE-1; i >= 1; i--) {
        int j = rand() % (i+1);
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void deal_cards(int (*hands)[HAND_SIZE], int num_players) {
    for (int i = 0; i < num_players; i++) {
        for (int j = 0; j < HAND_SIZE; j++) {
            hands[i][j] = draw_card();
        }
    }
}

void print_card(int card) {
    char* suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    char* ranks[] = {"Ace", "2", "3", "4", "5", "6", "7", "8" ,"9", "10", "Jack", "Queen", "King"};
    printf("%s of %s", ranks[card % 13], suits[card / 13]);
}

void print_hand(int* hand) {
    for (int i = 0; i < HAND_SIZE; i++) {
        print_card(hand[i]);
        printf("\n");
    }
}

int main() {
    init_deck();
    shuffle_deck();
    int hands[NUM_PLAYERS][HAND_SIZE];
    deal_cards(hands, NUM_PLAYERS);
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("Player %d's hand:\n", i+1);
        print_hand(hands[i]);
        printf("\n");
    }
    return 0;
}