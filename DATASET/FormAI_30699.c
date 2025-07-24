//FormAI DATASET v1.0 Category: Poker Game ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARDS 52
#define MAX_PLAYERS 4

enum suit {CLUBS, DIAMONDS, HEARTS, SPADES};
enum rank {TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE};

typedef struct card {
    enum suit s;
    enum rank r;
} card;

void initialize_deck(card *deck);
void shuffle_deck(card *deck);
void deal_cards(card *deck, card hand[][MAX_CARDS/MAX_PLAYERS], int num_players);
void sort_hand(card hand[]);
void print_card(card c);

int main() {
    srand(time(NULL));
    card deck[MAX_CARDS];
    card hand[MAX_PLAYERS][MAX_CARDS/MAX_PLAYERS];
    int num_players = 4;
    
    initialize_deck(deck);
    shuffle_deck(deck);
    deal_cards(deck, hand, num_players);
    
    for (int i = 0; i < num_players; i++) {
        sort_hand(hand[i]);
        printf("Player %d's hand: ", i + 1);
        for (int j = 0; j < MAX_CARDS/MAX_PLAYERS; j++) {
            print_card(hand[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}

void initialize_deck(card *deck) {
    for (int i = 0; i < MAX_CARDS; i++) {
        deck[i].s = i/13;
        deck[i].r = i%13;
    }
}

void shuffle_deck(card *deck) {
    for (int i = MAX_CARDS - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        card temp = deck[j];
        deck[j] = deck[i];
        deck[i] = temp;
    }
}

void deal_cards(card *deck, card hand[][MAX_CARDS/MAX_PLAYERS], int num_players) {
    for (int i = 0; i < MAX_CARDS/MAX_PLAYERS; i++) {
        for (int j = 0; j < num_players; j++) {
            hand[j][i] = deck[num_players*i + j];
        }
    }
}

void sort_hand(card hand[]) {
    for (int i = 0; i < MAX_CARDS/MAX_PLAYERS; i++) {
        for (int j = i + 1; j < MAX_CARDS/MAX_PLAYERS; j++) {
            if (hand[j].r < hand[i].r) {
                card temp = hand[j];
                hand[j] = hand[i];
                hand[i] = temp;
            }
        }
    }
}

void print_card(card c) {
    switch (c.r) {
        case TWO:
            printf("2");
            break;
        case THREE:
            printf("3");
            break;
        case FOUR:
            printf("4");
            break;
        case FIVE:
            printf("5");
            break;
        case SIX:
            printf("6");
            break;
        case SEVEN:
            printf("7");
            break;
        case EIGHT:
            printf("8");
            break;
        case NINE:
            printf("9");
            break;
        case TEN:
            printf("T");
            break;
        case JACK:
            printf("J");
            break;
        case QUEEN:
            printf("Q");
            break;
        case KING:
            printf("K");
            break;
        case ACE:
            printf("A");
            break;
    }
    switch (c.s) {
        case CLUBS:
            printf("C ");
            break;
        case DIAMONDS:
            printf("D ");
            break;
        case HEARTS:
            printf("H ");
            break;
        case SPADES:
            printf("S ");
            break;
    }
}