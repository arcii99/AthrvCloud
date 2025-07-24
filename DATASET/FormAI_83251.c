//FormAI DATASET v1.0 Category: Poker Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct card
{
    char suit;
    char rank[3];
}Card;

// Function to create deck
void createDeck(Card deck[])
{
    char suits[] = {'S', 'H', 'D', 'C'};
    char ranks[][3] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    int i, j, k = 0;
    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 13; j++)
        {
            deck[k].suit = suits[i];
            strcpy(deck[k].rank, ranks[j]);
            k++;
        }
    }
}

// Function to display deck
void displayDeck(Card deck[])
{
    int i;
    printf("\n\nDeck:\n");
    for(i = 0; i < 52; i++)
    {
        printf("%c%s ", deck[i].suit, deck[i].rank);
        if(i % 13 == 12)
        {
            printf("\n");
        }
    }
    printf("\n");
}

// Function to shuffle deck
void shuffleDeck(Card deck[])
{
    srand(time(NULL));
    int i, j;
    Card temp;
    for(i = 0; i < 52; i++)
    {
        j = rand() % 52;
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Function to deal cards
void dealCards(Card deck[], Card player1[], Card player2[], Card table[])
{
    int i;
    for(i = 0; i < 2; i++)
    {
        player1[i] = deck[i];
        player2[i] = deck[i + 2];
    }
    for(i = 0; i < 5; i++)
    {
        table[i] = deck[i + 4];
    }
}

// Function to display cards
void displayCards(Card player[], char name[])
{
    int i;
    printf("\n\n%s's cards:\n", name);
    for(i = 0; i < 2; i++)
    {
        printf("%c%s ", player[i].suit, player[i].rank);
    }
    printf("\n");
}

// Function to display table cards
void displayTable(Card table[])
{
    int i;
    printf("\n\nTable cards:\n");
    for(i = 0; i < 5; i++)
    {
        printf("%c%s ", table[i].suit, table[i].rank);
    }
    printf("\n");
}

int main()
{
    Card deck[52];
    Card player1[2];
    Card player2[2];
    Card table[5];
    createDeck(deck);
    displayDeck(deck);
    shuffleDeck(deck);
    displayDeck(deck);
    dealCards(deck, player1, player2, table);
    displayCards(player1, "Player 1");
    displayCards(player2, "Player 2");
    displayTable(table);
    return 0;
}