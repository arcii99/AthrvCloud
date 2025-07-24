//FormAI DATASET v1.0 Category: Poker Game ; Style: Alan Touring
// C Poker Game by a Turing-style Chatbot

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function Declarations
void shuffleDeck(int deck[]);
int drawCard(int deck[]);
int calculateHandValue(int hand[]);
void printHand(int hand[], int numCards);
void printCard(int card);
int determineWinner(int hand1[], int hand2[]);

// Main Function
int main()
{
    int deck[52] = {0}; // initialize deck of cards
    int player1Hand[5] = {0}; // initialize player 1's hand
    int player2Hand[5] = {0}; // initialize player 2's hand
    
    srand(time(NULL)); // seed random number generator
    
    shuffleDeck(deck); // shuffle deck
    
    // Deal cards to players
    for (int i=0; i<5; i++)
    {
        player1Hand[i] = drawCard(deck);
        player2Hand[i] = drawCard(deck);
    }
    
    // Print hands
    printf("Player 1's Hand:\n");
    printHand(player1Hand, 5);
    printf("\nPlayer 2's Hand:\n");
    printHand(player2Hand, 5);
    
    // Determine winner
    int winner = determineWinner(player1Hand, player2Hand);
    if (winner == 1)
        printf("\nPlayer 1 wins!");
    else if (winner == 2)
        printf("\nPlayer 2 wins!");
    else
        printf("\nIt's a tie!");
    
    return 0;
}

// Function Definitions
void shuffleDeck(int deck[])
{
    for (int i=0; i<52; i++)
        deck[i] = i+1; // assign cards to deck
    
    for (int i=0; i<52; i++) // fisher-yates shuffle algorithm
    {
        int j = rand() % 52;
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

int drawCard(int deck[])
{
    static int index = 0; // index of the next card to draw
    int card = deck[index];
    index++;
    return card;
}

int calculateHandValue(int hand[])
{
    int value = 0;
    int numAces = 0;
    
    for (int i=0; i<5; i++)
    {
        int cardRank = hand[i] % 13 + 1; // determine rank of card
        if (cardRank == 1) // if card is an ace
        {
            value += 11;
            numAces++;
        }
        else if (cardRank > 10) // if card is a face card
            value += 10;
        else
            value += cardRank;
    }
    
    // If value is over 21 and there are aces, change the value of the aces to 1
    while (value > 21 && numAces > 0)
    {
        value -= 10;
        numAces--;
    }
    
    return value;
}

void printHand(int hand[], int numCards)
{
    for (int i=0; i<numCards; i++)
    {
        printCard(hand[i]);
        printf(" ");
    }
    printf("\n");
}

void printCard(int card)
{
    int rank = card % 13 + 1;
    int suit = card / 13;
    
    switch (rank)
    {
        case 1:
            printf("A");
            break;
        case 11:
            printf("J");
            break;
        case 12:
            printf("Q");
            break;
        case 13:
            printf("K");
            break;
        default:
            printf("%d", rank);
            break;
    }
    
    switch (suit)
    {
        case 0:
            printf("♠");
            break;
        case 1:
            printf("❤");
            break;
        case 2:
            printf("♦");
            break;
        case 3:
            printf("♣");
            break;
        default:
            printf(" ");
            break;
    }
}

int determineWinner(int hand1[], int hand2[])
{
    int hand1Value = calculateHandValue(hand1);
    int hand2Value = calculateHandValue(hand2);
    
    if (hand1Value > 21 && hand2Value <= 21)
        return 2;
    else if (hand2Value > 21 && hand1Value <= 21)
        return 1;
    else if (hand1Value > hand2Value)
        return 1;
    else if (hand2Value > hand1Value)
        return 2;
    else
        return 0;
}