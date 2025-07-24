//FormAI DATASET v1.0 Category: Poker Game ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 52
#define NUM_SUITS 4
#define NUM_RANKS 13
#define NUM_HANDS 2

enum Suit { Hearts, Clubs, Diamonds, Spades };
enum Rank { Ace = 1, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King };
enum Hand { Player, Computer };

typedef struct Card
{
    enum Suit suit;
    enum Rank rank;
} Card;

typedef struct Deck
{
    Card cards[NUM_CARDS];
} Deck;

typedef struct HandStruct
{
    Card cards[NUM_HANDS];
} HandStruct;

void shuffle(Deck* deck)
{
    srand((unsigned int)time(NULL));

    for (int i = 0; i < NUM_CARDS; i++)
    {
        int j = rand() % NUM_CARDS;

        Card temp = deck->cards[i];
        deck->cards[i] = deck->cards[j];
        deck->cards[j] = temp;
    }
}

void deal(Deck* deck, HandStruct* player, HandStruct* computer)
{
    for (int i = 0; i < NUM_HANDS; i++)
    {
        player->cards[i] = deck->cards[i * 2];
        computer->cards[i] = deck->cards[i * 2 + 1];
    }
}

void printCard(Card card)
{
    switch (card.rank)
    {
        case Ace:
            printf("Ace");
            break;

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
            printf("Jack");
            break;

        case Queen:
            printf("Queen");
            break;

        case King:
            printf("King");
            break;

        default:
            break;
    }

    printf(" of ");

    switch (card.suit)
    {
        case Hearts:
            printf("Hearts");
            break;

        case Clubs:
            printf("Clubs");
            break;

        case Diamonds:
            printf("Diamonds");
            break;

        case Spades:
            printf("Spades");
            break;

        default:
            break;
    }
}

void printHand(HandStruct* hand, enum Hand handType)
{
    printf("%s's hand:\n", handType == Player ? "Player" : "Computer");

    for (int i = 0; i < NUM_HANDS; i++)
    {
        printf("\t");
        printCard(hand->cards[i]);
        printf("\n");
    }
}

int main()
{
    Deck deck;

    for (int i = 0; i < NUM_SUITS; i++)
    {
        for (int j = 1; j <= NUM_RANKS; j++)
        {
            deck.cards[i * NUM_RANKS + j - 1].suit = i;
            deck.cards[i * NUM_RANKS + j - 1].rank = j;
        }
    }

    shuffle(&deck);

    HandStruct playerHand;
    HandStruct computerHand;

    deal(&deck, &playerHand, &computerHand);

    printHand(&playerHand, Player);
    printHand(&computerHand, Computer);

    return 0;
}