//FormAI DATASET v1.0 Category: Poker Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the possible suits
enum suit { HEARTS, DIAMONDS, CLUBS, SPADES };

// Define the possible card values
enum value { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, 
            EIGHT, NINE, TEN, JACK, QUEEN, KING };

// Define a card structure
typedef struct {

    enum suit card_suit;
    enum value card_value;

} Card;

// Shuffle the deck of cards
void shuffle_deck(Card deck[]) {

    int i, j;
    Card temp;

    for (i = 0; i < 52; i++) {
        j = rand() % 52;
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Print out a card
void print_card(const Card* card) {

    char* suits[] = { "Hearts", "Diamonds", "Clubs", "Spades" };
    char* values[] = { "Ace", "Two", "Three", "Four", "Five", "Six", 
                       "Seven", "Eight", "Nine", "Ten", "Jack", 
                       "Queen", "King" };

    printf("%s of %s\n", values[card->card_value - 1], suits[card->card_suit]);
}

// Print out a player's hand
void print_hand(const Card hand[]) {

    int i;

    for (i = 0; i < 5; i++) {
        print_card(&hand[i]);
    }
}

// Prompt the player to discard cards
void discard_cards(Card hand[]) {

    char discard[6];
    int i, j, num_discarded = 0;

    printf("Enter the number(s) of the card(s) you want to discard: ");
    scanf("%s", discard);

    for (i = 0; i < 5; i++) {

        // Check if the current card should be discarded
        for (j = 0; j < 6; j++) {
            if (discard[j] == i + '1') {
                hand[i].card_suit = -1;
                hand[i].card_value = -1;
                num_discarded++;
            }
        }
    }

    // If the player didn't discard any cards, let them discard again
    if (num_discarded == 0) {
        printf("You must discard at least one card.\n");
        discard_cards(hand);
    }
}

int main() {

    // Seed the random number generator
    srand((unsigned int)time(NULL));

    // Initialize the deck of cards
    Card deck[52];
    int i, j, k = 0;

    for (i = 0; i < 4; i++) {
        for (j = 1; j <= 13; j++) {
            deck[k].card_suit = i;
            deck[k].card_value = j;
            k++;
        }
    }

    // Shuffle the deck of cards and deal out the player's hand
    shuffle_deck(deck);
    Card hand[5];

    for (i = 0; i < 5; i++) {
        hand[i] = deck[i];
    }

    // Print out the player's hand and let them discard cards
    printf("Your hand:\n");
    print_hand(hand);
    discard_cards(hand);

    // Deal out new cards to replace the discarded ones
    for (i = 0; i < 5; i++) {
        if (hand[i].card_suit == -1) {
            hand[i] = deck[i + 5];
        }
    }

    // Print out the player's final hand
    printf("Your final hand:\n");
    print_hand(hand);
    
    return 0;
}