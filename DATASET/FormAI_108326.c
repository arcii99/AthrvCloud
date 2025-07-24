//FormAI DATASET v1.0 Category: Poker Game ; Style: artistic
/* A Poker Game in C */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SUITS 4
#define NUM_RANKS 13
#define HAND_SIZE 5

typedef enum { false, true } bool;

typedef struct Card {
    int rank;
    int suit;
} Card;

typedef struct Player {
    Card hand[HAND_SIZE];
    int num_cards;
} Player;

/* Initializes the deck with cards */
void initialize_deck(Card deck[]) {
    int i, j, index = 0;
    for (i = 0; i < NUM_SUITS; i++) {
        for (j = 0; j < NUM_RANKS; j++) {
            deck[index].suit = i;
            deck[index].rank = j;
            index++;
        }
    }
}

/* Shuffles the deck of cards */
void shuffle_deck(Card deck[]) {
    int i, j;
    Card temp;
    for (i = 0; i < NUM_SUITS * NUM_RANKS; i++) {
        j = rand() % (NUM_SUITS * NUM_RANKS);
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

/* Deals the cards to the players */
void deal_cards(Card deck[], Player players[], int num_players) {
    int i, j;
    for (i = 0; i < num_players; i++) {
        for (j = 0; j < HAND_SIZE; j++) {
            players[i].hand[j] = deck[i * HAND_SIZE + j];
        }
        players[i].num_cards = HAND_SIZE;
    }
}

/* Prints the card */
void print_card(Card card) {
    const char *ranks[] = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven",
                            "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
    const char *suits[] = { "Hearts", "Diamonds", "Clubs", "Spades" };
    printf("%s of %s\n", ranks[card.rank], suits[card.suit]);
}

/* Prints the hand */
void print_hand(Player player) {
    int i;
    for (i = 0; i < player.num_cards; i++) {
        print_card(player.hand[i]);
    }
}

/* Determines if a hand is a flush */
bool is_flush(Player player) {
    int i;
    for (i = 1; i < player.num_cards; i++) {
        if (player.hand[i].suit != player.hand[0].suit) {
            return false;
        }
    }
    return true;
}

/* Determines if a hand is a straight */
bool is_straight(Player player) {
    int i;
    for (i = 1; i < player.num_cards; i++) {
        if (player.hand[i].rank != player.hand[i - 1].rank + 1) {
            return false;
        }
    }
    return true;
}

/* Determines the poker hand */
void determine_hand(Player player) {
    if (is_flush(player) && is_straight(player)) {
        printf("Royal flush!\n");
    } else if (is_flush(player)) {
        printf("Flush!\n");
    } else if (is_straight(player)) {
        printf("Straight!\n");
    } else {
        printf("Nothing special!\n");
    }
}

/* The main function */
int main(void) {
    srand((unsigned) time(NULL));
    Card deck[NUM_SUITS * NUM_RANKS];
    initialize_deck(deck);
    shuffle_deck(deck);

    Player players[2];
    deal_cards(deck, players, 2);
    printf("Player 1:\n");
    print_hand(players[0]);
    determine_hand(players[0]);
    printf("\n");
    printf("Player 2:\n");
    print_hand(players[1]);
    determine_hand(players[1]);

    return 0;
}