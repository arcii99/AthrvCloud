//FormAI DATASET v1.0 Category: Poker Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CARDS 52
#define FACES 13
#define HAND 5

// CARD STRUCTURE
struct card {
    const char *face;
    const char *suit;
};

// FUNCTION PROTOTYPES
void shuffleDeck(struct card deck[]);
void deal(struct card deck[], struct card hand[]);
int evaluateHand(struct card hand[]);

// MAIN FUNCTION
int main() {
    struct card deck[CARDS] = {
        {"Ace", "Hearts"}, {"2", "Hearts"}, {"3", "Hearts"}, {"4", "Hearts"},
        {"5", "Hearts"}, {"6", "Hearts"}, {"7", "Hearts"}, {"8", "Hearts"},
        {"9", "Hearts"}, {"10", "Hearts"}, {"Jack", "Hearts"}, {"Queen", "Hearts"},
        {"King", "Hearts"}, {"Ace", "Diamonds"}, {"2", "Diamonds"}, {"3", "Diamonds"},
        {"4", "Diamonds"}, {"5", "Diamonds"}, {"6", "Diamonds"}, {"7", "Diamonds"},
        {"8", "Diamonds"}, {"9", "Diamonds"}, {"10", "Diamonds"}, {"Jack", "Diamonds"},
        {"Queen", "Diamonds"}, {"King", "Diamonds"}, {"Ace", "Clubs"}, {"2", "Clubs"},
        {"3", "Clubs"}, {"4", "Clubs"}, {"5", "Clubs"}, {"6", "Clubs"}, {"7", "Clubs"},
        {"8", "Clubs"}, {"9", "Clubs"}, {"10", "Clubs"}, {"Jack", "Clubs"}, {"Queen", "Clubs"},
        {"King", "Clubs"}, {"Ace", "Spades"}, {"2", "Spades"}, {"3", "Spades"}, {"4", "Spades"},
        {"5", "Spades"}, {"6", "Spades"}, {"7", "Spades"}, {"8", "Spades"}, {"9", "Spades"},
        {"10", "Spades"}, {"Jack", "Spades"}, {"Queen", "Spades"}, {"King", "Spades"}};
    struct card hand[HAND];
    int handValue = 0;
    char playAgain = 'y';

    srand(time(NULL));

    while (playAgain == 'y') {
        shuffleDeck(deck);
        deal(deck, hand);
        printf("\n\nYour hand is:\n");
        for (int i = 0; i < HAND; ++i) {
            printf("%s of %s\n", hand[i].face, hand[i].suit);
        }
        handValue = evaluateHand(hand);
        printf("Hand value: %d\n\n", handValue);
        printf("Do you want to play again? (y/n)\n");
        scanf(" %c", &playAgain);
    }

    return 0;
}

// FUNCTION DEFINITIONS

void shuffleDeck(struct card deck[]) {
    for (int i = 0; i < CARDS; ++i) {
        int j = rand() % CARDS;
        struct card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void deal(struct card deck[], struct card hand[]) {
    for (int i = 0; i < HAND; ++i) {
        hand[i] = deck[i];
    }
}

int evaluateHand(struct card hand[]) {
    int handValue = 0;
    for (int i = 0; i < HAND; ++i) {
        if (hand[i].face == "Ace") {
            handValue += 11;
        } else if (hand[i].face == "Jack" || hand[i].face == "Queen" || hand[i].face == "King") {
            handValue += 10;
        } else {
            handValue += atoi(hand[i].face);
        }
    }
    return handValue;
}