//FormAI DATASET v1.0 Category: Poker Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define HAND_SIZE 5

typedef enum {HEARTS, DIAMONDS, CLUBS, SPADES} Suit;
typedef enum {ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING} Rank;

typedef struct {
    Suit suit;
    Rank rank;
} Card;

Card deck[DECK_SIZE];
Card hand[HAND_SIZE];

void ShuffleDeck() {
    srand(time(NULL));
    
    for (int i = 0; i < DECK_SIZE; i++) {
        Card temp = deck[i];
        int randomIndex = rand() % DECK_SIZE;
        deck[i] = deck[randomIndex];
        deck[randomIndex] = temp;
    }
}

void DealHand() {
    for (int i = 0; i < HAND_SIZE; i++) {
        hand[i] = deck[i];
    }
}

void PrintHand() {
    for (int i = 0; i < HAND_SIZE; i++) {
        printf("%d %d\n", hand[i].rank + 1, hand[i].suit + 1);
    }
}

int main() {
    // Initialize the deck
    int index = 0;
    for (int suit = HEARTS; suit <= SPADES; suit++) {
        for (int rank = ACE; rank <= KING; rank++) {
            deck[index].suit = suit;
            deck[index].rank = rank;
            index++;
        }
    }
    
    printf("Welcome to the Surprise Poker Game!\n");
    
    printf("Shuffling the deck...\n");
    ShuffleDeck();
    
    printf("Dealing your hand...\n");
    DealHand();
    
    printf("Your hand:\n");
    PrintHand();
    
    printf("Wow, what a surprise! You got a Royal Flush!\n");
    
    return 0;
}