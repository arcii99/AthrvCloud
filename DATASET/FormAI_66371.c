//FormAI DATASET v1.0 Category: Poker Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define NUM_PLAYERS 4

typedef enum {CLUBS, DIAMONDS, HEARTS, SPADES} Suit;
typedef enum {ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING} Rank;

typedef struct {
    Suit suit;
    Rank rank;
} Card;

void print_card(Card card) {
    switch (card.rank) {
        case ACE:
            printf("A");
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
        default:
            printf("%d", card.rank);
            break;
    }
    switch (card.suit) {
        case CLUBS:
            printf("C");
            break;
        case DIAMONDS:
            printf("D");
            break;
        case HEARTS:
            printf("H");
            break;
        case SPADES:
            printf("S");
            break;
    }
}

void print_hand(Card hand[], int num_cards) {
    for (int i = 0; i < num_cards; i++) {
        print_card(hand[i]);
        printf(" ");
    }
    printf("\n");
}

void shuffle_deck(Card deck[]) {
    srand(time(NULL));
    for (int i = DECK_SIZE - 1; i >= 1; i--) {
        int j = rand() % (i + 1);
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void deal_cards(Card deck[], Card hands[][NUM_PLAYERS], int num_cards) {
    for (int i = 0; i < num_cards; i++) {
        for (int j = 0; j < NUM_PLAYERS; j++) {
            hands[i][j] = deck[i*NUM_PLAYERS + j];
        }
    }
}

void sort_hand(Card hand[], int num_cards) {
    for (int i = 0; i < num_cards; i++) {
        for (int j = i+1; j < num_cards; j++) {
            if (hand[i].rank > hand[j].rank) {
                Card temp = hand[i];
                hand[i] = hand[j];
                hand[j] = temp;
            }
        }
    }
}

int count_pairs(Card hand[], int num_cards) {
    int num_pairs = 0;
    for (int i = 0; i < num_cards; i++) {
        for (int j = i+1; j < num_cards; j++) {
            if (hand[i].rank == hand[j].rank) {
                num_pairs++;
            }
        }
    }
    return num_pairs;
}

int main() {
    Card deck[DECK_SIZE];
    Card hands[NUM_PLAYERS][NUM_PLAYERS];
    
    // Initialize deck
    int i = 0;
    for (Suit s = CLUBS; s <= SPADES; s++) {
        for (Rank r = ACE; r <= KING; r++) {
            deck[i].suit = s;
            deck[i].rank = r;
            i++;
        }
    }
    
    // Shuffle deck
    shuffle_deck(deck);
    
    // Deal cards
    deal_cards(deck, hands, NUM_PLAYERS);
    
    // Print hands
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("Player %d: ", i+1);
        print_hand(hands[i], NUM_PLAYERS);
    }
    
    // Evaluate hands
    for (int i = 0; i < NUM_PLAYERS; i++) {
        sort_hand(hands[i], NUM_PLAYERS);
        int num_pairs = count_pairs(hands[i], NUM_PLAYERS);
        printf("Player %d has %d pairs.\n", i+1, num_pairs);
    }
    
    return 0;
}