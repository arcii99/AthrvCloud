//FormAI DATASET v1.0 Category: Memory Game ; Style: lively
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define NUM_OF_CARDS 16
#define NUM_OF_PAIRS 8

void shuffle(int cards[], int numCards);
void displayCards(int cards[], int flipped[]);
int getCard(int cards[], int flipped[]);
int isMatch(int cards[], int flipped[]);
int getChoice();

int main()
{
    int cards[NUM_OF_CARDS], flipped[NUM_OF_CARDS] = {0};
    int firstCard, secondCard, matches = 0;

    srand(time(0));

    for (int i = 0; i < NUM_OF_CARDS / 2; i++)
    {
        cards[i] = i + 1;
        cards[i + NUM_OF_PAIRS] = i + 1;
    }

    shuffle(cards, NUM_OF_CARDS);

    printf("Welcome to the C Memory Game!\n\n");

    while (matches < NUM_OF_PAIRS)
    {
        displayCards(cards, flipped);

        firstCard = getCard(cards, flipped);
        flipped[firstCard] = 1;

        displayCards(cards, flipped);

        secondCard = getCard(cards, flipped);
        flipped[secondCard] = 1;

        if (isMatch(cards, flipped))
        {
            printf("\nMATCH FOUND!\n\n");
            matches++;
        }
        else
        {
            flipped[firstCard] = 0;
            flipped[secondCard] = 0;
            printf("\nNO MATCH!\n\n");
        }

        // pause for 1 second to allow player to see cards
        clock_t start = clock();
        while (clock() < start + CLOCKS_PER_SEC);
    }

    printf("Congratulations, you matched all the pairs!\n");

    return 0;
}

void shuffle(int cards[], int numCards)
{
    for (int i = 0; i < NUM_OF_CARDS; i++)
    {
        int temp = cards[i];
        int rnd = rand() % NUM_OF_CARDS;
        cards[i] = cards[rnd];
        cards[rnd] = temp;
    }
}

void displayCards(int cards[], int flipped[])
{
    printf("         Memory Game\n");
    printf("------------------------------\n");

    for (int i = 0; i < NUM_OF_CARDS; i++)
    {
        if (flipped[i])
        {
            printf("%3d ", cards[i]);
        }
        else
        {
            printf("%3c ", '*');
        }

        if ((i + 1) % 4 == 0)
        {
            printf("\n");
        }
    }
}

int getCard(int cards[], int flipped[])
{
    int card = getChoice() - 1;

    while (flipped[card])
    {
        printf("That card is already flipped.\n");
        card = getChoice() - 1;
    }

    return card;
}

int isMatch(int cards[], int flipped[])
{
    for (int i = 0; i < NUM_OF_CARDS; i++)
    {
        if (flipped[i])
        {
            for (int j = i + 1; j < NUM_OF_CARDS; j++)
            {
                if (flipped[j] && cards[i] == cards[j])
                {
                    return 1;
                }
            }
        }
    }

    return 0;
}

int getChoice()
{
    int choice;

    printf("Enter card number (1-16): ");
    scanf("%d", &choice);

    while (choice < 1 || choice > 16)
    {
        printf("Invalid choice. Enter card number (1-16): ");
        scanf("%d", &choice);
    }

    return choice;
}