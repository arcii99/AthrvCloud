//FormAI DATASET v1.0 Category: Poker Game ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print the poker hand
void printHand(int hand[]) {
    char ranks[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
    char suits[] = {'\u2660', '\u2663', '\u2665', '\u2666'};

    printf("Your hand: ");
    for (int i = 0; i < 5; i++) {
        int rank = hand[i] % 13;
        int suit = hand[i] / 13;
        printf("%c%c ", ranks[rank], suits[suit]);
    }
    printf("\n");
}

// Function to check if the hand is a flush
int isFlush(int hand[]) {
    int suit = hand[0] / 13;
    for (int i = 1; i < 5; i++) {
        if (hand[i] / 13 != suit) {
            return 0;
        }
    }
    return 1;
}

// Function to check if the hand is a straight
int isStraight(int hand[]) {
    int minRank = hand[0] % 13;
    for (int i = 1; i < 5; i++) {
        int rank = hand[i] % 13;
        if (rank < minRank) {
            minRank = rank;
        }
    }
    if (minRank == 0) {
        int sum = 0;
        for (int i = 0; i < 5; i++) {
            sum += hand[i] % 13;
        }
        if (sum == 10) {
            return 1;
        }
    } else {
        for (int i = 0; i < 5; i++) {
            int rank = hand[i] % 13;
            if (rank != minRank+i) {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}

// Function to check if the hand is a straight flush
int isStraightFlush(int hand[]) {
    if (isFlush(hand) && isStraight(hand)) {
        return 1;
    }
    return 0;
}

// Function to check if the hand is a royal flush
int isRoyalFlush(int hand[]) {
    if (isFlush(hand) && hand[0] % 13 == 0) {
        return 1;
    }
    return 0;
}

// Function to check if the hand is four of a kind
int isFourOfAKind(int hand[]) {
    int count[13] = {0};
    for (int i = 0; i < 5; i++) {
        int rank = hand[i] % 13;
        count[rank]++;
    }
    for (int i = 0; i < 13; i++) {
        if (count[i] == 4) {
            return 1;
        }
    }
    return 0;
}

// Function to check if the hand is a full house
int isFullHouse(int hand[]) {
    int count[13] = {0};
    for (int i = 0; i < 5; i++) {
        int rank = hand[i] % 13;
        count[rank]++;
    }
    int hasThreeOfAKind = 0;
    int hasPair = 0;
    for (int i = 0; i < 13; i++) {
        if (count[i] == 3) {
            hasThreeOfAKind = 1;
        } else if (count[i] == 2) {
            hasPair = 1;
        }
    }
    if (hasThreeOfAKind && hasPair) {
        return 1;
    }
    return 0;
}

// Function to check if the hand is three of a kind
int isThreeOfAKind(int hand[]) {
    int count[13] = {0};
    for (int i = 0; i < 5; i++) {
        int rank = hand[i] % 13;
        count[rank]++;
    }
    for (int i = 0; i < 13; i++) {
        if (count[i] == 3) {
            return 1;
        }
    }
    return 0;
}

// Function to check if the hand is two pair
int isTwoPair(int hand[]) {
    int count[13] = {0};
    for (int i = 0; i < 5; i++) {
        int rank = hand[i] % 13;
        count[rank]++;
    }
    int numPairs = 0;
    for (int i = 0; i < 13; i++) {
        if (count[i] == 2) {
            numPairs++;
        }
    }
    if (numPairs == 2) {
        return 1;
    }
    return 0;
}

// Function to check if the hand is a pair
int isPair(int hand[]) {
    int count[13] = {0};
    for (int i = 0; i < 5; i++) {
        int rank = hand[i] % 13;
        count[rank]++;
    }
    for (int i = 0; i < 13; i++) {
        if (count[i] == 2) {
            return 1;
        }
    }
    return 0;
}

// Function to evaluate the hand
int evaluateHand(int hand[]) {
    if (isRoyalFlush(hand)) {
        return 10;
    } else if (isStraightFlush(hand)) {
        return 9;
    } else if (isFourOfAKind(hand)) {
        return 8;
    } else if (isFullHouse(hand)) {
        return 7;
    } else if (isFlush(hand)) {
        return 6;
    } else if (isStraight(hand)) {
        return 5;
    } else if (isThreeOfAKind(hand)) {
        return 4;
    } else if (isTwoPair(hand)) {
        return 3;
    } else if (isPair(hand)) {
        return 2;
    }
    return 1;
}

int main(void) {

    int deck[52], hand[5];
    char ranks[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
    char suits[] = {'\u2660', '\u2663', '\u2665', '\u2666'};
    int numHands = 0, numWins = 0;

    // Seed random number generator
    srand(time(NULL));

    // Initialize the deck
    for (int i = 0; i < 52; i++) {
        deck[i] = i;
    }

    // Shuffle the deck 1000 times
    for (int i = 0; i < 1000; i++) {
        int index1 = rand() % 52;
        int index2 = rand() % 52;
        int temp = deck[index1];
        deck[index1] = deck[index2];
        deck[index2] = temp;
    }

    // Print the shuffled deck
    printf("Shuffled deck:\n");
    for (int i = 0; i < 52; i++) {
        int rank = deck[i] % 13;
        int suit = deck[i] / 13;
        printf("%c%c ", ranks[rank], suits[suit]);
    }
    printf("\n\n");

    // Deal hands and evaluate
    for (int i = 0; i < 10000; i++) {
        // Deal 5 cards
        for (int j = 0; j < 5; j++) {
            hand[j] = deck[numHands*5 + j];
        }
        numHands++;

        // Evaluate the hand
        int handValue = evaluateHand(hand);
        if (handValue >= 5) {
            numWins++;
        }

        // Print the hand and its value
        printf("Hand %d: ", numHands);
        for (int j = 0; j < 5; j++) {
            int rank = hand[j] % 13;
            int suit = hand[j] / 13;
            printf("%c%c ", ranks[rank], suits[suit]);
        }
        printf("Value: %d\n", handValue);

        if (numHands == 52/5) {
            break;
        }
    }

    // Print the results
    printf("\nResults:\n");
    printf("Hands evaluated: %d\n", numHands);
    printf("Wins: %d\n", numWins);
    printf("Losses: %d\n", numHands - numWins);

    return 0;
}