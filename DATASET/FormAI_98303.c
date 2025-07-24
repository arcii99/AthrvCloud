//FormAI DATASET v1.0 Category: Poker Game ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define NUM_SUITS 4
#define NUM_RANKS 13
#define NUM_CARDS 52
#define HAND_SIZE 5

enum Suit { CLUBS, DIAMONDS, HEARTS, SPADES };
enum Rank { TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };

typedef struct {
    enum Rank rank;
    enum Suit suit;
} Card;

void print_card(Card card) {
    switch (card.rank) {
        case TWO: printf("2"); break;
        case THREE: printf("3"); break;
        case FOUR: printf("4"); break;
        case FIVE: printf("5"); break;
        case SIX: printf("6"); break;
        case SEVEN: printf("7"); break;
        case EIGHT: printf("8"); break;
        case NINE: printf("9"); break;
        case TEN: printf("10"); break;
        case JACK: printf("J"); break;
        case QUEEN: printf("Q"); break;
        case KING: printf("K"); break;
        case ACE: printf("A"); break;
    }
    switch (card.suit) {
        case CLUBS: printf("\u2663"); break;
        case DIAMONDS: printf("\u2666"); break;
        case HEARTS: printf("\u2665"); break;
        case SPADES: printf("\u2660"); break;
    }
}

void print_hand(Card hand[]) {
    for (int i = 0; i < HAND_SIZE; i++) {
        print_card(hand[i]);
        printf(" ");
    }
    printf("\n");
}

void shuffle_deck(Card deck[]) {
    srand(time(NULL));
    for (int i = 0; i < NUM_CARDS; i++) {
        int j = rand() % NUM_CARDS;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void deal_cards(Card deck[], Card hand[]) {
    for (int i = 0; i < HAND_SIZE; i++) {
        hand[i] = deck[i];
    }
}

bool has_pair(Card hand[]) {
    for (int i = 0; i < HAND_SIZE - 1; i++) {
        for (int j = i + 1; j < HAND_SIZE; j++) {
            if (hand[i].rank == hand[j].rank) {
                return true;
            }
        }
    }
    return false;
}

bool has_three_of_a_kind(Card hand[]) {
    for (int i = 0; i < HAND_SIZE - 2; i++) {
        if (hand[i].rank == hand[i+1].rank && hand[i].rank == hand[i+2].rank) {
            return true;
        }
    }
    return false;
}

bool has_four_of_a_kind(Card hand[]) {
    for (int i = 0; i < HAND_SIZE - 3; i++) {
        if (hand[i].rank == hand[i+1].rank && hand[i].rank == hand[i+2].rank && hand[i].rank == hand[i+3].rank) {
            return true;
        }
    }
    return false;
}

bool has_flush(Card hand[]) {
    enum Suit suit = hand[0].suit;
    for (int i = 1; i < HAND_SIZE; i++) {
        if (hand[i].suit != suit) {
            return false;
        }
    }
    return true;
}

bool has_straight(Card hand[]) {
    for (int i = 0; i < HAND_SIZE - 1; i++) {
        if (hand[i].rank != hand[i+1].rank - 1) {
            return false;
        }
    }
    return true;
}

int evaluate_hand(Card hand[]) {
    if (has_four_of_a_kind(hand)) {
        return 8;
    }
    if (has_three_of_a_kind(hand) && has_pair(hand)) {
        return 7;
    }
    if (has_flush(hand)) {
        return 6;
    }
    if (has_straight(hand)) {
        return 5;
    }
    if (has_three_of_a_kind(hand)) {
        return 4;
    }
    int num_pairs = 0;
    for (int i = 0; i < HAND_SIZE - 1; i++) {
        for (int j = i + 1; j < HAND_SIZE; j++) {
            if (hand[i].rank == hand[j].rank) {
                num_pairs++;
            }
        }
    }
    if (num_pairs == 2) {
        return 3;
    }
    if (has_pair(hand)) {
        return 2;
    }
    return 1;
}

int main() {
    Card deck[NUM_CARDS];
    for (int i = 0; i < NUM_SUITS; i++) {
        for (int j = 0; j < NUM_RANKS; j++) {
            deck[i*NUM_RANKS+j].suit = i;
            deck[i*NUM_RANKS+j].rank = j;
        }
    }
    shuffle_deck(deck);
    Card hand[HAND_SIZE];
    deal_cards(deck, hand);
    printf("Your hand: ");
    print_hand(hand);
    int score = evaluate_hand(hand);
    switch (score) {
        case 1: printf("You have a high card.\n"); break;
        case 2: printf("You have a pair.\n"); break;
        case 3: printf("You have two pairs.\n"); break;
        case 4: printf("You have three of a kind.\n"); break;
        case 5: printf("You have a straight.\n"); break;
        case 6: printf("You have a flush.\n"); break;
        case 7: printf("You have a full house.\n"); break;
        case 8: printf("You have four of a kind.\n"); break;
    }
    return 0;
}