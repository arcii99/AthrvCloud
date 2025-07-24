//FormAI DATASET v1.0 Category: Poker Game ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffleDeck(int deck[]);
void dealCards(int deck[], int playerCards[][2]);
int getCardValue(int card);
int getHandValue(int hand[][2], int numCards);
void printCard(int card);
void printHand(int hand[][2], int numCards);

int main()
{
    int deck[52] = {0};
    int playerCards[2][2] = {0};
    int dealerCards[2][2] = {0};
    int numPlayerCards = 0;
    int numDealerCards = 0;
    int playerVal = 0;
    int dealerVal = 0;
    char hitStand = 'h';
    srand(time(NULL));

    // Welcome message
    printf("Welcome to Retro Poker!\n");

    // Shuffle the deck and deal cards
    shuffleDeck(deck);
    dealCards(deck, playerCards);
    dealCards(deck, dealerCards);
    numPlayerCards = 2;
    numDealerCards = 2;

    // Show the player's hand and ask if they want to hit or stand
    printf("Your hand: ");
    printHand(playerCards, numPlayerCards);
    printf("Dealer's up card: ");
    printCard(dealerCards[0][0]);
    printf("\n");
    printf("Do you want to hit or stand? ");
    scanf("%c", &hitStand);

    // Player's turn
    while (hitStand == 'h')
    {
        // Deal the player a card
        playerCards[numPlayerCards][0] = deck[0];
        playerCards[numPlayerCards][1] = getCardValue(deck[0]);
        deck[0] = -1;
        numPlayerCards++;

        // Show the player's hand and ask if they want to hit or stand
        printf("Your hand: ");
        printHand(playerCards, numPlayerCards);
        printf("Dealer's up card: ");
        printCard(dealerCards[0][0]);
        printf("\n");
        playerVal = getHandValue(playerCards, numPlayerCards);
        printf("Your hand is worth %d points.\n", playerVal);
        if (playerVal >= 21)
        {
            break;
        }
        printf("Do you want to hit or stand? ");
        scanf(" %c", &hitStand);
    }

    // Dealer's turn
    dealerVal = getHandValue(dealerCards, numDealerCards);
    while (dealerVal < 17)
    {
        // Deal the dealer a card
        dealerCards[numDealerCards][0] = deck[0];
        dealerCards[numDealerCards][1] = getCardValue(deck[0]);
        deck[0] = -1;
        numDealerCards++;
        dealerVal = getHandValue(dealerCards, numDealerCards);
    }

    // Show the final hands and determine the winner
    printf("\n");
    printf("Your final hand: ");
    printHand(playerCards, numPlayerCards);
    printf("Dealer's final hand: ");
    printHand(dealerCards, numDealerCards);
    printf("\n");
    playerVal = getHandValue(playerCards, numPlayerCards);
    dealerVal = getHandValue(dealerCards, numDealerCards);
    if (playerVal > 21)
    {
        printf("You bust! Dealer wins!\n");
    }
    else if (dealerVal > 21)
    {
        printf("Dealer busts! You win!\n");
    }
    else if (playerVal == dealerVal)
    {
        printf("It's a tie!\n");
    }
    else if (playerVal > dealerVal)
    {
        printf("You win!\n");
    }
    else
    {
        printf("Dealer wins!\n");
    }

    return 0;
}

void shuffleDeck(int deck[])
{
    int i;
    for (i = 0; i < 52; i++)
    {
        deck[i] = i;
    }

    for (i = 0; i < 52; i++)
    {
        int j = rand() % 52;
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void dealCards(int deck[], int playerCards[][2])
{
    playerCards[0][0] = deck[0];
    playerCards[0][1] = getCardValue(deck[0]);
    deck[0] = -1;

    playerCards[1][0] = deck[1];
    playerCards[1][1] = getCardValue(deck[1]);
    deck[1] = -1;
}

int getCardValue(int card)
{
    int value = (card % 13) + 1;
    if (value > 10)
    {
        value = 10;
    }

    return value;
}

int getHandValue(int hand[][2], int numCards)
{
    int i;
    int value = 0;
    int numAces = 0;

    for (i = 0; i < numCards; i++)
    {
        value += hand[i][1];
        if (hand[i][1] == 1)
        {
            numAces++;
        }
    }

    while (value <= 11 && numAces > 0)
    {
        value += 10;
        numAces--;
    }

    return value;
}

void printCard(int card)
{
    const char *rank[] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    const char *suit[] = {"Hearts", "Diamonds", "Clubs", "Spades"};

    printf("%s of %s", rank[card % 13], suit[card / 13]);
}

void printHand(int hand[][2], int numCards)
{
    int i;
    for (i = 0; i < numCards; i++)
    {
        printCard(hand[i][0]);
        printf(" ");
    }
    printf("\n");
}