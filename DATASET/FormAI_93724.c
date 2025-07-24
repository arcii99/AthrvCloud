//FormAI DATASET v1.0 Category: Poker Game ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DECK_SIZE 52
#define SUIT_SIZE 13
#define HAND_SIZE 5

enum Suit {HEARTS, DIAMONDS, CLUBS, SPADES};
enum Rank {TWO=2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE};

typedef struct Card {
    enum Suit suit;
    enum Rank rank;
} Card;

typedef struct Hand {
    Card cards[HAND_SIZE];
} Hand;

Card deck[DECK_SIZE];

void initializeDeck() {
    int i = 0;
    for (int suit = HEARTS; suit <= SPADES; suit++) {
        for (int rank = TWO; rank <= ACE; rank++) {
            deck[i++] = (Card) {suit, rank};
        }
    }
}

void shuffleDeck() {
    for (int i = 0; i < DECK_SIZE; i++) {
        int r = rand() % DECK_SIZE;
        Card temp = deck[i];
        deck[i] = deck[r];
        deck[r] = temp;
    }
}

void printHand(Hand hand) {
    for (int i = 0; i < HAND_SIZE; i++) {
        char* suitStr = "";
        char* rankStr = "";
        switch (hand.cards[i].suit) {
            case HEARTS:
                suitStr = "Hearts";
                break;
            case DIAMONDS:
                suitStr = "Diamonds";
                break;
            case CLUBS:
                suitStr = "Clubs";
                break;
            case SPADES:
                suitStr = "Spades";
                break;
        }
        switch (hand.cards[i].rank) {
            case TWO:
                rankStr = "Two";
                break;
            case THREE:
                rankStr = "Three";
                break;
            case FOUR:
                rankStr = "Four";
                break;
            case FIVE:
                rankStr = "Five";
                break;
            case SIX:
                rankStr = "Six";
                break;
            case SEVEN:
                rankStr = "Seven";
                break;
            case EIGHT:
                rankStr = "Eight";
                break;
            case NINE:
                rankStr = "Nine";
                break;
            case TEN:
                rankStr = "Ten";
                break;
            case JACK:
                rankStr = "Jack";
                break;
            case QUEEN:
                rankStr = "Queen";
                break;
            case KING:
                rankStr = "King";
                break;
            case ACE:
                rankStr = "Ace";
                break;
        }
        printf("%s of %s\n", rankStr, suitStr);
    }
}

void dealInitialHand(Hand* hands, int numPlayers) {
    for (int i = 0; i < HAND_SIZE; i++) {
        for (int j = 0; j < numPlayers; j++) {
            hands[j].cards[i] = deck[i * numPlayers + j];
        }
    }
}

void makeBet(int* pot, int* bets, int betSize, int numPlayers) {
    for (int i = 0; i < numPlayers; i++) {
        bets[i] = 0;
    }
    char buf[10];
    for (int i = 0; i < numPlayers; i++) {
        printf("Player %d, what is your bet? (minimum %d, pot is %d): ", i+1, betSize, *pot);
        fgets(buf, 10, stdin);
        bets[i] = atoi(buf);
        while (bets[i] < betSize || bets[i] > *pot) { // repeat until the bet is valid
            printf("Invalid bet. Please enter a number between %d and %d: ", betSize, *pot);
            fgets(buf, 10, stdin);
            bets[i] = atoi(buf);
        }
        *pot -= bets[i];
    }
}

int main() {
    srand(42);
    initializeDeck();
    shuffleDeck();

    int numPlayers;
    char buf[10];
    printf("How many players? ");
    fgets(buf, 10, stdin);
    numPlayers = atoi(buf);

    Hand hands[numPlayers];
    dealInitialHand(hands, numPlayers);

    int pot = 0;
    int bets[numPlayers];
    makeBet(&pot, bets, 1, numPlayers);

    printf("\nHands:\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("Player %d:\n", i+1);
        printHand(hands[i]);
        printf("\n");
    }

    printf("\nBets:\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("Player %d: %d\n", i+1, bets[i]);
    }
    printf("Pot: %d\n", pot);

    return 0;
}