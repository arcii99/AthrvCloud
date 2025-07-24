//FormAI DATASET v1.0 Category: Poker Game ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum suits {HEARTS, SPADES, CLUBS, DIAMONDS};
enum ranks {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};

typedef struct {
    int rank;
    int suit;
} card_t;

void print_card(card_t card) {
    const char *suit_names[] = {"Hearts", "Spades", "Clubs", "Diamonds"};
    const char *rank_names[] = {"", "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    printf("%s of %s\n", rank_names[card.rank], suit_names[card.suit]);
}

void print_hand(card_t *hand, int num_cards) {
    for(int i = 0; i < num_cards; i++) {
        print_card(hand[i]);
    }
}

void swap_cards(card_t *card1, card_t *card2) {
    card_t temp = *card1;
    *card1 = *card2;
    *card2 = temp;
}

void shuffle_deck(card_t *deck, int num_cards) {
    srand(time(NULL));
    for(int i = num_cards-1; i > 0; i--) {
        int j = rand() % (i+1);
        swap_cards(&deck[i], &deck[j]);
    }
}

void deal_cards(card_t *deck, card_t *hand, int num_cards) {
    for(int i = 0; i < num_cards; i++) {
        hand[i] = deck[i];
    }
}

int is_flush(card_t *hand, int num_cards) {
    int suit = hand[0].suit;
    for(int i = 1; i < num_cards; i++) {
        if(hand[i].suit != suit) {
            return 0;
        }
    }
    return 1;
}

int is_straight(card_t *hand, int num_cards) {
    for(int i = 0; i < num_cards-1; i++) {
        if(hand[i].rank != hand[i+1].rank-1) {
            return 0;
        }
    }
    return 1;
}

void play_poker() {
    const int NUM_CARDS = 5;
    card_t deck[52];
    card_t hand[NUM_CARDS];
    for(int i = 0; i < 52; i++) {
        deck[i].rank = i % 13 + 1;
        deck[i].suit = i / 13;
    }
    shuffle_deck(deck, 52);
    deal_cards(deck, hand, NUM_CARDS);
    printf("Your hand is:\n");
    print_hand(hand, NUM_CARDS);
    if(is_flush(hand, NUM_CARDS)) {
        printf("You have a flush!\n");
    } else if(is_straight(hand, NUM_CARDS)) {
        printf("You have a straight!\n");
    }
}

int main() {
    play_poker();
    return 0;
}