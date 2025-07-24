//FormAI DATASET v1.0 Category: Poker Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 52
#define NUM_SUITS 4
#define NUM_RANKS 13
#define NUM_PLAYERS 2
#define MAX_HAND_SIZE 5
#define TRUE 1
#define FALSE 0

typedef struct {
    int rank;
    int suit;
} Card;

void shuffle(Card deck[NUM_CARDS]);
void printCard(Card card);
void printHand(Card hand[MAX_HAND_SIZE], int handSize);
int evaluateHand(Card hand[MAX_HAND_SIZE], int handSize);
int findHighestCard(Card hand[MAX_HAND_SIZE], int handSize);
int checkFlush(Card hand[MAX_HAND_SIZE], int handSize);
int checkStraight(Card hand[MAX_HAND_SIZE], int handSize);
int checkStraightFlush(Card hand[MAX_HAND_SIZE], int handSize);
int checkRoyalFlush(Card hand[MAX_HAND_SIZE], int handSize);

int main() {
    Card deck[NUM_CARDS];
    Card playerHands[NUM_PLAYERS][MAX_HAND_SIZE];
    int playerScores[NUM_PLAYERS] = {0};
    int turn = 0;

    // Initialize deck
    for (int i = 0; i < NUM_RANKS; i++) {
        for (int j = 0; j < NUM_SUITS; j++) {
            deck[i * NUM_SUITS + j].rank = i;
            deck[i * NUM_SUITS + j].suit = j;
        }
    }

    // Shuffle deck
    shuffle(deck);

    // Deal cards to players
    for (int i = 0; i < MAX_HAND_SIZE; i++) {
        for (int j = 0; j < NUM_PLAYERS; j++) {
            playerHands[j][i] = deck[i * NUM_PLAYERS + j];
        }
    }

    // Print each player's hand and evaluate their score
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("Player %d:\n", i+1);
        printHand(playerHands[i], MAX_HAND_SIZE);
        playerScores[i] = evaluateHand(playerHands[i], MAX_HAND_SIZE);
        printf("Hand score: %d\n\n", playerScores[i]);
    }

    // Determine winner
    int winner = 0;
    if (playerScores[1] > playerScores[0]) {
        winner = 1;
    } else if (playerScores[1] == playerScores[0]) {
        if (findHighestCard(playerHands[1], MAX_HAND_SIZE) > findHighestCard(playerHands[0], MAX_HAND_SIZE)) {
            winner = 1;
        }
    }

    printf("Player %d wins!", winner+1);

    return 0;
}

void shuffle(Card deck[NUM_CARDS]) {
    srand(time(NULL));
    for (int i = 0; i < NUM_CARDS; i++) {
        int j = rand() % NUM_CARDS;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void printCard(Card card) {
    char suits[NUM_SUITS][10] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    char ranks[NUM_RANKS][10] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    printf("%s of %s", ranks[card.rank], suits[card.suit]);
}

void printHand(Card hand[MAX_HAND_SIZE], int handSize) {
    for (int i = 0; i < handSize; i++) {
        printCard(hand[i]);
        printf("\n");
    }
}

int evaluateHand(Card hand[MAX_HAND_SIZE], int handSize) {
    if (checkRoyalFlush(hand, handSize)) {
        return 10;
    } else if (checkStraightFlush(hand, handSize)) {
        return 9;
    } else if (checkFlush(hand, handSize)) {
        return 6;
    } else if (checkStraight(hand, handSize)) {
        return 5;
    } else {
        return findHighestCard(hand, handSize);
    }
}

int findHighestCard(Card hand[MAX_HAND_SIZE], int handSize) {
    int highest = 0;
    for (int i = 0; i < handSize; i++) {
        if (hand[i].rank > hand[highest].rank) {
            highest = i;
        }
    }
    return hand[highest].rank;
}

int checkFlush(Card hand[MAX_HAND_SIZE], int handSize) {
    int numHearts = 0;
    int numDiamonds = 0;
    int numClubs = 0;
    int numSpades = 0;
    for (int i = 0; i < handSize; i++) {
        switch (hand[i].suit) {
            case 0:
                numHearts++;
                break;
            case 1:
                numDiamonds++;
                break;
            case 2:
                numClubs++;
                break;
            case 3:
                numSpades++;
                break;
            default:
                printf("Invalid suit!\n");
                exit(1);
        }
    }
    if (numHearts >= 5 || numDiamonds >= 5 || numClubs >= 5 || numSpades >= 5) {
        return TRUE;
    } else {
        return FALSE;
    }
}

int checkStraight(Card hand[MAX_HAND_SIZE], int handSize) {
    int numConsecutive = 0;
    int lastRank = hand[0].rank;
    for (int i = 1; i < handSize; i++) {
        if (hand[i].rank == lastRank + 1) {
            numConsecutive++;
            if (numConsecutive >= 4) {
                return TRUE;
            }
        } else {
            numConsecutive = 0;
        }
        lastRank = hand[i].rank;
    }
    return FALSE;
}

int checkStraightFlush(Card hand[MAX_HAND_SIZE], int handSize) {
    if (checkFlush(hand, handSize) && checkStraight(hand, handSize)) {
        return TRUE;
    } else {
        return FALSE;
    }
}

int checkRoyalFlush(Card hand[MAX_HAND_SIZE], int handSize) {
    if (checkStraightFlush(hand, handSize) && hand[0].rank == 0) {
        return TRUE;
    } else {
        return FALSE;
    }
}