//FormAI DATASET v1.0 Category: Poker Game ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define HAND_SIZE 5

typedef enum {SPADES, HEARTS, DIAMONDS, CLUBS} Suit;
typedef enum {ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING} Rank;

typedef struct {
    Rank rank;
    Suit suit;
} Card;

typedef struct {
    Card cards[HAND_SIZE];
} Hand;

typedef struct {
    Card deck[DECK_SIZE];
    int top;
} Deck;

void initializeDeck(Deck *deck) {
    int i, j;
    deck->top = 0;
    for (i = SPADES; i <= CLUBS; i++) {
        for (j = ACE; j <= KING; j++) {
            deck->deck[deck->top].suit = i;
            deck->deck[deck->top].rank = j;
            deck->top++;
        }
    }
}

void shuffleDeck(Deck *deck) {
    int i, j;
    Card temp;
    srand((unsigned) time(NULL));
    for (i = 0; i < deck->top; i++) {
        j = rand() % deck->top;
        temp = deck->deck[i];
        deck->deck[i] = deck->deck[j];
        deck->deck[j] = temp;
    }
}

void dealCards(Deck *deck, Hand *hand) {
    int i;
    for (i = 0; i < HAND_SIZE; i++) {
        hand->cards[i] = deck->deck[deck->top - 1];
        deck->top--;
    }
}

void printCard(Card card) {
    char *rank, *suit;
    switch (card.rank) {
        case ACE:
            rank = "Ace";
            break;
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
        default:
            rank = "Error";
            break;
    }
    switch (card.suit) {
        case SPADES:
            suit = "Spades";
            break;
        case HEARTS:
            suit = "Hearts";
            break;
        case DIAMONDS:
            suit = "Diamonds";
            break;
        case CLUBS:
            suit = "Clubs";
            break;
        default:
            suit = "Error";
            break;
    }
    printf("%s of %s\n", rank, suit);
}

void printHand(Hand hand) {
    int i;
    for (i = 0; i < HAND_SIZE; i++) {
        printCard(hand.cards[i]);
    }
}

int main(void) {
    Deck deck;
    Hand hand;
    initializeDeck(&deck);
    shuffleDeck(&deck);
    dealCards(&deck, &hand);
    printf("Your hand:\n");
    printHand(hand);
    return 0;
}