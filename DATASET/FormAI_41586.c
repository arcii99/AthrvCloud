//FormAI DATASET v1.0 Category: Poker Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
void shuffleDeck(int deck[][13]);
void dealCards(int deck[][13], const char *suit[], const char *face[]);
int getCardValue(int card);
void sortHand(int hand[], int size);
int analyzeHand(int hand[]);
void printHand(int hand[], const char *suit[], const char *face[], int size);

int main(void) {
    // seed random number generator
    srand(time(NULL));

    // initialize deck of cards
    int deck[4][13] = { {0} };

    // initialize suits and faces array
    const char *suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };
    const char *face[13] = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };

    // shuffle the deck
    shuffleDeck(deck);

    // deal cards to the players
    dealCards(deck, suit, face);

    return 0;
}

// shuffle the deck of cards
void shuffleDeck(int deck[][13]) {
    int row = 0;
    int column = 0;

    for (int card = 1; card <= 52; card++) {
        do {
            row = rand() % 4;
            column = rand() % 13;
        } while (deck[row][column] != 0);

        deck[row][column] = card;
    }
}

// deal cards to the players
void dealCards(int deck[][13], const char *suit[], const char *face[]) {
    int player1[5] = { 0 };
    int player2[5] = { 0 };
    int topCard = 0;

    // deal five cards to player 1
    for (int i = 0; i < 5; i++) {
        for (int row = 0; row < 4; row++) {
            for (int column = 0; column < 13; column++) {
                if (deck[row][column] == ++topCard) {
                    player1[i] = deck[row][column];
                    deck[row][column] = 0;
                    break;
                }
            }
        }
    }

    topCard = 5;

    // deal five cards to player 2
    for (int i = 0; i < 5; i++) {
        for (int row = 0; row < 4; row++) {
            for (int column = 0; column < 13; column++) {
                if (deck[row][column] == ++topCard) {
                    player2[i] = deck[row][column];
                    deck[row][column] = 0;
                    break;
                }
            }
        }
    }

    // sort players' hands
    sortHand(player1, 5);
    sortHand(player2, 5);

    // print players' hands
    printf("Player 1's hand:\n");
    printHand(player1, suit, face, 5);
    printf("Hand score: %d\n", analyzeHand(player1));
    printf("\nPlayer 2's hand:\n");
    printHand(player2, suit, face, 5);
    printf("Hand score: %d\n", analyzeHand(player2));
}

// get the numeric value of a card
int getCardValue(int card) {
    return (card - 1) % 13 + 1;
}

// sort a hand of cards in ascending order
void sortHand(int hand[], int size) {
    int temp;

    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (getCardValue(hand[i]) > getCardValue(hand[j])) {
                temp = hand[i];
                hand[i] = hand[j];
                hand[j] = temp;
            }
        }
    }
}

// analyze a hand of cards and determine its value
int analyzeHand(int hand[]) {
    int score = 0;

    // check for a flush (all same suit)
    if (hand[0] / 13 == hand[1] / 13 && hand[1] / 13 == hand[2] / 13 && hand[2] / 13 == hand[3] / 13 && hand[3] / 13 == hand[4] / 13) {
        score += 5000;
    }

    // check for a straight (five cards in a sequence)
    if (getCardValue(hand[0]) == getCardValue(hand[1]) - 1 && getCardValue(hand[1]) == getCardValue(hand[2]) - 1 && getCardValue(hand[2]) == getCardValue(hand[3]) - 1 && getCardValue(hand[3]) == getCardValue(hand[4]) - 1) {
        score += 1000;
    }

    // check for four of a kind (four cards of the same value)
    if (getCardValue(hand[0]) == getCardValue(hand[1]) && getCardValue(hand[1]) == getCardValue(hand[2]) && getCardValue(hand[2]) == getCardValue(hand[3])) {
        score += 500;
    } else if (getCardValue(hand[1]) == getCardValue(hand[2]) && getCardValue(hand[2]) == getCardValue(hand[3]) && getCardValue(hand[3]) == getCardValue(hand[4])) {
        score += 500;
    }

    // check for a full house (three of a kind and a pair)
    if (getCardValue(hand[0]) == getCardValue(hand[1]) && getCardValue(hand[1]) == getCardValue(hand[2]) && getCardValue(hand[3]) == getCardValue(hand[4])) {
        score += 250;
    } else if (getCardValue(hand[0]) == getCardValue(hand[1]) && getCardValue(hand[2]) == getCardValue(hand[3]) && getCardValue(hand[3]) == getCardValue(hand[4])) {
        score += 250;
    }

    // check for a three of a kind
    if (getCardValue(hand[0]) == getCardValue(hand[1]) && getCardValue(hand[1]) == getCardValue(hand[2])) {
        score += 100;
    } else if (getCardValue(hand[1]) == getCardValue(hand[2]) && getCardValue(hand[2]) == getCardValue(hand[3])) {
        score += 100;
    } else if (getCardValue(hand[2]) == getCardValue(hand[3]) && getCardValue(hand[3]) == getCardValue(hand[4])) {
        score += 100;
    }

    // check for two pairs
    if (getCardValue(hand[0]) == getCardValue(hand[1]) && getCardValue(hand[2]) == getCardValue(hand[3])) {
        score += 50;
    } else if (getCardValue(hand[0]) == getCardValue(hand[1]) && getCardValue(hand[3]) == getCardValue(hand[4])) {
        score += 50;
    } else if (getCardValue(hand[1]) == getCardValue(hand[2]) && getCardValue(hand[3]) == getCardValue(hand[4])) {
        score += 50;
    }

    return score;
}

// print a hand of cards
void printHand(int hand[], const char *suit[], const char *face[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%s of %s\n", face[getCardValue(hand[i])-1], suit[hand[i]/13]);
    }
}