//FormAI DATASET v1.0 Category: Poker Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define HAND_SIZE 5

typedef enum {Clubs, Diamonds, Hearts, Spades} Suit;
typedef enum {Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace} Rank;

typedef struct {
    Suit suit;
    Rank rank;
} Card;

void shuffle(Card deck[]);
void print_card(Card card);
void print_hand(Card hand[]);

int main(void)
{
    srand(time(NULL));

    Card deck[DECK_SIZE];
    int i, j, k;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 13; j++) {
            k = i * 13 + j;
            deck[k].suit = i;
            deck[k].rank = j;
        }
    }

    shuffle(deck);

    Card hand[HAND_SIZE];
    for (i = 0; i < HAND_SIZE; i++) {
        hand[i] = deck[i];
    }

    printf("Your hand:\n");
    print_hand(hand);

    return 0;
}

void shuffle(Card deck[])
{
    int i, j;
    Card temp;
    for (i = 0; i < DECK_SIZE; i++) {
        j = rand() % DECK_SIZE;
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void print_card(Card card)
{
    switch (card.rank) {
        case Two:
            printf("2");
            break;
        case Three:
            printf("3");
            break;
        case Four:
            printf("4");
            break;
        case Five:
            printf("5");
            break;
        case Six:
            printf("6");
            break;
        case Seven:
            printf("7");
            break;
        case Eight:
            printf("8");
            break;
        case Nine:
            printf("9");
            break;
        case Ten:
            printf("10");
            break;
        case Jack:
            printf("J");
            break;
        case Queen:
            printf("Q");
            break;
        case King:
            printf("K");
            break;
        case Ace:
            printf("A");
            break;
    }

    switch (card.suit) {
        case Clubs:
            printf("C ");
            break;
        case Diamonds:
            printf("D ");
            break;
        case Hearts:
            printf("H ");
            break;
        case Spades:
            printf("S ");
            break;
    }
}

void print_hand(Card hand[])
{
    int i;
    for (i = 0; i < HAND_SIZE; i++) {
        print_card(hand[i]);
    }
}