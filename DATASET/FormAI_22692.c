//FormAI DATASET v1.0 Category: Poker Game ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// define constants for the number of players and cards per hand
#define NUM_PLAYERS 4
#define NUM_CARDS 5

// function to assign suits to cards
char* assign_suit(int suit) {
    switch(suit) {
        case 0:
            return "Hearts";
        case 1:
            return "Diamonds";
        case 2:
            return "Clubs";
        case 3:
            return "Spades";
        default:
            return "Invalid Suit";
    }
}

// function to assign values to cards
char* assign_value(int value) {
    switch(value) {
        case 1:
            return "Ace";
        case 2:
            return "2";
        case 3:
            return "3";
        case 4:
            return "4";
        case 5:
            return "5";
        case 6:
            return "6";
        case 7:
            return "7";
        case 8:
            return "8";
        case 9:
            return "9";
        case 10:
            return "10";
        case 11:
            return "Jack";
        case 12:
            return "Queen";
        case 13:
            return "King";
        default:
            return "Invalid Value";
    }
}

int main() {
    // initialize random number generator
    srand(time(0));
    
    // declare variables to store the deck and each player's hand
    int deck[52];
    int player_hands[NUM_PLAYERS][NUM_CARDS];
    
    // initialize the deck with values 1-52 (representing the 52 cards in a deck)
    for(int i = 0; i < 52; i++) {
        deck[i] = i+1;
    }
    
    // shuffle the deck by swapping cards randomly
    for(int i = 0; i < 52; i++) {
        int j = rand() % 52;
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
    
    // deal cards to each player by taking the first NUM_CARDS cards from the deck
    for(int i = 0; i < NUM_PLAYERS; i++) {
        for(int j = 0; j < NUM_CARDS; j++) {
            player_hands[i][j] = deck[i*NUM_CARDS + j];
        }
    }
    
    // print out each player's hand
    for(int i = 0; i < NUM_PLAYERS; i++) {
        printf("Player %d's hand:\n", i+1);
        for(int j = 0; j < NUM_CARDS; j++) {
            int card = player_hands[i][j];
            int suit = (card - 1) / 13;
            int value = (card - 1) % 13 + 1;
            
            printf("%s of %s\n", assign_value(value), assign_suit(suit));
        }
        printf("\n");
    }
    
    return 0;
}