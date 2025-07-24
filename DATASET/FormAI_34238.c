//FormAI DATASET v1.0 Category: Poker Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define constants for the Poker game
#define MAX_CARDS 52
#define HAND_SIZE 5

// enum for card suits
typedef enum suit {
    CLUBS = 0,
    DIAMONDS = 1,
    HEARTS = 2,
    SPADES = 3
} Suit;

// struct for card value
typedef struct value {
    int rank;
    char name[6];
} Value;

// struct for card
typedef struct card {
    Suit suit;
    Value value;
} Card;

// function to create a deck of cards
void createDeck(Card deck[MAX_CARDS]) {
    int count = 0;
    for (int i = 0; i < 4; i++) { // loop through each suit
        for (int j = 2; j <= 14; j++) { // loop through each rank
            deck[count].suit = i;
            deck[count].value.rank = j;
            switch (j) {
                case 2:
                    sprintf(deck[count].value.name, "2");
                    break;
                case 3:
                    sprintf(deck[count].value.name, "3");
                    break;
                case 4:
                    sprintf(deck[count].value.name, "4");
                    break;
                case 5:
                    sprintf(deck[count].value.name, "5");
                    break;
                case 6:
                    sprintf(deck[count].value.name, "6");
                    break;
                case 7:
                    sprintf(deck[count].value.name, "7");
                    break;
                case 8:
                    sprintf(deck[count].value.name, "8");
                    break;
                case 9:
                    sprintf(deck[count].value.name, "9");
                    break;
                case 10:
                    sprintf(deck[count].value.name, "10");
                    break;
                case 11:
                    sprintf(deck[count].value.name, "J");
                    break;
                case 12:
                    sprintf(deck[count].value.name, "Q");
                    break;
                case 13:
                    sprintf(deck[count].value.name, "K");
                    break;
                case 14:
                    sprintf(deck[count].value.name, "A");
                    break;
                default:
                    break;
            }
            count++;
        }
    }
}

// function to shuffle a deck of cards
void shuffleDeck(Card deck[MAX_CARDS]) {
    srand(time(NULL)); // seed the random number generator
    for (int i = 0; i < MAX_CARDS; i++) {
        int j = rand() % MAX_CARDS;
        // swap cards at position i and j
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// function to print a card
void printCard(Card card) {
    switch (card.suit) {
        case CLUBS:
            printf("C");
            break;
        case DIAMONDS:
            printf("D");
            break;
        case HEARTS:
            printf("H");
            break;
        case SPADES:
            printf("S");
            break;
        default:
            break;
    }
    printf("%s ", card.value.name);
}

// function to print a hand of cards
void printHand(Card hand[HAND_SIZE]) {
    for (int i = 0; i < HAND_SIZE; i++) {
        printCard(hand[i]);
    }
    printf("\n");
}

// function to evaluate the strength of a hand
int evaluateHand(Card hand[HAND_SIZE]) {
    int straight, flush, hasAce, hasPair, hasTwoPairs, hasThreeOfAKind, hasFourOfAKind, hasFullHouse;
    straight = flush = hasAce = hasPair = hasTwoPairs = hasThreeOfAKind = hasFourOfAKind = hasFullHouse = 0;
    // check for flush
    for (int i = 1; i < HAND_SIZE; i++) {
        if (hand[i].suit != hand[0].suit) {
            flush = 0;
            break;
        }
        flush = 1;
    }
    // check for straight
    int rankSum = 0;
    for (int i = 0; i < HAND_SIZE; i++) {
        rankSum += hand[i].value.rank;
    }
    if (rankSum == 28) { // special case for A-5 straight
        straight = 1;
    } else if (hand[4].value.rank == hand[3].value.rank + 1 &&
        hand[3].value.rank == hand[2].value.rank + 1 &&
        hand[2].value.rank == hand[1].value.rank + 1 &&
        hand[1].value.rank == hand[0].value.rank + 1) {
        straight = 1;
    }
    // check for ace
    if (hand[4].value.rank == 14) {
        hasAce = 1;
    }
    // check for pairs, three of a kind, four of a kind and full house
    int pairCount = 0, threeCount = 0, fourCount = 0;
    for (int i = 0; i < HAND_SIZE - 1; i++) {
        int count = 1;
        for (int j = i + 1; j < HAND_SIZE; j++) {
            if (hand[j].value.rank == hand[i].value.rank) {
                count++;
            }
        }
        if (count == 2) {
            pairCount++;
        } else if (count == 3) {
            threeCount++;
        } else if (count == 4) {
            fourCount++;
        }
    }
    if (pairCount == 1 && threeCount == 1) {
        hasFullHouse = 1;
    } else if (fourCount == 1) {
        hasFourOfAKind = 1;
    } else if (threeCount == 1) {
        hasThreeOfAKind = 1;
    } else if (pairCount == 2) {
        hasTwoPairs = 1;
    } else if (pairCount == 1) {
        hasPair = 1;
    }
    // determine the strength of the hand
    if (straight && flush && hasAce) {
        return 10;
    } else if (hasFourOfAKind) {
        return 9;
    } else if (hasFullHouse) {
        return 8;
    } else if (flush) {
        return 7;
    } else if (straight) {
        return 6;
    } else if (hasThreeOfAKind) {
        return 5;
    } else if (hasTwoPairs) {
        return 4;
    } else if (hasPair) {
        return 3;
    } else {
        return 2;
    }
}

// function to compare two hands
int compareHands(Card hand1[HAND_SIZE], Card hand2[HAND_SIZE]) {
    int strength1 = evaluateHand(hand1);
    int strength2 = evaluateHand(hand2);
    if (strength1 > strength2) {
        return 1;
    } else if (strength1 < strength2) {
        return -1;
    } else { // if tied, check highest card
        int highest1 = hand1[4].value.rank, highest2 = hand2[4].value.rank;
        if (highest1 > highest2) {
            return 1;
        } else if (highest1 < highest2) {
            return -1;
        } else { // if highest card tied, check next highest card
            int second1 = hand1[3].value.rank, second2 = hand2[3].value.rank;
            if (second1 > second2) {
                return 1;
            } else if (second1 < second2) {
                return -1;
            } else { // if all 5 cards tied, return 0
                return 0;
            }
        }
    }
}

int main() {
    Card deck[MAX_CARDS];
    createDeck(deck);
    shuffleDeck(deck);
    printf("Shuffling the deck...\n\n");
    printf("Your hand: ");
    Card hand1[HAND_SIZE], hand2[HAND_SIZE];
    for (int i = 0; i < HAND_SIZE; i++) {
        hand1[i] = deck[i];
        printf("%d ", i + 1);
        printCard(hand1[i]);
    }
    printf("\n");
    printf("Opponent's hand: ");
    for (int i = 0; i < HAND_SIZE; i++) {
        hand2[i] = deck[i + HAND_SIZE];
        printf("%d ", i + 1);
        printCard(hand2[i]);
    }
    printf("\n\n");
    int result = compareHands(hand1, hand2);
    switch (result) {
        case 1:
            printf("You win!\n");
            break;
        case -1:
            printf("You lose!\n");
            break;
        case 0:
            printf("It's a tie!\n");
            break;
        default:
            break;
    }
    return 0;
}