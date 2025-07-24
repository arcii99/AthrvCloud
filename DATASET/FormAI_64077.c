//FormAI DATASET v1.0 Category: Poker Game ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define CARD_VALUE 13
#define NUM_SUITS 4

const char* suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
const char* ranks[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

typedef struct {
    char* suit;
    char* rank;
    int value;
} Card;

void create_deck(Card deck[]) {
    int index = 0;
    for (int suit_idx = 0; suit_idx < NUM_SUITS; suit_idx++) {
        for (int rank_idx = 0; rank_idx < CARD_VALUE; rank_idx++) {
            Card new_card = {suits[suit_idx], ranks[rank_idx], rank_idx + 1};
            deck[index++] = new_card;
        }   
    }
}

void shuffle_deck(Card deck[]) {
    srand(time(NULL));
    for (int i = 0; i < DECK_SIZE; i++) {
        int random_idx = rand() % DECK_SIZE;
        Card temp_card = deck[i];
        deck[i] = deck[random_idx];
        deck[random_idx] = temp_card;
    }
}

void create_players(Card deck[], Card player1[], Card player2[]) {
    for (int i = 0; i < DECK_SIZE; i += 2) {
        player1[i / 2] = deck[i];
        player2[i / 2] = deck[i + 1];
    }
}

void print_card(Card card) {
    printf("%s of %s\n", card.rank, card.suit);
}

void print_hand(Card hand[]) {
    for (int i = 0; i < DECK_SIZE / 2; i++) {
        printf("Card %d: ", i + 1);
        print_card(hand[i]);
    }
}

void play_game(Card deck[]) {
    Card player1[DECK_SIZE / 2];
    Card player2[DECK_SIZE / 2];

    create_players(deck, player1, player2);

    printf("Player 1's hand:\n");
    print_hand(player1);

    printf("\n");

    printf("Player 2's hand:\n");
    print_hand(player2);

    printf("\n");
}

int main() {
    Card deck[DECK_SIZE];

    create_deck(deck);
    shuffle_deck(deck);
    play_game(deck);

    return 0;
}