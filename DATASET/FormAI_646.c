//FormAI DATASET v1.0 Category: Poker Game ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SPADES 1
#define HEARTS 2
#define CLUBS 3
#define DIAMONDS 4

#define JACK 11
#define QUEEN 12
#define KING 13
#define ACE 14

// Structure representing a card
typedef struct {
    int suit;
    int value;
} Card;

// Structure representing a player
typedef struct {
    Card cards[2];
    int chips;
} Player;

// Function to generate a deck of cards
void generateDeck(Card deck[]) {
    int i, j, count = 0;
    for (i = 1; i <= 4; i++) {
        for (j = 2; j <= 14; j++) {
            deck[count].suit = i;
            deck[count].value = j;
            count++;
        }
    }
}

// Function to shuffle the deck
void shuffleDeck(Card deck[], int size) {
    int i, j;
    Card temp;
    for (i = 0; i < size; i++) {
        j = rand() % size;
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Function to print a card
void printCard(Card card) {
    if (card.value == JACK) {
        printf("J");
    } else if (card.value == QUEEN) {
        printf("Q");
    } else if (card.value == KING) {
        printf("K");
    } else if (card.value == ACE) {
        printf("A");
    } else {
        printf("%d", card.value);
    }
    printf(" ");
    if (card.suit == SPADES) {
        printf("S");
    } else if (card.suit == HEARTS) {
        printf("H");
    } else if (card.suit == CLUBS) {
        printf("C");
    } else if (card.suit == DIAMONDS) {
        printf("D");
    }
    printf("\n");
}

// Function to deal two cards to each player
void deal(Player players[], Card deck[]) {
    int i, j;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            players[j].cards[i] = deck[i * 2 + j];
        }
    }
}

// Function to print the cards of a player
void printPlayerCards(Player player) {
    printf("Player's cards are:\n");
    printCard(player.cards[0]);
    printCard(player.cards[1]);
}

int main() {
    srand(time(NULL)); // Initialize random seed
    Card deck[52];
    generateDeck(deck); // Generate a new deck of cards
    shuffleDeck(deck, 52); // Shuffle the deck
    Player players[2];
    players[0].chips = 100; // Set initial chips for players
    players[1].chips = 100;
    deal(players, deck); // Deal two cards to each player
    printPlayerCards(players[0]); // Print the cards of player 1
    printPlayerCards(players[1]); // Print the cards of player 2
    return 0;
}