//FormAI DATASET v1.0 Category: Poker Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define suits and ranks
#define SUITS 4
#define RANKS 13

// create the deck of cards using a structure
struct card {
    int rank;
    int suit;
};

// function to print card in human-readable format
void print_card(struct card c) {
    char ranks[] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
    char suits[] = {'C', 'D', 'H', 'S'};
    printf("%c%c ", ranks[c.rank], suits[c.suit]);
}

// function to shuffle the deck
void shuffle_deck(struct card deck[], int num_cards) {
    srand(time(NULL));
    for (int i = 0; i < num_cards; i++) {
        int j = rand() % num_cards;
        struct card tmp = deck[i];
        deck[i] = deck[j];
        deck[j] = tmp;
    }
}

// function to deal cards to players
void deal_cards(struct card deck[], int num_cards, int num_players) {
    for (int i = 0; i < num_cards; i++) {
        printf("Card %i: ", i+1);
        print_card(deck[i]);
        printf("\n");
    }
    int cards_per_player = num_cards / num_players;
    printf("\nDealing %i cards to %i players...\n\n", cards_per_player, num_players);
    for (int i = 0; i < num_players; i++) {
        printf("Player %i's cards: ", i+1);
        for (int j = 0; j < cards_per_player; j++) {
            print_card(deck[i*cards_per_player+j]);
        }
        printf("\n");
    }
}

int main() {
    // create the deck of cards
    struct card deck[SUITS*RANKS];
    int i = 0;
    for (int s = 0; s < SUITS; s++) {
        for (int r = 0; r < RANKS; r++) {
            deck[i].suit = s;
            deck[i].rank = r;
            i++;
        }
    }

    // shuffle the deck and deal cards
    shuffle_deck(deck, SUITS*RANKS);
    deal_cards(deck, SUITS*RANKS, 4);

    return 0;
}