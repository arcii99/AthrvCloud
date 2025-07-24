//FormAI DATASET v1.0 Category: Poker Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define HAND_SIZE 5

// Define Card Structure
typedef struct {
    int rank;
    int suit;
} Card;

// Function Prototypes
void sort_hand(Card hand[]);
void print_hand(Card hand[]);
void shuffle_deck(Card deck[]);

// Main Function
int main() {
    srand(time(0)); // Seed random number generator with current time
    Card deck[DECK_SIZE], hand[HAND_SIZE]; //Declare deck and hand variables
    int i, j, k = 0; //Declare counter variables
    
    // Assign values to deck and hand
    for(i = 0; i < 4; i++) {
        for(j = 1; j <= 13; j++) {
            deck[k].rank = j;
            deck[k].suit = i;
            k++;
        }
    }
    shuffle_deck(deck);
    for(i = 0; i < HAND_SIZE; i++) {
        hand[i] = deck[i];
    }
    sort_hand(hand);
    print_hand(hand);
    return 0;
}

// Function to shuffle the deck
void shuffle_deck(Card deck[]) {
    int i, j;
    Card temp;
    for(i = DECK_SIZE - 1; i > 0; i--) {
        j = rand() % (i + 1);
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Function to sort the hand by rank
void sort_hand(Card hand[]) {
    int i, j;
    Card temp;
    for(i = 0; i < HAND_SIZE; i++) {
        for(j = i + 1; j < HAND_SIZE; j++) {
            if(hand[j].rank < hand[i].rank) {
                temp = hand[i];
                hand[i] = hand[j];
                hand[j] = temp;
            }
        }
    }
}

// Function to print the hand
void print_hand(Card hand[]) {
    int i;
    for(i = 0; i < HAND_SIZE; i++) {
        printf("%d of ", hand[i].rank);
        switch(hand[i].suit) {
            case 0:
                printf("Clubs\n");
                break;
            case 1:
                printf("Diamonds\n");
                break;
            case 2:
                printf("Hearts\n");
                break;
            case 3:
                printf("Spades\n");
                break;
        }
    }
}