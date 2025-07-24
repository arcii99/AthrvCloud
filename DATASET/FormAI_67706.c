//FormAI DATASET v1.0 Category: Poker Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
* This program simulates a game of poker between two players, player and computer.
* It uses a standard 52-card deck and follows traditional poker rules.
*/

// Define global constants
#define DECK_SIZE 52
#define HAND_SIZE 5

// Define global variables
int numPlayers;
int numRounds;

// Define functions
void initializeDeck(int deck[]);
void shuffleDeck(int deck[]);
void printDeck(int deck[]);
int dealCard(int deck[], int* cardIndex);
void printHand(int hand[]);
int countPairs(int hand[]);
int countThreeOfAKind(int hand[]);
int countFourOfAKind(int hand[]);
int countFullHouse(int hand[]);
int countFlush(int hand[]);
int countStraight(int hand[]);
int countStraightFlush(int hand[]);
int countRoyalFlush(int hand[]);

int main() {
    // Initialize random seed
    srand(time(NULL));

    // Initialize deck of cards
    int deck[DECK_SIZE];
    initializeDeck(deck);
    shuffleDeck(deck);

    // Ask user for number of players and number of rounds
    printf("Welcome to Poker!\n\n");
    printf("How many players would you like to play against? ");
    scanf("%d", &numPlayers);
    printf("How many rounds would you like to play? ");
    scanf("%d", &numRounds);
    printf("\n");

    // Start game
    int playerScore = 0;
    int computerScore = 0;
    for (int round = 1; round <= numRounds; round++) {
        printf("Round %d:\n", round);

        // Deal cards to each player
        int playerHand[HAND_SIZE];
        int computerHand[HAND_SIZE];
        int cardIndex = 0;
        for (int i = 0; i < HAND_SIZE; i++) {
            playerHand[i] = dealCard(deck, &cardIndex);
            computerHand[i] = dealCard(deck, &cardIndex);
        }

        // Print hands
        printf("Your hand: ");
        printHand(playerHand);
        printf("Computer's hand: ");
        printHand(computerHand);

        // Evaluate hands and determine winner
        int playerRank = countPairs(playerHand);
        int computerRank = countPairs(computerHand);
        if (playerRank > computerRank) {
            printf("You win!\n\n");
            playerScore++;
        }
        else if (computerRank > playerRank) {
            printf("Computer wins!\n\n");
            computerScore++;
        }
        else {
            printf("It's a tie!\n\n");
        }
    }

    // Print final scores
    printf("Final score:\n");
    printf("You: %d\n", playerScore);
    printf("Computer: %d\n", computerScore);

    return 0;
}

// Initialize deck with values 1-52
void initializeDeck(int deck[]) {
    for (int i = 0; i < DECK_SIZE; i++) {
        deck[i] = i + 1;
    }
}

// Shuffle deck by swapping each card with a random card in the deck
void shuffleDeck(int deck[]) {
    for (int i = 0; i < DECK_SIZE; i++) {
        int randomIndex = rand() % DECK_SIZE;
        int temp = deck[i];
        deck[i] = deck[randomIndex];
        deck[randomIndex] = temp;
    }
}

// Print deck (for testing purposes)
void printDeck(int deck[]) {
    for (int i = 0; i < DECK_SIZE; i++) {
        printf("%d ", deck[i]);
        if ((i + 1) % 13 == 0) {
            printf("\n");
        }
    }
}

// Deal a card from the deck and return its value (removes card from deck)
int dealCard(int deck[], int* cardIndex) {
    int card = deck[*cardIndex];
    (*cardIndex)++;
    return card;
}

// Print hand (cards) of specified player
void printHand(int hand[]) {
    for (int i = 0; i < HAND_SIZE; i++) {
        int card = hand[i];
        int suit = (card - 1) / 13;
        int value = (card - 1) % 13;
        char* suitStr;
        switch (suit) {
        case 0:
            suitStr = "Spades";
            break;
        case 1:
            suitStr = "Hearts";
            break;
        case 2:
            suitStr = "Diamonds";
            break;
        case 3:
            suitStr = "Clubs";
            break;
        }
        char* valueStr;
        switch (value) {
        case 0:
            valueStr = "Ace";
            break;
        case 10:
            valueStr = "Jack";
            break;
        case 11:
            valueStr = "Queen";
            break;
        case 12:
            valueStr = "King";
            break;
        default:
            valueStr = (char*)malloc(sizeof(char) * 2);
            sprintf(valueStr, "%d", value + 1);
        }
        printf("%s of %s, ", valueStr, suitStr);
        free(valueStr);
    }
    printf("\n");
}

