//FormAI DATASET v1.0 Category: Poker Game ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define MAX_PLAYERS 4
#define MAX_ROUNDS 3
#define NUM_CARDS_PER_HAND 5

//Enumeration of the suits in poker
enum suits {
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES
};

//Enumeration of ranks in poker
enum ranks {
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    ACE
};

//Struct for holding a card
struct card {
    enum suits suit;
    enum ranks rank;
};

//Struct for holding a player's hand (five cards)
struct hand {
    struct card cards[NUM_CARDS_PER_HAND];
};

//Function to shuffle the deck of cards
void shuffleDeck(struct card deck[]) {
    srand(time(NULL));
    for(int i = 0; i < DECK_SIZE; i++) {
        int j = rand() % DECK_SIZE;
        struct card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

//Function to print a card in a human-readable format
void printCard(const struct card *c) {
    const char *suit;
    const char *rank;
    switch(c->suit) {
        case CLUBS:
            suit = "Clubs";
            break;
        case DIAMONDS:
            suit = "Diamonds";
            break;
        case HEARTS:
            suit = "Hearts";
            break;
        case SPADES:
            suit = "Spades";
            break;
    }
    switch(c->rank) {
        case TWO:
            rank = "Two";
            break;
        case THREE:
            rank = "Three";
            break;
        case FOUR:
            rank = "Four";
            break;
        case FIVE:
            rank = "Five";
            break;
        case SIX:
            rank = "Six";
            break;
        case SEVEN:
            rank = "Seven";
            break;
        case EIGHT:
            rank = "Eight";
            break;
        case NINE:
            rank = "Nine";
            break;
        case TEN:
            rank = "Ten";
            break;
        case JACK:
            rank = "Jack";
            break;
        case QUEEN:
            rank = "Queen";
            break;
        case KING:
            rank = "King";
            break;
        case ACE:
            rank = "Ace";
            break;
    }
    printf("%s of %s\n", rank, suit);
}

//Function to print a player's hand
void printHand(const struct hand *h) {
    for(int i = 0; i < NUM_CARDS_PER_HAND; i++) {
        printCard(&h->cards[i]);
    }
}

//Function to deal hands to players
void dealHands(struct hand hands[], struct card deck[]) {
    for(int i = 0; i < MAX_PLAYERS; i++) {
        for(int j = 0; j < NUM_CARDS_PER_HAND; j++) {
            hands[i].cards[j] = deck[i*NUM_CARDS_PER_HAND+j];
        }
    }
}

//Main function
int main() {
    //Create deck of cards
    struct card deck[DECK_SIZE];
    int card_count = 0;
    for(int s = 0; s < 4; s++) {
        for(int r = 0; r < 13; r++) {
            deck[card_count].suit = s;
            deck[card_count].rank = r;
            card_count++;
        }
    }

    //Shuffle deck of cards
    shuffleDeck(deck);

    //Deal hands to players
    struct hand hands[MAX_PLAYERS];
    dealHands(hands, deck);

    //Print hands of each player
    for(int i = 0; i < MAX_PLAYERS; i++) {
        printf("Hand of Player %d:\n", i+1);
        printHand(&hands[i]);
        printf("\n");
    }

    return 0;
}