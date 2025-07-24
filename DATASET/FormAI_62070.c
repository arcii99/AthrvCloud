//FormAI DATASET v1.0 Category: Poker Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to shuffle the deck
void shuffleDeck(int deck[]) {
    srand(time(NULL));
    for (int i = 0; i < 52; i++) {
        int randIndex = rand() % 52;
        int temp = deck[i];
        deck[i] = deck[randIndex];
        deck[randIndex] = temp;
    }
}

// Function to deal cards to players
void dealCards(int deck[], int playerCards[][2], int numPlayers) {
    int cardIndex = 0;
    for (int i = 0; i < numPlayers; i++) {
        for (int j = 0; j < 2; j++) {
            playerCards[i][j] = deck[cardIndex++];
        }
    }
}

// Function to print cards in human-readable format
void printCards(int cards[]) {
    for (int i = 0; i < 5; i++) {
        int value = cards[i] % 13;
        int suit = cards[i] / 13;
        char valueChar;
        switch (value) {
            case 0: valueChar = 'A'; break;
            case 10: valueChar = 'T'; break;
            case 11: valueChar = 'J'; break;
            case 12: valueChar = 'Q'; break;
            case 9: valueChar = 'K'; break;
            default: valueChar = '0' + (value + 1); break;
        }
        char suitChar;
        switch (suit) {
            case 0: suitChar = 'C'; break;
            case 1: suitChar = 'D'; break;
            case 2: suitChar = 'H'; break;
            case 3: suitChar = 'S'; break;
        }
        printf("%c%c ", valueChar, suitChar);
    }
}

// Function to evaluate the strength of a poker hand
int evaluateHand(int cards[]) {
    // Determine if hand is a straight, flush, or straight flush
    int isStraight = 0;
    int isFlush = 0;
    int isStraightFlush = 0;
    int prevValue = -1;
    int prevSuit = -1;
    for (int i = 0; i < 5; i++) {
        int value = cards[i] % 13;
        int suit = cards[i] / 13;
        if (prevValue != -1 && prevValue != value - 1) {
            isStraight = 0;
        }
        if (prevSuit != -1 && prevSuit != suit) {
            isFlush = 0;
        }
        prevValue = value;
        prevSuit = suit;
    }
    if (isStraight && isFlush) {
        isStraightFlush = 1;
    }
    
    // Determine if hand is a pair, two pair, three of a kind, full house, or four of a kind
    int numPairs = 0;
    int numThrees = 0;
    int numFours = 0;
    int values[13] = {0};
    for (int i = 0; i < 5; i++) {
        int value = cards[i] % 13;
        values[value]++;
    }
    for (int i = 0; i < 13; i++) {
        if (values[i] == 2) {
            numPairs++;
        }
        else if (values[i] == 3) {
            numThrees++;
        }
        else if (values[i] == 4) {
            numFours++;
        }
    }
    int handStrength = 0;
    if (isStraightFlush) {
        handStrength = 8;
    }
    else if (numFours > 0) {
        handStrength = 7;
    }
    else if (numThrees > 0 && numPairs > 0) {
        handStrength = 6;
    }
    else if (isFlush) {
        handStrength = 5;
    }
    else if (isStraight) {
        handStrength = 4;
    }
    else if (numThrees > 0) {
        handStrength = 3;
    }
    else if (numPairs >= 2) {
        handStrength = 2;
    }
    else if (numPairs == 1) {
        handStrength = 1;
    }
    
    return handStrength;
}

int main() {
    int deck[52]; // Deck of cards represented by integers 0-51
    for (int i = 0; i < 52; i++) {
        deck[i] = i;
    }
    shuffleDeck(deck);
    
    int numPlayers;
    printf("Enter the number of players (2-6): ");
    scanf("%d", &numPlayers);
    while (numPlayers < 2 || numPlayers > 6) {
        printf("Invalid number of players. Enter a number between 2 and 6: ");
        scanf("%d", &numPlayers);
    }
    
    int playerCards[numPlayers][2]; // Array to hold each player's two cards
    dealCards(deck, playerCards, numPlayers);
    
    printf("\nPlayer cards:\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("Player %d: ", i+1);
        printCards(playerCards[i]);
        printf("\n");
    }
    
    int communityCards[5]; // Array to hold the 5 community cards
    for (int i = 0; i < 5; i++) {
        communityCards[i] = deck[numPlayers*2+i];
    }
    
    printf("\nCommunity cards: ");
    printCards(communityCards);
    printf("\n");
    
    int maxScore = 0;
    int winners[numPlayers];
    for (int i = 0; i < numPlayers; i++) {
        int hand[5];
        for (int j = 0; j < 2; j++) {
            hand[j] = playerCards[i][j];
        }
        for (int j = 0; j < 5; j++) {
            hand[j+2] = communityCards[j];
        }
        int score = evaluateHand(hand);
        if (score > maxScore) {
            maxScore = score;
            winners[0] = i;
            for (int k = 1; k < numPlayers; k++) {
                winners[k] = -1;
            }
        }
        else if (score == maxScore) {
            int numWinners = 0;
            for (int k = 0; k < numPlayers; k++) {
                if (winners[k] != -1) {
                    numWinners++;
                }
            }
            winners[numWinners] = i;
        }
    }
    
    printf("\nWinning hand: ");
    switch (maxScore) {
        case 0: printf("High card\n"); break;
        case 1: printf("Pair\n"); break;
        case 2: printf("Two pair\n"); break;
        case 3: printf("Three of a kind\n"); break;
        case 4: printf("Straight\n"); break;
        case 5: printf("Flush\n"); break;
        case 6: printf("Full house\n"); break;
        case 7: printf("Four of a kind\n"); break;
        case 8: printf("Straight flush\n"); break;
    }
    printf("Winners: ");
    for (int i = 0; i < numPlayers; i++) {
        if (winners[i] != -1) {
            printf("%d ", winners[i]+1);
        }
    }
    printf("\n");
    
    return 0;
}