//FormAI DATASET v1.0 Category: Poker Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DECK_SIZE 52
#define HAND_SIZE 5

typedef struct {
    int value;
    char suit;
} Card;

void shuffleDeck(Card* deck) {
    srand(time(NULL));

    for(int i = 0; i < DECK_SIZE; i++) {
        int j = rand() % DECK_SIZE;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void dealHand(Card* deck, Card* hand) {
    for(int i = 0; i < HAND_SIZE; i++) {
        hand[i] = deck[i];
    }
}

void printCard(Card card) {
    char value;
    switch(card.value) {
        case 1:
            value = 'A';
            break;
        case 10: 
            printf("10");
            return;
        case 11:
            value = 'J';
            break;
        case 12:
            value = 'Q';
            break;
        case 13:
            value = 'K';
            break;
        default:
            value = card.value + '0';
            break;
    }

    printf("%c%c ", value, card.suit);
}

void printHand(Card* hand) {
    for(int i = 0; i < HAND_SIZE; i++) {
        printCard(hand[i]);
    }
}

int countPairs(Card* hand) {
    int pairs = 0;

    for(int i = 0; i < HAND_SIZE - 1; i++) {
        for(int j = i + 1; j < HAND_SIZE; j++) {
            if(hand[i].value == hand[j].value) {
                pairs++;
            }
        }
    }

    return pairs;
}

int countSuit(Card* hand, char suit) {
    int count = 0;

    for(int i = 0; i < HAND_SIZE; i++) {
        if(hand[i].suit == suit) {
            count++;
        }
    }

    return count;
}

int countSequence(Card* hand) {
    int count = 1;
    int maxSequence = 1;

    for(int i = 0; i < HAND_SIZE - 1; i++) {
        if(hand[i].value == hand[i+1].value - 1) {
            count++;
            if(count > maxSequence) {
                maxSequence = count;
            }
        }
        else {
            count = 1;
        }
    }

    return maxSequence;
}

int isFlush(Card* hand) {
    char firstSuit = hand[0].suit;
    for(int i = 1; i < HAND_SIZE; i++) {
        if(hand[i].suit != firstSuit) {
            return 0;
        }
    }

    return 1;
}

int isStraight(Card* hand) {
    return countSequence(hand) == HAND_SIZE;
}

int isRoyalFlush(Card* hand) {
    return isFlush(hand) && isStraight(hand) && hand[0].value == 1 && hand[4].value == 13;
}

int isStraightFlush(Card* hand) {
    return isFlush(hand) && isStraight(hand);
}

int isFourOfAKind(Card* hand) {
    for(int i = 0; i < HAND_SIZE - 3; i++) {
        if(hand[i].value == hand[i+1].value && hand[i+1].value == hand[i+2].value && hand[i+2].value == hand[i+3].value) {
            return 1;
        }
    }

    return 0;
}

int isThreeOfAKind(Card* hand) {
    for(int i = 0; i < HAND_SIZE - 2; i++) {
        if(hand[i].value == hand[i+1].value && hand[i+1].value == hand[i+2].value) {
            return 1;
        }
    }

    return 0;
}

int isFullHouse(Card* hand) {
    return isThreeOfAKind(hand) && countPairs(hand) == 2;
}

int isTwoPair(Card* hand) {
    return countPairs(hand) == 2;
}

int isOnePair(Card* hand) {
    return countPairs(hand) == 1;
}

int evaluateHand(Card* hand) {
    if(isRoyalFlush(hand)) {
        return 10;
    }
    else if(isStraightFlush(hand)) {
        return 9;
    }
    else if(isFourOfAKind(hand)) {
        return 8;
    }
    else if(isFullHouse(hand)) {
        return 7;
    }
    else if(isFlush(hand)) {
        return 6;
    }
    else if(isStraight(hand)) {
        return 5;
    }
    else if(isThreeOfAKind(hand)) {
        return 4;
    }
    else if(isTwoPair(hand)) {
        return 3;
    }
    else if(isOnePair(hand)) {
        return 2;
    }
    else {
        return 1;
    }
}

int main() {
    Card deck[DECK_SIZE] = {
        {1, 'D'},
        {2, 'D'},
        {3, 'D'},
        {4, 'D'},
        {5, 'D'},
        {6, 'D'},
        {7, 'D'},
        {8, 'D'},
        {9, 'D'},
        {10, 'D'},
        {11, 'D'},
        {12, 'D'},
        {13, 'D'},

        {1, 'H'},
        {2, 'H'},
        {3, 'H'},
        {4, 'H'},
        {5, 'H'},
        {6, 'H'},
        {7, 'H'},
        {8, 'H'},
        {9, 'H'},
        {10, 'H'},
        {11, 'H'},
        {12, 'H'},
        {13, 'H'},

        {1, 'S'},
        {2, 'S'},
        {3, 'S'},
        {4, 'S'},
        {5, 'S'},
        {6, 'S'},
        {7, 'S'},
        {8, 'S'},
        {9, 'S'},
        {10, 'S'},
        {11, 'S'},
        {12, 'S'},
        {13, 'S'},

        {1, 'C'},
        {2, 'C'},
        {3, 'C'},
        {4, 'C'},
        {5, 'C'},
        {6, 'C'},
        {7, 'C'},
        {8, 'C'},
        {9, 'C'},
        {10, 'C'},
        {11, 'C'},
        {12, 'C'},
        {13, 'C'}
    };

    shuffleDeck(deck);

    Card playerHand[HAND_SIZE];
    dealHand(deck, playerHand);

    printf("Your hand:");
    printHand(playerHand);

    printf("\nYour hand value: %d", evaluateHand(playerHand));

    return 0;
}