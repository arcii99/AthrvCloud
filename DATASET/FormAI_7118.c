//FormAI DATASET v1.0 Category: Poker Game ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define card suits
typedef enum
{
    Hearts,
    Diamonds,
    Clubs,
    Spades
} Suit;

// Define card ranks
typedef enum
{
    Ace,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King
} Rank;

// Define a card
typedef struct
{
    Suit suit;
    Rank rank;
} Card;

// Define a deck of cards
typedef struct
{
    Card cards[52];
    int numCards;
} Deck;

// Shuffle the deck
void shuffleDeck(Deck *deck)
{
    srand(time(NULL));
    for (int i = 0; i < deck->numCards; i++)
    {
        int j = rand() % deck->numCards;
        Card temp = deck->cards[i];
        deck->cards[i] = deck->cards[j];
        deck->cards[j] = temp;
    }
}

// Initialize the deck
void initDeck(Deck *deck)
{
    deck->numCards = 52;
    int i = 0;
    for (Suit suit = Hearts; suit <= Spades; suit++)
    {
        for (Rank rank = Ace; rank <= King; rank++)
        {
            deck->cards[i].suit = suit;
            deck->cards[i].rank = rank;
            i++;
        }
    }
    shuffleDeck(deck);
}

// Print a card
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
    }
    printf(" of ");
    switch (card.suit)
    {
    case Hearts:
        printf("Hearts");
        break;
    case Diamonds:
        printf("Diamonds");
        break;
    case Clubs:
        printf("Clubs");
        break;
    case Spades:
        printf("Spades");
        break;
    }
}

// Print the deck
void printDeck(Deck deck)
{
    for (int i = 0; i < deck.numCards; i++)
    {
        printCard(deck.cards[i]);
        printf("\n");
    }
}

// Get the value of a card
int getCardValue(Card card)
{
    switch (card.rank)
    {
    case Ace:
        return 11;
    case Two:
        return 2;
    case Three:
        return 3;
    case Four:
        return 4;
    case Five:
        return 5;
    case Six:
        return 6;
    case Seven:
        return 7;
    case Eight:
        return 8;
    case Nine:
        return 9;
    case Ten:
    case Jack:
    case Queen:
    case King:
        return 10;
    }
}

// Deal a card to a player
void dealCard(Deck *deck, Card *card)
{
    if (deck->numCards == 0)
    {
        printf("Error: Out of cards.\n");
        exit(1);
    }
    *card = deck->cards[deck->numCards - 1];
    deck->numCards--;
}

// Determine the winner of a hand
void determineWinner(int playerTotal, int dealerTotal)
{
    if ((playerTotal > dealerTotal && playerTotal <= 21) || (dealerTotal > 21 && playerTotal <= 21))
    {
        printf("Player wins!\n");
    }
    else if ((dealerTotal > playerTotal && dealerTotal <= 21) || (playerTotal > 21 && dealerTotal <= 21))
    {
        printf("Dealer wins!\n");
    }
    else
    {
        printf("Push!\n");
    }
}

// Play a hand
void playHand(Deck *deck)
{
    int playerTotal = 0;
    int dealerTotal = 0;
    Card playerCards[10];
    Card dealerCards[10];
    int numPlayerCards = 0;
    int numDealerCards = 0;
    Card card;

    // Deal initial cards
    dealCard(deck, &playerCards[numPlayerCards]);
    numPlayerCards++;
    dealCard(deck, &dealerCards[numDealerCards]);
    numDealerCards++;
    dealCard(deck, &playerCards[numPlayerCards]);
    numPlayerCards++;
    dealCard(deck, &dealerCards[numDealerCards]);
    numDealerCards++;

    // Player's turn
    while (playerTotal < 21)
    {
        printf("Player's cards:\n");
        for (int i = 0; i < numPlayerCards; i++)
        {
            printCard(playerCards[i]);
            printf("\n");
        }
        playerTotal = 0;
        for (int i = 0; i < numPlayerCards; i++)
        {
            playerTotal += getCardValue(playerCards[i]);
        }
        printf("Player's total: %d\n", playerTotal);
        char choice;
        printf("Hit or stand? (H/S)\n");
        scanf(" %c", &choice);
        if (choice == 'H' || choice == 'h')
        {
            dealCard(deck, &playerCards[numPlayerCards]);
            numPlayerCards++;
        }
        else
        {
            break;
        }
    }

    // Dealer's turn
    while (dealerTotal < 17)
    {
        dealCard(deck, &dealerCards[numDealerCards]);
        numDealerCards++;
        dealerTotal = 0;
        for (int i = 0; i < numDealerCards; i++)
        {
            dealerTotal += getCardValue(dealerCards[i]);
        }
    }

    // Determine the winner
    printf("Player's cards:\n");
    for (int i = 0; i < numPlayerCards; i++)
    {
        printCard(playerCards[i]);
        printf("\n");
    }
    playerTotal = 0;
    for (int i = 0; i < numPlayerCards; i++)
    {
        playerTotal += getCardValue(playerCards[i]);
    }
    printf("Player's total: %d\n", playerTotal);
    printf("Dealer's cards:\n");
    for (int i = 0; i < numDealerCards; i++)
    {
        printCard(dealerCards[i]);
        printf("\n");
    }
    dealerTotal = 0;
    for (int i = 0; i < numDealerCards; i++)
    {
        dealerTotal += getCardValue(dealerCards[i]);
    }
    printf("Dealer's total: %d\n", dealerTotal);
    determineWinner(playerTotal, dealerTotal);
}

int main()
{
    // Initialize the deck
    Deck deck;
    initDeck(&deck);

    // Play the hand
    playHand(&deck);

    return 0;
}