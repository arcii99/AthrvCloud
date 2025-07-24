//FormAI DATASET v1.0 Category: Poker Game ; Style: accurate
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
  
#define SUITS 4 
#define FACES 13 
#define CARDS 5 

// function prototypes 
void shuffleDeck(unsigned int deck[][FACES]); 
void deal(unsigned int deck[][FACES], const char *face[], const char *suit[]); 
int evaluateHand(unsigned int hand[][2], const char *face[], const char *suit[]); 

int main(void) 
{ 
    // initialize two-dimensional array of deck 
    unsigned int deck[SUITS][FACES] = { 0 }; 
    srand(time(NULL)); 

    // initialize array of suits                     
    const char *suit[SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"}; 

    // initialize array of face values                   
    const char *face[FACES] = 
        {"Ace", "Deuce", "Three", "Four", 
         "Five", "Six", "Seven", "Eight", 
         "Nine", "Ten", "Jack", "Queen", "King"}; 

    shuffleDeck(deck); 
    deal(deck, face, suit); 

    return 0; 
} 

// shuffle cards in deck 
void shuffleDeck(unsigned int deck[][FACES]) 
{ 
    // for each card, choose new random location for card 
    for (size_t card = 1; card <= CARDS; ++card) { 
        for (size_t row = 0; row < SUITS; ++row) { 
            for (size_t column = 0; column < FACES; ++column) { 
                size_t newRow = rand() % SUITS; 
                size_t newColumn = rand() % FACES; 

                unsigned int temp = deck[row][column]; 
                deck[row][column] = deck[newRow][newColumn]; 
                deck[newRow][newColumn] = temp; 
            } 
        } 
    } 
} 

// deal cards in deck 
void deal(unsigned int deck[][FACES], const char *face[], const char *suit[]) 
{ 
    // initialize hand array
    unsigned int hand[CARDS][2] = { 0 }; 

    // deal each of the cards in the deck 
    for (size_t card = 0; card < CARDS; ++card) { 
        for (size_t row = 0; row < SUITS; ++row) { 
            for (size_t column = 0; column < FACES; ++column) { 
                // if slot contains current card, deal card 
                if (deck[row][column] == card) { 
                    hand[card][0] = row; 
                    hand[card][1] = column; 
                    deck[row][column] = 50; // mark card as dealt 
                    break; 
                } 
            } 
        } 
    } 

    // evaluate the hand and display the results
    int result = evaluateHand(hand, face, suit);
    printf("\nResult: %d\n", result);
} 

// evaluate the hand
int evaluateHand(unsigned int hand[][2], const char *face[], const char *suit[]) 
{ 
    // determine if hand contains a pair
    int pair = 0;
    for (size_t card = 0; card < CARDS; ++card) {
        for (size_t card2 = card + 1; card2 < CARDS; ++card2) {
            if (hand[card][1] == hand[card2][1]) {
                pair = 1;
                break;
            }
        }
    }

    // determine if hand contains three of a kind
    int threeKind = 0;
    for (size_t card = 0; card < CARDS; ++card) {
        int numMatches = 0;
        for (size_t card2 = 0; card2 < CARDS; ++card2) {
            if (hand[card][1] == hand[card2][1]) {
                numMatches++;
            }
        }
        if (numMatches == 3) {
            threeKind = 1;
            break;
        }
    }

    // determine if hand contains four of a kind
    int fourKind = 0;
    for (size_t card = 0; card < CARDS; ++card) {
        int numMatches = 0;
        for (size_t card2 = 0; card2 < CARDS; ++card2) {
            if (hand[card][1] == hand[card2][1]) {
                numMatches++;
            }
        }
        if (numMatches == 4) {
            fourKind = 1;
            break;
        }
    }

    // determine if hand contains a flush
    int flush = 1;
    for (size_t card = 1; card < CARDS; ++card) {
        if (hand[card][0] != hand[0][0]) {
            flush = 0;
            break;
        }
    }

    // determine if hand contains a straight
    int straight = 1;
    for (size_t card = 0; card < CARDS - 1; ++card) {
        if (hand[card][1] != hand[card + 1][1] - 1) {
            straight = 0;
            break;
        }
    }

    // determine if hand contains a straight flush
    int straightFlush = straight && flush;

    // determine the hand's value
    if (straightFlush) {
        return 9;
    } else if (fourKind) {
        return 8;
    } else if (threeKind && pair) {
        return 7;
    } else if (flush) {
        return 6;
    } else if (straight) {
        return 5;
    } else if (threeKind) {
        return 4;
    } else if (pair == 2) {
        return 3;
    } else if (pair) {
        return 2;
    } else {
        return 1;
    }
}