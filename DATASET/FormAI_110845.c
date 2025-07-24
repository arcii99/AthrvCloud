//FormAI DATASET v1.0 Category: Poker Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to shuffle the deck of cards
void shuffle(int deck[])
{
    int i, j, temp;
    for (i = 51; i >= 0; i--)
    {
        j = rand() % (i + 1);
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Function to print the hand of cards
void printHand(int hand[])
{
    int i;
    for (i = 0; i < 5; i++)
    {
        int value = hand[i] % 13;
        int suit = hand[i] / 13;

        printf("%d of ", value + 2);
        switch (suit)
        {
        case 0:
            printf("Hearts\n");
            break;
        case 1:
            printf("Diamonds\n");
            break;
        case 2:
            printf("Clubs\n");
            break;
        case 3:
            printf("Spades\n");
            break;
        }
    }
}

// Function to determine the rank of the hand
int getRank(int hand[])
{
    int i, j;
    int flush = 1, straight = 1, pairs = 0;

    // Check for flush
    for (i = 1; i < 5; i++)
    {
        if (hand[i] / 13 != hand[0] / 13)
        {
            flush = 0;
            break;
        }
    }

    // Check for straight
    for (i = 1; i < 5; i++)
    {
        if (hand[i] % 13 != hand[i - 1] % 13 - 1)
        {
            if (i == 4 && hand[4] % 13 == 0 && hand[0] % 13 == 12)
            {
                continue;
            }
            straight = 0;
            break;
        }
    }

    // Check for pairs and three of a kind
    for (i = 0; i < 5; i++)
    {
        int count = 0;
        for (j = 0; j < 5; j++)
        {
            if (hand[i] % 13 == hand[j] % 13)
            {
                count++;
            }
        }
        if (count == 2)
        {
            pairs++;
        }
        else if (count == 3)
        {
            return 4;
        }
    }

    if (flush)
    {
        if (straight)
        {
            return 8; // Straight flush
        }
        else
        {
            return 5; // Flush
        }
    }
    else if (straight)
    {
        return 6; // Straight
    }
    else if (pairs == 1)
    {
        return 1; // One pair
    }
    else if (pairs == 2)
    {
        return 2; // Two pair
    }
    else if (pairs == 3)
    {
        return 7; // Full house
    }
    else if (pairs == 4)
    {
        return 3; // Four of a kind
    }
    else
    {
        return 0; // High card
    }
}

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Initialize the deck of cards
    int deck[52];
    int i;
    for (i = 0; i < 52; i++)
    {
        deck[i] = i;
    }

    // Shuffle the deck of cards
    shuffle(deck);

    // Deal the first hand of cards
    int hand1[5];
    for (i = 0; i < 5; i++)
    {
        hand1[i] = deck[i];
    }
    printf("Hand 1:\n");
    printHand(hand1);
    printf("\n");

    // Deal the second hand of cards
    int hand2[5];
    for (i = 0; i < 5; i++)
    {
        hand2[i] = deck[i + 5];
    }
    printf("Hand 2:\n");
    printHand(hand2);
    printf("\n");

    // Determine the rank of each hand
    printf("Hand 1 rank: %d\n", getRank(hand1));
    printf("Hand 2 rank: %d\n", getRank(hand2));
    printf("\n");

    // Determine the winner
    if (getRank(hand1) > getRank(hand2))
    {
        printf("Hand 1 wins!\n");
    }
    else if (getRank(hand1) < getRank(hand2))
    {
        printf("Hand 2 wins!\n");
    }
    else
    {
        printf("It's a tie!\n");
    }

    return 0;
}