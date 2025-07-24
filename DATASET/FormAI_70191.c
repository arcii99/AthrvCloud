//FormAI DATASET v1.0 Category: Poker Game ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// card structure
typedef struct {
    const char *face;
    const char *suit;
} Card;

// deck of cards structure
typedef struct {
    Card deck[52];
    int currentCard;
} Deck;

// function prototypes
void shuffleDeck(Deck *);
void printDeck(Deck *);
void dealCards(Deck *, int);


int main() {
    // initialize deck
    Deck deck = {
        .deck = {
            {"Ace", "Spades"}, {"2", "Spades"}, {"3", "Spades"}, {"4", "Spades"},
            {"5", "Spades"}, {"6", "Spades"}, {"7", "Spades"}, {"8", "Spades"},
            {"9", "Spades"}, {"10", "Spades"}, {"Jack", "Spades"}, {"Queen", "Spades"},
            {"King", "Spades"}, {"Ace", "Hearts"}, {"2", "Hearts"}, {"3", "Hearts"},
            {"4", "Hearts"}, {"5", "Hearts"}, {"6", "Hearts"}, {"7", "Hearts"},
            {"8", "Hearts"}, {"9", "Hearts"}, {"10", "Hearts"}, {"Jack", "Hearts"},
            {"Queen", "Hearts"}, {"King", "Hearts"}, {"Ace", "Diamonds"}, {"2", "Diamonds"},
            {"3", "Diamonds"}, {"4", "Diamonds"}, {"5", "Diamonds"}, {"6", "Diamonds"},
            {"7", "Diamonds"}, {"8", "Diamonds"}, {"9", "Diamonds"}, {"10", "Diamonds"},
            {"Jack", "Diamonds"}, {"Queen", "Diamonds"}, {"King", "Diamonds"}, {"Ace", "Clubs"},
            {"2", "Clubs"}, {"3", "Clubs"}, {"4", "Clubs"}, {"5", "Clubs"}, {"6", "Clubs"},
            {"7", "Clubs"}, {"8", "Clubs"}, {"9", "Clubs"}, {"10", "Clubs"}, {"Jack", "Clubs"},
            {"Queen", "Clubs"}, {"King", "Clubs"}
        },
        .currentCard = 0
    };

    // shuffle deck
    shuffleDeck(&deck);

    // print shuffled deck
    printDeck(&deck);

    // deal cards
    dealCards(&deck, 5);

    return 0;
}

// shuffles the deck
void shuffleDeck(Deck *deck) {
    srand(time(NULL));
    for (int i = 0; i < 52; i++) {
        int j = rand() % 52;
        Card temp = deck->deck[i];
        deck->deck[i] = deck->deck[j];
        deck->deck[j] = temp;
    }
}

// prints each card in the deck
void printDeck(Deck *deck) {
    for (int i = 0; i < 52; i++) {
        printf("%s of %s\n", deck->deck[i].face, deck->deck[i].suit);
    }
}

// deals specified number of cards
void dealCards(Deck *deck, int numCards) {
    printf("\nDealing %d cards:\n", numCards);
    for (int i = 0; i < numCards; i++) {
        if (deck->currentCard == 52) {
            printf("There are no more cards in the deck.\n");
            return;
        }
        printf("%s of %s\n", deck->deck[deck->currentCard].face, deck->deck[deck->currentCard].suit);
        deck->currentCard++;
    }
}