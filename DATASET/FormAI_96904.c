//FormAI DATASET v1.0 Category: Poker Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Card structure
struct Card {
    char* face;
    char* suit;
};

// Deck structure
struct Deck {
    struct Card cards[52];
    int index;
};

// Creates a new deck of cards
void createDeck(struct Deck* deck) {
    char* faces[13] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    char* suits[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};

    for (int i = 0; i < 52; i++) {
        deck->cards[i].face = faces[i % 13];
        deck->cards[i].suit = suits[i % 4];
    }

    deck->index = 0;
}

// Shuffles the deck
void shuffleDeck(struct Deck* deck) {
    srand(time(NULL));

    for (int i = 0; i < 52; i++) {
        int j = rand() % 52;
        struct Card temp = deck->cards[i];
        deck->cards[i] = deck->cards[j];
        deck->cards[j] = temp;
    }

    deck->index = 0;
}

// Deals a card from the deck
struct Card dealCard(struct Deck* deck) {
    struct Card card = deck->cards[deck->index];
    deck->index++;
    return card;
}

// Prints a card
void printCard(struct Card card) {
    printf("%s of %s\n", card.face, card.suit);
}

// Main function
int main() {
    struct Deck deck;
    createDeck(&deck);
    shuffleDeck(&deck);

    printf("Welcome to the Poker Game!\n");

    // Deal two cards to each player
    struct Card player1card1 = dealCard(&deck);
    struct Card player1card2 = dealCard(&deck);
    struct Card player2card1 = dealCard(&deck);
    struct Card player2card2 = dealCard(&deck);

    printf("Player 1's cards are:\n");
    printCard(player1card1);
    printCard(player1card2);

    printf("Player 2's cards are:\n");
    printCard(player2card1);
    printCard(player2card2);

    // Deal the flop (3 cards)
    printf("The flop is:\n");
    struct Card flop1 = dealCard(&deck);
    struct Card flop2 = dealCard(&deck);
    struct Card flop3 = dealCard(&deck);
    printCard(flop1);
    printCard(flop2);
    printCard(flop3);

    // Deal the turn (1 card)
    printf("The turn is:\n");
    struct Card turn = dealCard(&deck);
    printCard(turn);

    // Deal the river (1 card)
    printf("The river is:\n");
    struct Card river = dealCard(&deck);
    printCard(river);

    return 0;
}