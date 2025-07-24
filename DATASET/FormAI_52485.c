//FormAI DATASET v1.0 Category: Poker Game ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    char *suits[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    char *faces[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

    int deck[52];

    for(int i = 0; i < 52; i++)
    {
        deck[i] = i;
    }

    for(int i = 0; i < 52; i++)
    {
        int rnd = rand() % 52;

        int temp = deck[i];
        deck[i] = deck[rnd];
        deck[rnd] = temp;
    }

    printf("Welcome to the Surrealist Poker Game!\n\n");

    printf("The dealer has dealt you the following cards:\n");

    for(int i = 0; i < 5; i++)
    {
        int card = deck[i];
        int faceValue = card % 13;
        int suitValue = card / 13;

        printf("[%s of %s]\n", faces[faceValue], suits[suitValue]);
    }

    printf("\nHow surreal are you feeling today?\n");

    int surrealLevel = 0;
    scanf("%d", &surrealLevel);

    if(surrealLevel < 0)
    {
        surrealLevel = 0;
    }
    else if(surrealLevel > 10)
    {
        surrealLevel = 10;
    }

    printf("\nYour surreal level is %d\n\n", surrealLevel);

    printf("Please choose which cards to keep:\n");

    int cardsToKeep[5] = {0};

    for(int i = 0; i < 5; i++)
    {
        printf("[%d] [%s of %s]\n", i + 1, faces[deck[i] % 13], suits[deck[i] / 13]);
        printf("Keep this card? (1 = yes, 0 = no)\n");

        scanf("%d", &cardsToKeep[i]);
    }

    for(int i = 0; i < 5; i++)
    {
        if(cardsToKeep[i] != 1)
        {
            int card = deck[i];
            int faceValue = card % 13;
            int suitValue = card / 13;

            deck[i] = deck[i + 5 - surrealLevel];

            printf("You discarded the [%s of %s]\n", faces[faceValue], suits[suitValue]);
        }
    }

    for(int i = 0; i < surrealLevel; i++)
    {
        int card = deck[5 + i];
        int faceValue = card % 13;
        int suitValue = card / 13;

        printf("You drew the [%s of %s]\n", faces[faceValue], suits[suitValue]);
    }

    printf("\nYou now have the following cards:\n");

    for(int i = 0; i < 5; i++)
    {
        int card = deck[i];
        int faceValue = card % 13;
        int suitValue = card / 13;

        printf("[%s of %s]\n", faces[faceValue], suits[suitValue]);
    }

    printf("\nLet's see what you've got!\n");

    int hand[5] = {0};

    for(int i = 0; i < 5; i++)
    {
        hand[i] = deck[i] % 13;
    }

    int straight = 0;
    int flush = 0;
    int pairs = 0;

    for(int i = 0; i < 5; i++)
    {
        int count = 0;

        for(int j = 0; j < 5; j++)
        {
            if(hand[i] == hand[j])
            {
                count++;
            }
        }

        if(count > 1)
        {
            pairs++;
        }

        if(i < 4)
        {
            if(hand[i] + 1 == hand[i + 1])
            {
                straight++;
            }
        }

        if(i == 4 && hand[i] == 12 && hand[0] == 0)
        {
            straight++;
        }
    }

    for(int i = 0; i < 4; i++)
    {
        int count = 0;

        for(int j = 0; j < 5; j++)
        {
            if(deck[j] / 13 == i)
            {
                count++;
            }
        }

        if(count == 5)
        {
            flush++;
        }
    }

    if(straight == 4 && flush == 0)
    {
        printf("You have a straight!\n");
    }
    else if(straight == 4 && flush == 1)
    {
        printf("You have a straight flush!\n");
    }
    else if(straight == 0 && flush == 1)
    {
        printf("You have a flush!\n");
    }
    else if(pairs == 1)
    {
        printf("You have one pair!\n");
    }
    else if(pairs == 2)
    {
        printf("You have two pairs!\n");
    }
    else if(pairs == 3)
    {
        printf("You have three of a kind!\n");
    }
    else if(straight == 4 && flush == 1)
    {
        printf("You have a straight flush!\n");
    }
    else if(pairs == 4)
    {
        printf("You have four of a kind!\n");
    }
    else
    {
        printf("You have a high card!\n");
    }

    printf("\nThe game has ended. Thank you for playing the Surrealist Poker Game!\n");

    return 0;
}