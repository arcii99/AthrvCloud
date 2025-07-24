//FormAI DATASET v1.0 Category: Poker Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to initialize deck
void createDeck(int deck[])
{
    for(int i = 0; i < 52; i++)
    {
        deck[i] = i + 1;
    }
}

// Function to shuffle deck
void shuffleDeck(int deck[])
{
    srand(time(NULL));
    for(int i = 0; i < 52; i++)
    {
        int j = rand() % 52;
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Function to print card value
void printCardValue(int value)
{
    int rank = value % 13;
    int suit = value / 13;
    char ranks[13][3] = {"Ace", "Two", "Three", "Four", "Five", "Six",
                        "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    char suits[4][10] = {"Spades", "Hearts", "Clubs", "Diamonds"};

    printf("%s of %s\n", ranks[rank], suits[suit]);
}

// Function to print player's hand
void printHand(int hand[], int numCards)
{
    for(int i = 0; i < numCards; i++)
    {
        printCardValue(hand[i]);
    }
}

// Function to evaluate hand strength
int evaluateHand(int hand[], int numCards)
{
    int rankCount[13] = {0};
    int suitCount[4] = {0};
    int pairCount = 0;
    int threeKind = 0;
    int fourKind = 0;
    int flush = 0;
    int straight = 0;

    for(int i = 0; i < numCards; i++)
    {
        int rank = hand[i] % 13;
        int suit = hand[i] / 13;
        rankCount[rank]++;
        suitCount[suit]++;
    }

    // Check for flush
    for(int i = 0; i < 4; i++)
    {
        if(suitCount[i] == numCards)
        {
            flush = 1;
            break;
        }
    }

    // Check for straight
    for(int i = 0; i < 9; i++)
    {
        if(rankCount[i] && rankCount[i+1] && rankCount[i+2] && rankCount[i+3] && rankCount[i+4])
        {
            straight = 1;
            break;
        }
    }
    // Check for pairs, three of a kind, four of a kind
    for(int i = 0; i < 13; i++)
    {
        if(rankCount[i] == 2)
        {
            pairCount++;
        }
        else if(rankCount[i] == 3)
        {
            threeKind = 1;
        }
        else if(rankCount[i] == 4)
        {
            fourKind = 1;
        }
    }

    // Evaluate hand strength
    if(flush && straight)
    {
        return 9;   // Straight Flush
    }
    else if(fourKind)
    {
        return 8;   // Four of a Kind
    }
    else if(threeKind && pairCount == 1)
    {
        return 7;   // Full House
    }
    else if(flush)
    {
        return 6;   // Flush
    }
    else if(straight)
    {
        return 5;   // Straight
    }
    else if(threeKind)
    {
        return 4;   // Three of a Kind
    }
    else if(pairCount == 2)
    {
        return 3;   // Two Pair
    }
    else if(pairCount == 1)
    {
        return 2;   // One Pair
    }
    else
    {
        return 1;   // High Card
    }
}

int main()
{
    int playerHand[5];
    int dealerHand[5];
    int deck[52];

    createDeck(deck);
    shuffleDeck(deck);

    // Deal player's hand
    for(int i = 0; i < 5; i++)
    {
        playerHand[i] = deck[i];
    }

    // Deal dealer's hand
    for(int i = 0; i < 5; i++)
    {
        dealerHand[i] = deck[i+5];
    }

    printf("Welcome to Poker Game!\n");
    printf("Your hand:\n");
    printHand(playerHand, 5);

    printf("\n\nDealer's hand:\n");
    printHand(dealerHand, 5);

    int playerStrength = evaluateHand(playerHand, 5);
    int dealerStrength = evaluateHand(dealerHand, 5);

    printf("\n\nYour hand strength: %d\n", playerStrength);
    printf("Dealer's hand strength: %d\n", dealerStrength);

    if(playerStrength > dealerStrength)
    {
        printf("\n\nCongratulations! You win!\n");
    }
    else if(playerStrength < dealerStrength)
    {
        printf("\n\nSorry, you lose. Better luck next time!\n");
    }
    else
    {
        printf("\n\nIt's a tie! Good game.\n");
    }

    return 0;
}