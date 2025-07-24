//FormAI DATASET v1.0 Category: Poker Game ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_CARDS_IN_DECK 52
#define NUM_CARDS_IN_HAND 5
#define NUM_SUITS 4
#define NUM_RANKS 13

// Definition of the Card struct
typedef struct {
    int rank;
    int suit;
} Card;

// Definition of the Hand struct
typedef struct {
    Card cards[NUM_CARDS_IN_HAND];
} Hand;

// Function to print the rank of a card
char* getRank(int rank) {
    char* ranks[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    return ranks[rank];
}

// Function to print the suit of a card
char* getSuit(int suit) {
    char* suits[] = {"Spades", "Hearts", "Diamonds", "Clubs"};
    return suits[suit];
}

// Function to initialize the deck of cards
void initDeck(Card deck[]) {
    int i, j, index;
    for (i = 0; i < NUM_SUITS; i++) {
        for (j = 0; j < NUM_RANKS; j++) {
            index = i * NUM_RANKS + j;
            deck[index].suit = i;
            deck[index].rank = j;
        }
    }
}

// Function to shuffle the deck of cards
void shuffleDeck(Card deck[]) {
    int i, j, index;
    Card temp;
    for (i = 0; i < NUM_CARDS_IN_DECK; i++) {
        j = rand() % NUM_CARDS_IN_DECK;
        
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Function to print the deck of cards
void printDeck(Card deck[]) {
    int i;
    for (i = 0; i < NUM_CARDS_IN_DECK; i++) {
        printf("%s of %s\n", getRank(deck[i].rank), getSuit(deck[i].suit));
    }
}

// Function to deal cards to a hand from the deck
void dealHand(Card deck[], Hand* hand) {
    int i;
    for (i = 0; i < NUM_CARDS_IN_HAND; i++) {
        hand->cards[i] = deck[i];
    }
}

// Function to print a hand of cards
void printHand(Hand* hand) {
    int i;
    for (i = 0; i < NUM_CARDS_IN_HAND; i++) {
        printf("%s of %s\n", getRank(hand->cards[i].rank), getSuit(hand->cards[i].suit));
    }
}

// Function to determine if a hand contains a pair
int isPair(Hand* hand) {
    int i, j;
    for (i = 0; i < NUM_CARDS_IN_HAND - 1; i++) {
        for (j = i + 1; j < NUM_CARDS_IN_HAND; j++) {
            if (hand->cards[i].rank == hand->cards[j].rank) {
                return 1;
            }
        }
    }
    return 0;
}

// Function to determine if a hand contains two pairs
int isTwoPairs(Hand* hand) {
    int i, j, count = 0;
    for (i = 0; i < NUM_CARDS_IN_HAND - 1; i++) {
        for (j = i + 1; j < NUM_CARDS_IN_HAND; j++) {
            if (hand->cards[i].rank == hand->cards[j].rank) {
                count++;
            }
        }
    }
    if (count == 2) {
        return 1;
    }
    return 0;
}

// Function to determine if a hand contains three of a kind
int isThreeOfAKind(Hand* hand) {
    int i, j, count = 0;
    for (i = 0; i < NUM_CARDS_IN_HAND - 2; i++) {
        for (j = i + 1; j < NUM_CARDS_IN_HAND - 1; j++) {
            if (hand->cards[i].rank == hand->cards[j].rank) {
                count++;
            }
            if (hand->cards[j].rank == hand->cards[j+1].rank) {
                count++;
            }
            if (count == 2) {
                return 1;
            }
        }
    }
    return 0;
}

// Function to determine if a hand contains a straight
int isStraight(Hand* hand) {
    int i, j, count = 0;
    for (i = 0; i < NUM_CARDS_IN_HAND - 1; i++) {
        if (hand->cards[i].rank == hand->cards[i+1].rank - 1) {
            count++;
        }
    }
    if (count == 4) {
        return 1;
    }
    return 0;
}

// Function to determine if a hand contains a flush
int isFlush(Hand* hand) {
    int i;
    for (i = 1; i < NUM_CARDS_IN_HAND; i++) {
        if (hand->cards[i].suit != hand->cards[0].suit) {
            return 0;
        }
    }
    return 1;
}

// Function to determine if a hand contains a full house
int isFullHouse(Hand* hand) {
    int i, j, count = 0, pairRank = -1, threeOfAKindRank = -1;
    for (i = 0; i < NUM_CARDS_IN_HAND - 2; i++) {
        for (j = i + 1; j < NUM_CARDS_IN_HAND - 1; j++) {
            if (hand->cards[i].rank == hand->cards[j].rank) {
                pairRank = hand->cards[i].rank;
            }
            if (hand->cards[j].rank == hand->cards[j+1].rank) {
                threeOfAKindRank = hand->cards[j].rank;
            }
            if (pairRank >= 0 && threeOfAKindRank >= 0) {
                if (pairRank != threeOfAKindRank) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

// Function to determine if a hand contains four of a kind
int isFourOfAKind(Hand* hand) {
    int i, j, count = 0;
    for (i = 0; i < NUM_CARDS_IN_HAND - 3; i++) {
        for (j = i + 1; j < NUM_CARDS_IN_HAND - 2; j++) {
            if (hand->cards[i].rank == hand->cards[j].rank) {
                count++;
            }
            if (hand->cards[j].rank == hand->cards[j+1].rank) {
                count++;
            }
            if (count == 3) {
                return 1;
            }
        }
    }
    return 0;
}

// Function to determine if a hand contains a straight flush
int isStraightFlush(Hand* hand) {
    if (isStraight(hand) && isFlush(hand)) {
        return 1;
    }
    return 0;
}

// Function to determine the rank of a hand
int getHandRank(Hand* hand) {
    if (isStraightFlush(hand)) {
        return 8;
    }
    if (isFourOfAKind(hand)) {
        return 7;
    }
    if (isFullHouse(hand)) {
        return 6;
    }
    if (isFlush(hand)) {
        return 5;
    }
    if (isStraight(hand)) {
        return 4;
    }
    if (isThreeOfAKind(hand)) {
        return 3;
    }
    if (isTwoPairs(hand)) {
        return 2;
    }
    if (isPair(hand)) {
        return 1;
    }
    return 0;
}

int main() {
    Card deck[NUM_CARDS_IN_DECK];
    Hand hand;
    int i, rank;
    
    // Seed the random number generator
    srand(time(NULL));
    
    // Initialize the deck of cards and shuffle it
    initDeck(deck);
    shuffleDeck(deck);
    
    // Deal a hand and print the cards in the hand
    dealHand(deck, &hand);
    printf("Your hand:\n");
    printHand(&hand);
    
    // Determine the rank of the hand and print it
    rank = getHandRank(&hand);
    switch (rank) {
        case 0:
            printf("You have a high card.\n");
            break;
        case 1:
            printf("You have a pair.\n");
            break;
        case 2:
            printf("You have two pairs.\n");
            break;
        case 3:
            printf("You have three of a kind.\n");
            break;
        case 4:
            printf("You have a straight.\n");
            break;
        case 5:
            printf("You have a flush.\n");
            break;
        case 6:
            printf("You have a full house.\n");
            break;
        case 7:
            printf("You have four of a kind.\n");
            break;
        case 8:
            printf("You have a straight flush!\n");
            break;
    }

    return 0;
}