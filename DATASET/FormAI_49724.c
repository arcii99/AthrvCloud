//FormAI DATASET v1.0 Category: Poker Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PLAYERS 4
#define NUM_DECKS 2

struct card {
    int rank;
    char suit;
};

struct hand {
    struct card cards[5];
};

void shuffle_deck(struct card deck[], int num_cards) {
    int i, j;
    struct card temp;

    srand(time(NULL));
    for (i = num_cards - 1; i > 0; i--) {
        j = rand() % (i + 1);
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void deal_cards(struct card deck[], int num_cards, struct hand hands[], int num_players) {
    int i, j, card_index = 0;

    for (i = 0; i < num_players; i++) {
        for (j = 0; j < 5; j++) {
            hands[i].cards[j] = deck[card_index++];
        }
    }
}

int main() {
    struct card deck[52 * NUM_DECKS], temp_card;
    struct hand hands[NUM_PLAYERS];
    int i, j, k, l;
    char ranks[] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
    char suits[] = {'C', 'D', 'H', 'S'};

    // Generate deck of cards
    for (i = 0; i < NUM_DECKS; i++) {
        for (j = 0; j < 4; j++) {
            for (k = 0; k < 13; k++) {
                temp_card.rank = k + 2;
                temp_card.suit = suits[j];
                deck[i * 52 + j * 13 + k] = temp_card;
            }
        }
    }

    // Shuffle deck of cards
    shuffle_deck(deck, 52 * NUM_DECKS);

    // Deal cards to players
    deal_cards(deck, 52 * NUM_DECKS, hands, NUM_PLAYERS);

    // Print each player's hand
    for (i = 0; i < NUM_PLAYERS; i++) {
        printf("Player %d:", i + 1);
        for (j = 0; j < 5; j++) {
            printf(" %c%c", ranks[hands[i].cards[j].rank - 2], hands[i].cards[j].suit);
        }
        printf("\n");
    }

    return 0;
}