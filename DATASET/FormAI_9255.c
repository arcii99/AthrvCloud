//FormAI DATASET v1.0 Category: Poker Game ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 52
#define NUM_FACES 13
#define NUM_SUITS 4
#define HAND_SIZE 5

const char *faces[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
const char *suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};

typedef struct card {
    int face;
    int suit;
} Card;

typedef struct deck {
    Card cards[NUM_CARDS];
    int top_card;
} Deck;

typedef struct hand {
    Card cards[HAND_SIZE];
} Hand;

void shuffle(Deck *deck) {
    int i, j;
    Card temp;
    
    for (i = 0; i < NUM_CARDS; i++) {
        j = rand() % NUM_CARDS;
        temp = deck->cards[i];
        deck->cards[i] = deck->cards[j];
        deck->cards[j] = temp;
    }
}

void init_deck(Deck *deck) {
    int i, j, k = 0;
    
    for (i = 0; i < NUM_FACES; i++) {
        for (j = 0; j < NUM_SUITS; j++) {
            deck->cards[k].face = i;
            deck->cards[k].suit = j;
            k++;
        }
    }
    
    deck->top_card = 0;
    shuffle(deck);
}

void print_card(Card card) {
    printf("%s of %s\n", faces[card.face], suits[card.suit]);
}

void print_hand(Hand hand) {
    int i;
    
    for (i = 0; i < HAND_SIZE; i++) {
        print_card(hand.cards[i]);
    }
}

void deal_hand(Hand *hand, Deck *deck) {
    int i;
    
    for (i = 0; i < HAND_SIZE; i++) {
        hand->cards[i] = deck->cards[deck->top_card];
        deck->top_card++;
    }
}

int main() {
    Deck deck;
    Hand hand;
    
    srand(time(NULL));
    init_deck(&deck);
    deal_hand(&hand, &deck);
    print_hand(hand);
    
    return 0;
}