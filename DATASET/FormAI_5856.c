//FormAI DATASET v1.0 Category: Poker Game ; Style: cheerful
// Welcome to the Cheery Poker Game!
// This game is all about fun and cards, so grab a drink, and get ready!
// The rules are simple: every player receives two cards, and then we'll deal five more
// cards in the middle. The player with the best hand wins!
// Let's start coding, and don't forget to enjoy the ride!

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the suits and ranks of the cards
const char *suits[] = {"Spades", "Hearts", "Diamonds", "Clubs"};
const char *ranks[] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven",
                       "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

// Define the card structure
typedef struct {
    int rank;
    int suit;
} Card;

// Function to print a card
void print_card(Card card) {
    printf("%s of %s\n", ranks[card.rank], suits[card.suit]);
}

// Function to shuffle the deck
void shuffle_deck(Card deck[52]) {
    srand(time(NULL)); // initialize random seed
    for (int i = 51; i > 0; i--) {
        // Generate a random index between 0 and i
        int j = rand() % (i + 1);

        // Swap the cards at index i and j
        Card temp = deck[j];
        deck[j] = deck[i];
        deck[i] = temp;
    }
}

// Function to initialize the deck
void init_deck(Card deck[52]) {
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 4; j++) {
            deck[i * 4 + j].rank = i;
            deck[i * 4 + j].suit = j;
        }
    }
}

int main() {
    printf("Welcome to the Cheery Poker Game!\n");
    printf("Let's shuffle the deck...\n");

    // Initialize the deck and shuffle it
    Card deck[52];
    init_deck(deck);
    shuffle_deck(deck);

    // Print the shuffled deck
    printf("Here's the shuffled deck:\n");
    for (int i = 0; i < 52; i++) {
        print_card(deck[i]);
    }

    // Let's deal some cards!
    printf("Dealing cards...\n");

    // Initialize the players' hands
    Card player1[7];
    Card player2[7];

    // Deal the first two cards to each player
    player1[0] = deck[0];
    deck[0].suit = -1; // mark as dealt
    player2[0] = deck[1];
    deck[1].suit = -1; // mark as dealt

    player1[1] = deck[2];
    deck[2].suit = -1; // mark as dealt
    player2[1] = deck[3];
    deck[3].suit = -1; // mark as dealt
    
    printf("Player 1's hand:\n");
    print_card(player1[0]);
    print_card(player1[1]);

    printf("Player 2's hand:\n");
    print_card(player2[0]);
    print_card(player2[1]);

    // Deal the flop (three cards in the middle)
    Card flop[3];
    flop[0] = deck[4];
    deck[4].suit = -1; // mark as dealt
    flop[1] = deck[5];
    deck[5].suit = -1; // mark as dealt
    flop[2] = deck[6];
    deck[6].suit = -1; // mark as dealt

    printf("The flop:\n");
    print_card(flop[0]);
    print_card(flop[1]);
    print_card(flop[2]);

    // Deal the turn (one more card in the middle)
    Card turn = deck[7];
    deck[7].suit = -1; // mark as dealt

    printf("The turn:\n");
    print_card(turn);

    // Deal the river (one last card in the middle)
    Card river = deck[8];
    deck[8].suit = -1; // mark as dealt

    printf("The river:\n");
    print_card(river);

    printf("Thanks for playing Cheery Poker! Good luck!\n");
    return 0;
}