// Count number of pairs in hand
int countPairs(int hand[]) {
    int numPairs = 0;
    for (int i = 0; i < HAND_SIZE - 1; i++) {
        for (int j = i + 1; j < HAND_SIZE; j++) {
            int value1 = (hand[i] - 1) % 13;
            int value2 = (hand[j] - 1) % 13;
            if (value1 == value2) {
                numPairs++;
            }
        }
    }
    return numPairs;
}

// Count number of three-of-a-kind in hand
int countThreeOfAKind(int hand[]) {
    int numThreeOfAKind = 0;
    for (int i = 0; i < HAND_SIZE - 2; i++) {
        for (int j = i + 1; j < HAND_SIZE - 1; j++) {
            for (int k = j + 1; k < HAND_SIZE; k++) {
                int value1 = (hand[i] - 1) % 13;
                int value2 = (hand[j] - 1) % 13;
                int value3 = (hand[k] - 1) % 13;
                if (value1 == value2 && value2 == value3) {
                    numThreeOfAKind++;
                }
            }
        }
    }
    return numThreeOfAKind;
}

// Count number of four-of-a-kind in hand
int countFourOfAKind(int hand[]) {
    int numFourOfAKind = 0;
    for (int i = 0; i < HAND_SIZE - 3; i++) {
        for (int j = i + 1; j < HAND_SIZE - 2; j++) {
            for (int k = j + 1; k < HAND_SIZE - 1; k++) {
                for (int l = k + 1; l < HAND_SIZE; l++) {
                    int value1 = (hand[i] - 1) % 13;
                    int value2 = (hand[j] - 1) % 13;
                    int value3 = (hand[k] - 1) % 13;
                    int value4 = (hand[l] - 1) % 13;
                    if (value1 == value2 && value2 == value3 && value3 == value4) {
                        numFourOfAKind++;
                    }
                }
            }
        }
    }
    return numFourOfAKind;
}

// Count number of full houses in hand
int countFullHouse(int hand[]) {
    int numFullHouse = 0;
    for (int i = 0; i < HAND_SIZE - 2; i++) {
        for (int j = i + 1; j < HAND_SIZE - 1; j++) {
            for (int k = j + 1; k < HAND_SIZE; k++) {
                int value1 = (hand[i] - 1) % 13;
                int value2 = (hand[j] - 1) % 13;
                int value3 = (hand[k] - 1) % 13;
                if (value1 == value2 && value2 != value3) {
                    int count = countPairs(hand);
                    if (count == 3) {
                        numFullHouse++;
                    }
                }
                else if (value1 != value2 && value2 == value3) {
                    int count = countPairs(hand);
                    if (count == 3) {
                        numFullHouse++;
                    }
                }
            }
        }
    }
    return numFullHouse;
}

// Count number of flushes in hand
int countFlush(int hand[]) {
    int numFlush = 0;
    int suit = (hand[0] - 1) / 13;
    for (int i = 1; i < HAND_SIZE; i++) {
        int suit2 = (hand[i] - 1) / 13;
        if (suit != suit2) {
            return 0;
        }
    }
    return 1;
}

// Count number of straights in hand
int countStraight(int hand[]) {
    int numStraight = 0;
    int values[HAND_SIZE];
    for (int i = 0; i < HAND_SIZE; i++) {
        values[i] = (hand[i] - 1) % 13;
    }
    for (int i = 0; i < HAND_SIZE - 1; i++) {
        int value1 = values[i];
        int value2 = values[i + 1];
        if (value1 == 0 && value2 == 9) {
            numStraight++;
        }
        else if (value1 + 1 == value2) {
            numStraight++;
        }
        else {
            return 0;
        }
    }
    return 1;
}

// Count number of straight flushes in hand
int countStraightFlush(int hand[]) {
    int numStraightFlush = 0;
    int flush = countFlush(hand);
    int straight = countStraight(hand);
    if (flush && straight) {
        numStraightFlush++;
    }
    return numStraightFlush;
}

// Count number of Royal Flushes in hand
int countRoyalFlush(int hand[]) {
    int numRoyalFlush = 0;
    int straightFlush = countStraightFlush(hand);
    int value1 = (hand[0] - 1) % 13;
    int value2 = (hand[1] - 1) % 13;
    int value3 = (hand[2] - 1) % 13;
    int value4 = (hand[3] - 1) % 13;
    int value5 = (hand[4] - 1) % 13;
    if (straightFlush && value1 == 0 && value2 == 9 && value3 == 10 && value4 == 11 && value5 == 12) {
        numRoyalFlush++;
    }
    return numRoyalFlush;
}