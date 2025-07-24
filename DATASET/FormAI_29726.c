//FormAI DATASET v1.0 Category: Poker Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FACES 13
#define SUITS 4
#define CARDS 52

void shuffle(int wDeck[][SUITS]);
void deal(const int wDeck[][SUITS], const char *wFace[], const char *wSuit[]);

int main(void)
{
    const char *suit[SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    const char *face[FACES] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven",
                            "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    int deck[FACES][SUITS] = {0};

    srand(time(NULL));

    shuffle(deck);
    deal(deck, face, suit);

    return 0;
}

void shuffle(int wDeck[][SUITS])
{
    int card, row, column;

    for (card = 1; card <= CARDS; card++)
    {
        do
        {
            row = rand() % FACES;
            column = rand() % SUITS;
        }
        while (wDeck[row][column] != 0);

        wDeck[row][column] = card;
    }
}

void deal(const int wDeck[][SUITS], const char *wFace[], const char *wSuit[])
{
    int card, row, column;

    for (card = 1; card <= CARDS; card++)
    {
        for (row = 0; row < FACES; row++)
        {
            for (column = 0; column < SUITS; column++)
            {
                if (wDeck[row][column] == card)
                {
                    printf("%s of %s\n", wFace[row], wSuit[column]);
                }
            }
        }
    }
}