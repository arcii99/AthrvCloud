//FormAI DATASET v1.0 Category: Poker Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_CARDS_IN_DECK 52
#define NUM_PLAYERS 2
#define NUM_HANDS 2
#define NUM_CARDS_PER_HAND 5

int deck[NUM_CARDS_IN_DECK];
int player_hands[NUM_PLAYERS][NUM_HANDS][NUM_CARDS_PER_HAND];

char* get_card_name(int card_value) {
    int rank = card_value % 13;
    char* suit;

    switch (card_value / 13) {
        case 0:
            suit = "Hearts";
            break;
        case 1:
            suit = "Diamonds";
            break;
        case 2:
            suit = "Clubs";
            break;
        case 3:
            suit = "Spades";
            break;
    }

    char* rank_strings[13] = {
        "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"
    };

    char* result = malloc(20);
    sprintf(result, "%s of %s", rank_strings[rank], suit);
    return result;
}

void print_card(int card_value) {
    printf("%s\n", get_card_name(card_value));
}

void print_hand(int hand[NUM_CARDS_PER_HAND]) {
    for (int i = 0; i < NUM_CARDS_PER_HAND; i++) {
        print_card(hand[i]);
    }
}

void shuffle_deck() {
    for (int i = 0; i < NUM_CARDS_IN_DECK; i++) {
        deck[i] = i;
    }

    for (int i = NUM_CARDS_IN_DECK - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void deal_hands() {
    for (int i = 0; i < NUM_PLAYERS; i++) {
        for (int j = 0; j < NUM_HANDS; j++) {
            for (int k = 0; k < NUM_CARDS_PER_HAND; k++) {
                int card_value = deck[NUM_CARDS_PER_HAND * j + k];
                player_hands[i][j][k] = card_value;
            }
        }
    }
}

void print_hands() {
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("Player %d's hands:\n", i + 1);
        for (int j = 0; j < NUM_HANDS; j++) {
            printf("Hand %d:\n", j + 1);
            print_hand(player_hands[i][j]);
        }
    }
}

int main() {
    srand(time(NULL));
    shuffle_deck();
    deal_hands();
    print_hands();
    return 0;
}