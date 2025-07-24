//FormAI DATASET v1.0 Category: Poker Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 52
#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_PLAYERS 2

void shuffleDeck(int deck[][NUM_RANKS]);
void dealCards(int deck[][NUM_RANKS], int numCards, int players, int playerCards[][numCards]);
void printCards(int playerCards[][NUM_CARDS], int numCards, int playerNum);
void evaluateHand(int playerCards[][NUM_CARDS], int numCards, int playerNum);

int main(void) {
    int deck[NUM_SUITS][NUM_RANKS] = {{0}};
    int playerCards[NUM_PLAYERS][NUM_CARDS] = {{0}};

    srand(time(NULL)); // seed the random number generator

    shuffleDeck(deck);
    dealCards(deck, NUM_CARDS, NUM_PLAYERS, playerCards);

    for(int i = 0; i < NUM_PLAYERS; i++) {
        printf("Player %d:\n", i+1);
        printCards(playerCards, NUM_CARDS, i);
        evaluateHand(playerCards, NUM_CARDS, i);
        printf("\n");
    }

    return 0;
}

void shuffleDeck(int deck[][NUM_RANKS]) {
    int card = 1;
    for(int i = 0; i < NUM_SUITS; i++) {
        for(int j = 0; j < NUM_RANKS; j++) {
            deck[i][j] = card;
            card++;
        }
    }

    for(int i = 0; i < NUM_CARDS; i++) {
        int row1 = rand() % NUM_SUITS;
        int col1 = rand() % NUM_RANKS;
        int row2 = rand() % NUM_SUITS;
        int col2 = rand() % NUM_RANKS;

        int temp = deck[row1][col1];
        deck[row1][col1] = deck[row2][col2];
        deck[row2][col2] = temp;
    }
}

void dealCards(int deck[][NUM_RANKS], int numCards, int players, int playerCards[][numCards]) {
    int card = 0;
    for(int i = 0; i < numCards; i++) {
        for(int j = 0; j < players; j++) {
            playerCards[j][i] = deck[j][card];
        }
        card++;
    }
}

void printCards(int playerCards[][NUM_CARDS], int numCards, int playerNum) {
    for(int i = 0; i < numCards; i++) {
        int cardNum = playerCards[playerNum][i];
        int suit = (cardNum-1) / NUM_RANKS;
        int rank = (cardNum-1) % NUM_RANKS;

        switch(rank) {
            case 0:
                printf("Ace");
                break;
            case 10:
                printf("Jack");
                break;
            case 11:
                printf("Queen");
                break;
            case 12:
                printf("King");
                break;
            default:
                printf("%d", rank+1);
                break;
        }

        switch(suit) {
            case 0:
                printf(" of Clubs\n");
                break;
            case 1:
                printf(" of Diamonds\n");
                break;
            case 2:
                printf(" of Hearts\n");
                break;
            case 3:
                printf(" of Spades\n");
                break;
        }
    }
}

void evaluateHand(int playerCards[][NUM_CARDS], int numCards, int playerNum) {
    int numPairs = 0;
    int numThreeOfAKind = 0;
    int numFourOfAKind = 0;
    int numFlush = 0;
    int numStraight = 0;

    int ranks[NUM_RANKS] = {0};
    int suits[NUM_SUITS] = {0};
    int maxRank = 0;
    int minRank = NUM_RANKS;

    for(int i = 0; i < numCards; i++) {
        int cardNum = playerCards[playerNum][i];
        int rank = (cardNum-1) % NUM_RANKS;
        int suit = (cardNum-1) / NUM_RANKS;

        ranks[rank]++;
        suits[suit]++;

        if(rank > maxRank) {
            maxRank = rank;
        }

        if(rank < minRank) {
            minRank = rank;
        }
    }

    // check for pairs, three of a kind, and four of a kind
    for(int i = 0; i < NUM_RANKS; i++) {
        if(ranks[i] == 2) {
            numPairs++;
        }
        else if(ranks[i] == 3) {
            numThreeOfAKind++;
        }
        else if(ranks[i] == 4) {
            numFourOfAKind++;
        }
    }

    // check for flush
    for(int i = 0; i < NUM_SUITS; i++) {
        if(suits[i] == NUM_RANKS) {
            numFlush++;
        }
    }

    // check for straight
    if(maxRank - minRank == NUM_RANKS-1) {
        numStraight++;
    }

    // print results
    if(numFlush > 0 && numStraight > 0) {
        printf("Straight Flush\n");
    }
    else if(numFourOfAKind > 0) {
        printf("Four of a Kind\n");
    }
    else if(numThreeOfAKind > 0 && numPairs > 0) {
        printf("Full House\n");
    }
    else if(numFlush > 0) {
        printf("Flush\n");
    }
    else if(numStraight > 0) {
        printf("Straight\n");
    }
    else if(numThreeOfAKind > 0) {
        printf("Three of a Kind\n");
    }
    else if(numPairs == 2) {
        printf("Two Pairs\n");
    }
    else if(numPairs == 1) {
        printf("Pair\n");
    }
    else {
        printf("High Card\n");
    }
}