//FormAI DATASET v1.0 Category: Poker Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define HAND_SIZE 5

typedef enum Suit { HEARTS, DIAMONDS, CLUBS, SPADES } Suit;
typedef enum Rank { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING } Rank;
typedef struct Card { Suit suit; Rank rank; } Card;
typedef struct Hand { Card cards[HAND_SIZE]; } Hand;

void shuffleCards(Card deck[]) {
    srand(time(NULL));
    for (int i = 0; i < DECK_SIZE; i++) {
        int j = rand() % DECK_SIZE;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void dealCards(Card deck[], Hand* hand) {
    for (int i = 0; i < HAND_SIZE; i++) {
        hand->cards[i] = deck[i];
    }
}

void printCard(Card card) {
    char* suits[] = { "Hearts", "Diamonds", "Clubs", "Spades" };
    char* ranks[] = { NULL, "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };

    printf("%s of %s\n", ranks[card.rank], suits[card.suit]);
}

void printHand(Hand hand) {
    for (int i = 0; i < HAND_SIZE; i++) {
        printCard(hand.cards[i]);
    }
}

int isRoyalFlush(Hand hand) {
    int count = 0;
    int expected[HAND_SIZE] = { 10, JACK, QUEEN, KING, ACE };
    for (int i = 0; i < HAND_SIZE; i++) {
        if (hand.cards[i].rank == expected[count] && hand.cards[i].suit == HEARTS) {
            count++;
        }
    }
    return count == HAND_SIZE;
}

int isStraightFlush(Hand hand) {
    int count = 0;
    for (int i = 0; i < HAND_SIZE - 1; i++) {
        if (hand.cards[i].rank == hand.cards[i + 1].rank - 1 && hand.cards[i].suit == hand.cards[i + 1].suit) {
            count++;
        }
    }
    return count == HAND_SIZE - 1;
}

int isFourOfAKind(Hand hand) {
    int count = 0;
    for (int i = 0; i < HAND_SIZE - 1; i++) {
        if (hand.cards[i].rank == hand.cards[i + 1].rank) {
            count++;
        }
    }
    return count == HAND_SIZE - 1;
}

int isFullHouse(Hand hand) {
    int count = 0;
    for (int i = 0; i < HAND_SIZE - 1; i++) {
        if (hand.cards[i].rank == hand.cards[i + 1].rank) {
            if (i < HAND_SIZE - 2 && hand.cards[i].rank == hand.cards[i + 2].rank) {
                count += 2;
                break;
            }
            else {
                count++;
            }
        }
    }
    return count == HAND_SIZE - 2;
}

int isFlush(Hand hand) {
    int count = 0;
    for (int i = 0; i < HAND_SIZE - 1; i++) {
        if (hand.cards[i].suit == hand.cards[i + 1].suit) {
            count++;
        }
    }
    return count == HAND_SIZE - 1;
}

int isStraight(Hand hand) {
    int count = 0;
    for (int i = 0; i < HAND_SIZE - 1; i++) {
        if (hand.cards[i].rank == hand.cards[i + 1].rank - 1) {
            count++;
        }
    }
    return count == HAND_SIZE - 1;
}

int isThreeOfAKind(Hand hand) {
    int count = 0;
    for (int i = 0; i < HAND_SIZE - 2; i++) {
        if (hand.cards[i].rank == hand.cards[i + 1].rank && hand.cards[i + 1].rank == hand.cards[i + 2].rank) {
            count += 3;
            break;
        }
    }
    return count == 3;
}

int isTwoPair(Hand hand) {
    int count = 0;
    for (int i = 0; i < HAND_SIZE - 1; i++) {
        if (hand.cards[i].rank == hand.cards[i + 1].rank) {
            count++;
        }
    }
    return count == 2;
}

int isOnePair(Hand hand) {
    int count = 0;
    for (int i = 0; i < HAND_SIZE - 1; i++) {
        if (hand.cards[i].rank == hand.cards[i + 1].rank) {
            count += 2;
            break;
        }
    }
    return count == 2;
}

int getHandValue(Hand hand) {
    if (isRoyalFlush(hand)) {
        return 10;
    }
    if (isStraightFlush(hand)) {
        return 9;
    }
    if (isFourOfAKind(hand)) {
        return 8;
    }
    if (isFullHouse(hand)) {
        return 7;
    }
    if (isFlush(hand)) {
        return 6;
    }
    if (isStraight(hand)) {
        return 5;
    }
    if (isThreeOfAKind(hand)) {
        return 4;
    }
    if (isTwoPair(hand)) {
        return 3;
    }
    if (isOnePair(hand)) {
        return 2;
    }
    return 1;
}

void playGame() {
    Card deck[DECK_SIZE];
    for (int i = 0; i < DECK_SIZE; i++) {
        deck[i].suit = (Suit)(i % 4);
        deck[i].rank = (Rank)((i % 13) + 1);
    }

    shuffleCards(deck);

    Hand playerHand;
    dealCards(deck, &playerHand);

    printf("Your hand:\n");
    printHand(playerHand);

    int handValue = getHandValue(playerHand);

    printf("Hand value: %d\n", handValue);
}

int main() {
    playGame();
    return 0;
}