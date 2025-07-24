//FormAI DATASET v1.0 Category: Poker Game ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define card suits and face values
#define SPADES 0
#define HEARTS 1
#define CLUBS 2
#define DIAMONDS 3
#define ACE 1
#define JACK 11
#define QUEEN 12
#define KING 13

// function prototypes
int drawCard(int deck[]);
int evaluateHand(int hand[], int handSize);
void swap(int *a, int *b);
void shuffle(int deck[]);
void dealCards(int deck[], int numPlayers, int numCards, int playerHands[][numCards]);
void printCard(int card);
void printHand(int hand[], int handSize);
void bubbleSort(int hand[], int handSize);
void playRound(int deck[], int numPlayers, int numCards, int playerHands[][numCards], int scores[], int round);
void playGame(int numPlayers, int numCards);

// main function
int main()
{
    // seed the random number generator
    srand(time(NULL));
    
    // set the number of players and cards per hand
    int numPlayers = 3;
    int numCards = 5;
    
    // play the game
    playGame(numPlayers, numCards);
    
    return 0;
}

// function to draw a card from the deck
int drawCard(int deck[])
{
    static int index = 0; // static variable to keep track of deck position
    return deck[index++];
}

// function to evaluate a hand and return its score
int evaluateHand(int hand[], int handSize)
{
    int score = 0;
    int numAces = 0;
    
    // calculate the score of non-ace cards
    for (int i = 0; i < handSize; i++)
    {
        int cardValue = hand[i] % 13 + 1;
        if (cardValue >= 10)
        {
            score += 10;
        }
        else
        {
            score += cardValue;
        }
        
        if (cardValue == ACE)
        {
            numAces++;
        }
    }
    
    // calculate the score of aces (if any)
    for (int i = 0; i < numAces; i++)
    {
        if (score + 11 <= 21)
        {
            score += 11;
        }
        else
        {
            score += 1;
        }
    }
    
    return score;
}

// function to swap two integers
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// function to shuffle the deck
void shuffle(int deck[])
{
    for (int i = 0; i < 52; i++)
    {
        int j = rand() % 52;
        swap(&deck[i], &deck[j]);
    }
}

// function to deal cards to players
void dealCards(int deck[], int numPlayers, int numCards, int playerHands[][numCards])
{
    for (int i = 0; i < numCards; i++)
    {
        for (int j = 0; j < numPlayers; j++)
        {
            playerHands[j][i] = drawCard(deck);
        }
    }
}

// function to print a card in English
void printCard(int card)
{
    switch (card / 13)
    {
        case SPADES:
            printf("Spades ");
            break;
        case HEARTS:
            printf("Hearts ");
            break;
        case CLUBS:
            printf("Clubs ");
            break;
        case DIAMONDS:
            printf("Diamonds ");
            break;
    }
    
    int cardValue = card % 13 + 1;
    switch (cardValue)
    {
        case ACE:
            printf("Ace");
            break;
        case JACK:
            printf("Jack");
            break;
        case QUEEN:
            printf("Queen");
            break;
        case KING:
            printf("King");
            break;
        default:
            printf("%d", cardValue);
            break;
    }
}

// function to print a hand
void printHand(int hand[], int handSize)
{
    for (int i = 0; i < handSize; i++)
    {
        printCard(hand[i]);
        printf(" ");
    }
}

// function to sort a hand using bubble sort
void bubbleSort(int hand[], int handSize)
{
    for (int i = 0; i < handSize - 1; i++)
    {
        for (int j = 0; j < handSize - i - 1; j++)
        {
            if (hand[j] > hand[j + 1])
            {
                swap(&hand[j], &hand[j + 1]);
            }
        }
    }
}

// recursive function to play a round of the game
void playRound(int deck[], int numPlayers, int numCards, int playerHands[][numCards], int scores[], int round)
{
    printf("\nRound %d:\n", round);
    
    // shuffle the deck
    shuffle(deck);
    
    // deal cards to players
    dealCards(deck, numPlayers, numCards, playerHands);
    
    // print each player's hand and score
    for (int i = 0; i < numPlayers; i++)
    {
        printf("Player %d: ", i + 1);
        printHand(playerHands[i], numCards);
        bubbleSort(playerHands[i], numCards);
        scores[i] += evaluateHand(playerHands[i], numCards);
        printf("(%d points)\n", scores[i]);
    }
    
    // play another round if not all players have busted (exceeded 21 points)
    int numBusted = 0;
    for (int i = 0; i < numPlayers; i++)
    {
        if (scores[i] > 21)
        {
            numBusted++;
        }
    }
    if (numBusted < numPlayers)
    {
        playRound(deck, numPlayers, numCards, playerHands, scores, round + 1);
    }
}

// function to play the game
void playGame(int numPlayers, int numCards)
{
    printf("Welcome to C Poker Game!\n");
    printf("There are %d players, each dealt %d cards.\n", numPlayers, numCards);
    
    int deck[52];
    for (int i = 0; i < 52; i++)
    {
        deck[i] = i;
    }
    
    int playerHands[numPlayers][numCards];
    int scores[numPlayers];
    for (int i = 0; i < numPlayers; i++)
    {
        scores[i] = 0;
    }
    
    playRound(deck, numPlayers, numCards, playerHands, scores, 1);
    
    // determine the winner(s)
    int maxScore = 0;
    for (int i = 0; i < numPlayers; i++)
    {
        if (scores[i] <= 21 && scores[i] > maxScore)
        {
            maxScore = scores[i];
        }
    }
    printf("\nGame over.\n");
    printf("Final scores:\n");
    for (int i = 0; i < numPlayers; i++)
    {
        printf("Player %d: %d points\n", i + 1, scores[i]);
    }
    printf("Winner(s):\n");
    for (int i = 0; i < numPlayers; i++)
    {
        if (scores[i] == maxScore)
        {
            printf("Player %d\n", i + 1);
        }
    }
}