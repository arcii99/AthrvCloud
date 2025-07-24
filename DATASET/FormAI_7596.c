//FormAI DATASET v1.0 Category: Poker Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define HAND_SIZE 5

// Card structure
typedef struct Card {
    char suit;
    char value;
} Card;

// Hand structure
typedef struct Hand {
    Card cards[HAND_SIZE];
} Hand;

// Deck structure
typedef struct Deck {
    Card cards[DECK_SIZE];
    int topCard;
} Deck;

// Initializes the deck
void initDeck(Deck *deck) {
    char suits[4] = {'C', 'D', 'H', 'S'};
    char values[13] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
    int i, j, k = 0;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 13; j++) {
            deck->cards[k].suit = suits[i];
            deck->cards[k].value = values[j];
            k++;
        }
    }

    deck->topCard = k;
}

// Shuffles the deck
void shuffleDeck(Deck *deck) {
    srand(time(NULL));
    int i, j;
    Card temp;

    for (i = 0; i < deck->topCard; i++) {
        j = rand() % deck->topCard;
        temp = deck->cards[i];
        deck->cards[i] = deck->cards[j];
        deck->cards[j] = temp;
    }
}

// Deals a card from the deck
Card dealCard(Deck *deck) {
    Card card = deck->cards[deck->topCard - 1];
    deck->topCard--;
    return card;
}

// Initializes the hand
void initHand(Hand *hand) {
    int i;

    for (i = 0; i < HAND_SIZE; i++) {
        hand->cards[i].suit = '\0';
        hand->cards[i].value = '\0';
    }
}

// Prints a hand
void printHand(Hand *hand) {
    int i;

    for (i = 0; i < HAND_SIZE; i++) {
        printf("%c%c ", hand->cards[i].value, hand->cards[i].suit);
    }

    printf("\n");
}

// Checks if a hand is a flush
int isFlush(Hand *hand) {
    int i;
    char suit = hand->cards[0].suit;

    for (i = 1; i < HAND_SIZE; i++) {
        if (hand->cards[i].suit != suit) {
            return 0;
        }
    }

    return 1;
}

// Checks if a hand is a straight
int isStraight(Hand *hand) {
    int i, j, minIndex;
    char values[HAND_SIZE];
    int isAce = 0;
    char temp;

    for (i = 0; i < HAND_SIZE; i++) {
        values[i] = hand->cards[i].value;

        if (values[i] == 'A') {
            isAce = 1;
        }
    }

    // Sort the values in ascending order using bubble sort
    for (i = 0; i < HAND_SIZE - 1; i++) {
        minIndex = i;

        for (j = i + 1; j < HAND_SIZE; j++) {
            if (values[j] < values[minIndex]) {
                minIndex = j;
            }
        }

        temp = values[i];
        values[i] = values[minIndex];
        values[minIndex] = temp;
    }

    if (isAce) {
        // Check for A, 2, 3, 4, 5
        if (values[0] == 'A' && values[1] == '2' && values[2] == '3' && values[3] == '4' && values[4] == '5') {
            return 1;
        }

        // Check for 10, J, Q, K, A
        if (values[0] == 'T' && values[1] == 'J' && values[2] == 'Q' && values[3] == 'K' && values[4] == 'A') {
            return 1;
        }
    }

    // Check for 5 consecutive values
    for (i = 0; i < HAND_SIZE - 1; i++) {
        if (values[i+1] - values[i] != 1) {
            return 0;
        }
    }

    return 1;
}

// Checks if a hand is a flush or a straight
int isFlushOrStraight(Hand *hand) {
    if (isFlush(hand) || isStraight(hand)) {
        return 1;
    }

    return 0;
}

// Main function
int main() {
    Deck deck;
    Hand hand;
    int i;

    // Initialize the deck, shuffle it and deal a hand
    initDeck(&deck);
    shuffleDeck(&deck);
    initHand(&hand);

    for (i = 0; i < HAND_SIZE; i++) {
        hand.cards[i] = dealCard(&deck);
    }

    // Print the hand
    printHand(&hand);

    // Check if the hand is a flush or a straight
    if (isFlushOrStraight(&hand)) {
        printf("You have a flush or a straight!\n");
    } else {
        printf("You do not have a flush or a straight.\n");
    }

    return 0;
}