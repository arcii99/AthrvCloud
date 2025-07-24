//FormAI DATASET v1.0 Category: Poker Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 52

enum Suit {
    HEARTS, SPADES, CLUBS, DIAMONDS
};

enum Rank {
    TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE
};

struct Card {
    enum Suit suit;
    enum Rank rank;
};

int deck[NUM_CARDS];

void shuffle()
{
    srand(time(NULL));
    for (int i = 0; i < NUM_CARDS; i++) {
        int j = rand() % NUM_CARDS;
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

int main()
{
    struct Card hand[5];

    // Initialize deck of cards
    for (int i = 0; i < NUM_CARDS; i++) {
        deck[i] = i;
    }

    // Shuffle deck
    shuffle();

    // Deal hand
    for (int i = 0; i < 5; i++) {
        int card = deck[i];
        enum Suit suit = card / 13;
        enum Rank rank = card % 13;
        hand[i].suit = suit;
        hand[i].rank = rank;
    }

    // Print hand
    for (int i = 0; i < 5; i++) {
        char* suit_str;
        char* rank_str;

        switch (hand[i].suit) {
            case HEARTS:
                suit_str = "Hearts";
                break;
            case SPADES:
                suit_str = "Spades";
                break;
            case CLUBS:
                suit_str = "Clubs";
                break;
            case DIAMONDS:
                suit_str = "Diamonds";
                break;
        }

        switch (hand[i].rank) {
            case TWO:
                rank_str = "Two";
                break;
            case THREE:
                rank_str = "Three";
                break;
            case FOUR:
                rank_str = "Four";
                break;
            case FIVE:
                rank_str = "Five";
                break;
            case SIX:
                rank_str = "Six";
                break;
            case SEVEN:
                rank_str = "Seven";
                break;
            case EIGHT:
                rank_str = "Eight";
                break;
            case NINE:
                rank_str = "Nine";
                break;
            case TEN:
                rank_str = "Ten";
                break;
            case JACK:
                rank_str = "Jack";
                break;
            case QUEEN:
                rank_str = "Queen";
                break;
            case KING:
                rank_str = "King";
                break;
            case ACE:
                rank_str = "Ace";
                break;
        }

        printf("%s of %s\n", rank_str, suit_str);
    }

    return 0;
}