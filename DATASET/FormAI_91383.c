//FormAI DATASET v1.0 Category: Poker Game ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FACE_NUM 13
#define SUIT_NUM 4
#define DECK_SIZE 52
#define HAND_SIZE 5
#define HIGH_CARD 0
#define PAIR 1
#define TWO_PAIR 2
#define THREE_OF_A_KIND 3
#define STRAIGHT 4
#define FLUSH 5
#define FULL_HOUSE 6
#define FOUR_OF_A_KIND 7
#define STRAIGHT_FLUSH 8

const char *HAND_VALUES[] = {"High Card", "Pair", "Two Pair", "Three of a Kind", "Straight", "Flush", "Full House", "Four of a Kind", "Straight Flush"};
const char *SUITS[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
const char *FACES[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};

typedef struct {
    int value;
    int suit;
} Card;

typedef struct {
    Card cards[HAND_SIZE];
    int value;
} Hand;

void printCard(Card card) {
    printf("%s of %s\n", FACES[card.value], SUITS[card.suit]);
}

void printHand(Hand hand) {
    for (int i=0; i<HAND_SIZE; i++) {
        printCard(hand.cards[i]);
    }
    printf("Hand Value: %s\n", HAND_VALUES[hand.value]);
}

void shuffleDeck(Card *deck) {
    srand(time(NULL));
    for (int i=0; i<DECK_SIZE; i++) {
        int r = rand() % DECK_SIZE;
        Card temp = deck[i];
        deck[i] = deck[r];
        deck[r] = temp;
    }
}

void dealHand(Card *deck, Hand *hand) {
    for (int i=0; i<HAND_SIZE; i++) {
        hand->cards[i] = deck[i];
    }
}

int getHandValue(Hand hand) {
    int values[FACE_NUM] = {0};
    int suits[SUIT_NUM] = {0};

    // Count the number of each face and suit
    for (int i=0; i<HAND_SIZE; i++) {
        values[hand.cards[i].value]++;
        suits[hand.cards[i].suit]++;
    }

    int hasPair = 0;
    int hasThreeOfAKind = 0;
    int hasFourOfAKind = 0;
    int hasFlush = 0;
    int hasStraight = 0;
    int straightCount = 0;
    int highestStraightCard = 0;

    // Check for pairs and three/four of a kind
    for (int i=0; i<FACE_NUM; i++) {
        if (values[i] == 2) {
            hasPair++;
        } else if (values[i] == 3) {
            hasThreeOfAKind++;
        } else if (values[i] == 4) {
            hasFourOfAKind++;
        }
    }

    // Check for flush
    for (int i=0; i<SUIT_NUM; i++) {
        if (suits[i] == HAND_SIZE) {
            hasFlush = 1;
        }
    }

    // Check for straight
    for (int i=0; i<FACE_NUM; i++) {
        if (values[i] == 1) {
            straightCount++;
            highestStraightCard = i;
        } else {
            straightCount = 0;
        }
        if (straightCount == 5) {
            hasStraight = 1;
        }
    }

    if (hasStraight && hasFlush) {
        return STRAIGHT_FLUSH;
    } else if (hasFourOfAKind) {
        return FOUR_OF_A_KIND;
    } else if (hasThreeOfAKind && hasPair) {
        return FULL_HOUSE;
    } else if (hasFlush) {
        return FLUSH;
    } else if (hasStraight) {
        return STRAIGHT;
    } else if (hasThreeOfAKind) {
        return THREE_OF_A_KIND;
    } else if (hasPair == 2) {
        return TWO_PAIR;
    } else if (hasPair) {
        return PAIR;
    } else {
        return HIGH_CARD;
    }
}

int compareHands(Hand hand1, Hand hand2) {
    if (hand1.value > hand2.value) {
        return 1;
    } else if (hand1.value < hand2.value) {
        return -1;
    } else {
        // Compare the high cards
        for (int i=HAND_SIZE-1; i>=0; i--) {
            if (hand1.cards[i].value > hand2.cards[i].value) {
                return 1;
            } else if (hand1.cards[i].value < hand2.cards[i].value) {
                return -1;
            }
        }
        return 0;
    }
}

int main() {
    Card deck[DECK_SIZE];
    int handCount = 2;
    Hand hands[handCount];

    // Generate deck
    int index = 0;
    for (int i=0; i<SUIT_NUM; i++) {
        for (int j=0; j<FACE_NUM; j++) {
            deck[index].suit = i;
            deck[index].value = j;
            index++;
        }
    }

    shuffleDeck(deck);

    // Deal hands
    for (int i=0; i<handCount; i++) {
        dealHand(&deck[i*HAND_SIZE], &hands[i]);
        hands[i].value = getHandValue(hands[i]);
    }

    // Print hands and winner
    for (int i=0; i<handCount; i++) {
        printf("Player %d Hand:\n", i+1);
        printHand(hands[i]);
        printf("\n");
    }

    int winner = compareHands(hands[0], hands[1]);

    if (winner == 1) {
        printf("Player 1 Wins!\n");
    } else if (winner == -1) {
        printf("Player 2 Wins!\n");
    } else {
        printf("It's a tie!\n");
    }
    
    return 0;
}