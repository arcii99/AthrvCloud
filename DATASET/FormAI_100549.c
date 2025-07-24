//FormAI DATASET v1.0 Category: Poker Game ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 52
#define NUM_SUITS 4
#define NUM_RANKS 13

enum Suit { CLUBS, DIAMONDS, HEARTS, SPADES };
enum Rank { ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };

struct Card {
    enum Suit suit;
    enum Rank rank;
};

void initialize_deck(struct Card deck[]) {
    int i, j, card_num = 0;
    for (i = 0; i < NUM_SUITS; i++) {
        for (j = 0; j < NUM_RANKS; j++) {
            deck[card_num].suit = i;
            deck[card_num].rank = j;
            card_num++;
        }
    }
}

void shuffle_deck(struct Card deck[]) {
    int i, j;
    struct Card temp;
    srand(time(NULL));
    for (i = 0; i < NUM_CARDS; i++) {
        j = rand() % NUM_CARDS;
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void print_card(struct Card card) {
    char* suit_names[] = { "Clubs", "Diamonds", "Hearts", "Spades" };
    char* rank_names[] = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven",
                            "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
    printf("%s of %s\n", rank_names[card.rank], suit_names[card.suit]);
}

int main() {
    struct Card deck[NUM_CARDS];
    initialize_deck(deck);
    shuffle_deck(deck);
    int i;
    printf("Your hand:\n");
    for (i = 0; i < 5; i++) {
        print_card(deck[i]);
    }
    return 0;
}