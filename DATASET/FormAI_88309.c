//FormAI DATASET v1.0 Category: Poker Game ; Style: synchronous
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

#define DECK_SIZE 52 
#define HAND_SIZE 5 

typedef enum card_suit { 
    HEARTS, 
    DIAMONDS, 
    CLUBS, 
    SPADES 
} card_suit;

typedef struct card { 
    int rank; 
    card_suit suit; 
} card; 

void shuffle_deck(card* deck) { 
    int i, j; 
    card temp; 

    srand(time(NULL)); 

    for (i = 0; i < DECK_SIZE; i++) { 
        j = rand() % DECK_SIZE; 

        temp = deck[i]; 
        deck[i] = deck[j]; 
        deck[j] = temp; 
    } 
} 

void print_card(card c) { 
    char suit; 

    switch (c.suit) { 
    case HEARTS: 
        suit = 'H'; 
        break; 
    case DIAMONDS: 
        suit = 'D'; 
        break; 
    case CLUBS: 
        suit = 'C'; 
        break; 
    case SPADES: 
        suit = 'S'; 
        break; 
    } 

    printf("%d-%c ", c.rank, suit); 
} 

void print_hand(card* hand) { 
    int i; 

    for (i = 0; i < HAND_SIZE; i++) { 
        print_card(hand[i]); 
    } 

    printf("\n"); 
} 

int rank_hand(card* hand) { 
    // TODO: Implement hand ranking function 
} 

int main() { 
    card deck[DECK_SIZE]; 
    card hand[HAND_SIZE]; 
    int i; 

    for (i = 0; i < DECK_SIZE; i++) { 
        deck[i].rank = (i % 13) + 1; 

        if (i < 13) { 
            deck[i].suit = HEARTS; 
        } else if (i < 26) { 
            deck[i].suit = DIAMONDS; 
        } else if (i < 39) { 
            deck[i].suit = CLUBS; 
        } else { 
            deck[i].suit = SPADES; 
        } 
    } 

    shuffle_deck(deck); 

    for (i = 0; i < HAND_SIZE; i++) { 
        hand[i] = deck[i]; 
    } 

    printf("Your hand: "); 
    print_hand(hand); 

    printf("Hand ranking: %d\n", rank_hand(hand)); 

    return 0; 
}