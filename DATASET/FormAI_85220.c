//FormAI DATASET v1.0 Category: Poker Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_CARDS_IN_DECK 52
#define NUM_CARDS_IN_HAND 5

// card suit enum
enum Suit {
    Hearts = 0,
    Diamonds,
    Clubs,
    Spades
};

// card value enum
enum Value {
    Ace = 1,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King
};

// card struct
typedef struct {
    enum Suit suit;
    enum Value value;
} Card;

// deck struct
typedef struct {
    Card cards[NUM_CARDS_IN_DECK];
    int num_cards;
} Deck;

// hand struct
typedef struct {
    Card cards[NUM_CARDS_IN_HAND];
} Hand;

// initialize deck
void init_deck(Deck *deck) {
    // set number of cards in deck
    deck->num_cards = NUM_CARDS_IN_DECK;
    
    int i = 0;
    // initialize deck with all cards
    for (enum Suit s = Hearts; s <= Spades; s++) {
        for (enum Value v = Ace; v <= King; v++) {
            deck->cards[i].suit = s;
            deck->cards[i].value = v;
            i++;
        }
    }
}

// shuffle deck
void shuffle_deck(Deck *deck) {
    srand(time(NULL)); // set random seed
    
    // shuffle deck by swapping cards randomly
    for (int i = deck->num_cards - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Card temp = deck->cards[i];
        deck->cards[i] = deck->cards[j];
        deck->cards[j] = temp;
    }
}

// deal hand
void deal_hand(Deck *deck, Hand *hand) {
    // take the top NUM_CARDS_IN_HAND cards from the deck and add them to the hand
    memcpy(hand->cards, deck->cards, sizeof(Card) * NUM_CARDS_IN_HAND);
    
    // remove dealt cards from deck by shifting remaining cards to the left
    memmove(deck->cards, &deck->cards[NUM_CARDS_IN_HAND], sizeof(Card) * (deck->num_cards - NUM_CARDS_IN_HAND));
    deck->num_cards -= NUM_CARDS_IN_HAND;
}

// print card
void print_card(Card *c) {
    if (c->value >= Two && c->value <= Ten) {
        printf("%d", c->value);
    } else {
        switch (c->value) {
            case Ace:
                printf("A");
                break;
            case Jack:
                printf("J");
                break;
            case Queen:
                printf("Q");
                break;
            case King:
                printf("K");
                break;
        }
    }
    switch (c->suit) {
        case Hearts:
            printf("H ");
            break;
        case Diamonds:
            printf("D ");
            break;
        case Clubs:
            printf("C ");
            break;
        case Spades:
            printf("S ");
            break;
    }
}

// print hand
void print_hand(Hand *hand) {
    for (int i = 0; i < NUM_CARDS_IN_HAND; i++) {
        print_card(&hand->cards[i]);
    }
}

// sort hand by value (bubble sort)
void sort_hand(Hand *hand) {
    for (int i = 0; i < NUM_CARDS_IN_HAND - 1; i++) {
        for (int j = 0; j < NUM_CARDS_IN_HAND - i - 1; j++) {
            if (hand->cards[j].value > hand->cards[j+1].value) {
                Card temp = hand->cards[j];
                hand->cards[j] = hand->cards[j+1];
                hand->cards[j+1] = temp;
            }
        }
    }
}

// check for pair
int has_pair(Hand *hand) {
    for (int i = 0; i < NUM_CARDS_IN_HAND - 1; i++) {
        for (int j = i + 1; j < NUM_CARDS_IN_HAND; j++) {
            if (hand->cards[i].value == hand->cards[j].value) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    Deck deck;
    Hand hand;
    
    // initialize deck and shuffle
    init_deck(&deck);
    shuffle_deck(&deck);
    
    // deal a hand
    deal_hand(&deck, &hand);
    
    // sort hand by value
    sort_hand(&hand);
    
    // print hand
    printf("Your hand is: ");
    print_hand(&hand);
    
    // check for pair
    if (has_pair(&hand)) {
        printf("\nYou have a pair!");
    } else {
        printf("\nYou do not have a pair.");
    }
    
    return 0;
}