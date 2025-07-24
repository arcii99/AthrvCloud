//FormAI DATASET v1.0 Category: Poker Game ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define DECK_SIZE 52
#define HAND_SIZE 5

typedef enum { HEARTS, DIAMONDS, CLUBS, SPADES } Suit;
typedef enum { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING } Rank;

typedef struct {
    Suit suit;
    Rank rank;
} Card;

typedef struct {
    Card cards[HAND_SIZE];
    int score;
} Hand;

Card deck[DECK_SIZE];
int topCardIndex = 0;

// Function to create a new deck of cards
void createDeck() {
    int index = 0;
    for (Suit s = HEARTS; s <= SPADES; s++) {
        for (Rank r = ACE; r <= KING; r++) {
            deck[index].suit = s;
            deck[index].rank = r;
            index++;
        }
    }
}

// Function to shuffle the deck of cards
void shuffleDeck() {
    topCardIndex = 0;
    srand(time(NULL));
    for (int i = 0; i < DECK_SIZE; i++) {
        int randomIndex = rand() % DECK_SIZE;
        Card temp = deck[i];
        deck[i] = deck[randomIndex];
        deck[randomIndex] = temp;
    }
}

// Function to deal cards to a hand
void dealCards(Hand *hand) {
    for (int i = 0; i < HAND_SIZE; i++) {
        hand->cards[i] = deck[topCardIndex++];
    }
}

// Function to print a card
void printCard(Card card) {
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
    }
    switch (card.suit) {
        case HEARTS:
            printf("♥ ");
            break;
        case DIAMONDS:
            printf("♦ ");
            break;
        case CLUBS:
            printf("♣ ");
            break;
        case SPADES:
            printf("♠ ");
            break;
    }
}

// Function to print a hand
void printHand(Hand hand) {
    for (int i = 0; i < HAND_SIZE; i++) {
        printCard(hand.cards[i]);
    }
}

// Function to determine whether a hand contains a pair
bool containsPair(Hand hand) {
    for (int i = 0; i < HAND_SIZE; i++) {
        for (int j = i + 1; j < HAND_SIZE; j++) {
            if (hand.cards[i].rank == hand.cards[j].rank) {
                return true;
            }
        }
    }
    return false;
}

// Function to determine the score of a hand
void calculateScore(Hand *hand) {
    if (containsPair(*hand)) {
        hand->score = 1;
    } else {
        hand->score = 0;
    }
}

int main() {
    createDeck();
    shuffleDeck();

    Hand playerHand;
    dealCards(&playerHand);

    printf("Your hand: ");
    printHand(playerHand);

    calculateScore(&playerHand);
    printf("\nScore: %d\n", playerHand.score);

    return 0;
}