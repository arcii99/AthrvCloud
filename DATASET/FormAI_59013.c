//FormAI DATASET v1.0 Category: Poker Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PLAYERS 4
#define NUM_CARDS 52

typedef struct {
    int value; // 2-10, J-11, Q-12, K-13, A-14
    char suit; // C-Clubs, D-Diamonds, H-Hearts, S-Spades
} Card;

void initializeDeck(Card *deck) {
    char suits[4] = {'C', 'D', 'H', 'S'};
    int i, j, count = 0;

    for (i = 0; i < 4; i++) {
        for (j = 2; j <= 14; j++) {
            deck[count].suit = suits[i];
            deck[count].value = j;
            count++;
        }
    }
}

void shuffleDeck(Card *deck) {
    int i, randIndex;
    Card tempCard;

    srand(time(0));

    for (i = 0; i < NUM_CARDS; i++) {
        randIndex = rand() % NUM_CARDS;
        tempCard = deck[i];
        deck[i] = deck[randIndex];
        deck[randIndex] = tempCard;
    }
}

void dealCards(Card *deck, Card (*hands)[5]) {
    int i, j, k = 0;

    for (i = 0; i < NUM_PLAYERS; i++) {
        for (j = 0; j < 5; j++) {
            hands[i][j] = deck[k];
            k++;
        }
    }
}

void printHands(Card (*hands)[5]) {
    int i, j;

    for (i = 0; i < NUM_PLAYERS; i++) {
        printf("Player %d's Hand:\n", i + 1);
        for (j = 0; j < 5; j++) {
            printf("%d%c ", hands[i][j].value, hands[i][j].suit);
        }
        printf("\n");
    }
}

void evaluateHands(Card (*hands)[5]) {
    int i, j, k, l, highCard, pairCount, threeCount, straightCount, flushCount, fullHouseCount, fourCount;
    char suit;
    int values[5];
    int pairFlag, threeFlag, straightFlag, flushFlag, fullHouseFlag, fourFlag;

    for (i = 0; i < NUM_PLAYERS; i++) {
        pairCount = 0;
        threeCount = 0;
        straightCount = 0;
        flushCount = 0;
        fullHouseCount = 0;
        fourCount = 0;
        pairFlag = 0;
        threeFlag = 0;
        straightFlag = 0;
        flushFlag = 0;
        fullHouseFlag = 0;
        fourFlag = 0;

        // Check for flush
        suit = hands[i][0].suit;
        for (j = 1; j < 5; j++) {
            if (hands[i][j].suit != suit) {
                flushFlag = 0;
                break;
            } else {
                flushFlag = 1;
            }
        }
        if (flushFlag == 1) {
            printf("Player %d has a flush.\n", i + 1);
            flushCount = 1;
        }

        // Sort card values in ascending order
        for (j = 0; j < 5; j++) {
            values[j] = hands[i][j].value;
        }
        for (j = 0; j < 5; j++) {
            for (k = j + 1; k < 5; k++) {
                if (values[k] < values[j]) {
                    int temp = values[k];
                    values[k] = values[j];
                    values[j] = temp;
                }
            }
        }

        // Check for straight
        for (j = 0; j < 4; j++) {
            if ((values[j] + 1) == values[j + 1]) {
                straightCount++;
                if (straightCount == 4) {
                    printf("Player %d has a straight.\n", i + 1);
                    straightFlag = 1;
                    break;
                }
            } else {
                straightCount = 0;
            }
        }

        // Check for pairs, three of a kind, and four of a kind
        for (j = 0; j < 4; j++) {
            if (values[j] == values[j + 1]) {
                pairCount++;
                if (pairCount == 1) {
                    highCard = values[j + 1];
                }
                else if (pairCount == 2) {
                    printf("Player %d has two pairs.\n", i + 1);
                    pairFlag = 1;
                    break;
                }
            } else {
                pairCount = 0;
            }
        }
        for (j = 0; j < 3; j++) {
            if (values[j] == values[j + 1] && values[j + 1] == values[j + 2]) {
                printf("Player %d has three of a kind.\n", i + 1);
                threeFlag = 1;
                break;
            }
        }
        for (j = 0; j < 2; j++) {
            if (values[j] == values[j + 1] && values[j + 1] == values[j + 2] && values[j + 2] == values[j + 3]) {
                printf("Player %d has four of a kind.\n", i + 1);
                fourFlag = 1;
                break;
            }
        }

        // Check for full house
        if (pairFlag == 1 && threeFlag == 1) {
            printf("Player %d has a full house.\n", i + 1);
            fullHouseFlag = 1;
        }

        // Check for high card
        if (flushCount == 0 && straightFlag == 0 && pairFlag == 0 && threeFlag == 0 && fullHouseFlag == 0 && fourFlag == 0) {
            printf("Player %d has a high card of %d.\n", i + 1, values[4]);
        }
        printf("\n");
    }
}

int main() {
    Card deck[NUM_CARDS];
    Card hands[NUM_PLAYERS][5];

    initializeDeck(deck);
    shuffleDeck(deck);
    dealCards(deck, hands);
    printHands(hands);
    evaluateHands(hands);

    return 0;
}