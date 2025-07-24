//FormAI DATASET v1.0 Category: Poker Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Create an array of card strings
const char* ranks[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
const char* suits[] = {"Spades", "Hearts", "Diamonds", "Clubs"};

// Define card structure
typedef struct {
    int rank;
    int suit;
} Card;

// Shuffle deck of cards
void shuffleDeck(Card* deck, int deckLength) {
    srand(time(NULL));
    for (int i = 0; i < deckLength; i++) {
        int j = rand() % deckLength;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

int main() {
    // Create deck of cards
    Card deck[52];
    int count = 0;
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 4; j++) {
            deck[count].rank = i;
            deck[count].suit = j;
            count++;
        }
    }

    // Shuffle deck of cards
    shuffleDeck(deck, 52);

    // Deal 2 cards to 4 players
    Card player1hand[2];
    Card player2hand[2];
    Card player3hand[2];
    Card player4hand[2];

    player1hand[0] = deck[0];
    player2hand[0] = deck[1];
    player3hand[0] = deck[2];
    player4hand[0] = deck[3];
    player1hand[1] = deck[4];
    player2hand[1] = deck[5];
    player3hand[1] = deck[6];
    player4hand[1] = deck[7];

    // Print out the cards in each player's hand
    printf("Player 1's Hand: %s of %s, %s of %s\n", ranks[player1hand[0].rank], suits[player1hand[0].suit], ranks[player1hand[1].rank], suits[player1hand[1].suit]);
    printf("Player 2's Hand: %s of %s, %s of %s\n", ranks[player2hand[0].rank], suits[player2hand[0].suit], ranks[player2hand[1].rank], suits[player2hand[1].suit]);
    printf("Player 3's Hand: %s of %s, %s of %s\n", ranks[player3hand[0].rank], suits[player3hand[0].suit], ranks[player3hand[1].rank], suits[player3hand[1].suit]);
    printf("Player 4's Hand: %s of %s, %s of %s\n", ranks[player4hand[0].rank], suits[player4hand[0].suit], ranks[player4hand[1].rank], suits[player4hand[1].suit]);

    return 0;
}