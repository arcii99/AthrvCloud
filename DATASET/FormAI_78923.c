//FormAI DATASET v1.0 Category: Poker Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CARDS 52
#define FACES 13

void shuffle(unsigned int wDeck[][FACES]);
void deal(const unsigned int wDeck[][FACES], const char *wFace[], const char *wSuit[]);

int main(void)
{
    unsigned int deck[CARDS][FACES] = {0};
    const char *face[FACES] = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    const char *suit[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};

    srand(time(0));
    shuffle(deck);
    deal(deck, face, suit);

    return 0;
}

void shuffle(unsigned int wDeck[][FACES])
{
    for (size_t card = 1; card <= CARDS; ++card)
    {
        size_t row;
        size_t column;

        do
        {
            row = rand() % 4;
            column = rand() % 13;

        } while(wDeck[row][column] != 0);

        wDeck[row][column] = card;
    }
}

void deal(const unsigned int wDeck[][FACES], const char *wFace[], const char *wSuit[])
{
    for (size_t card = 1; card <= CARDS; ++card)
    {
        for (size_t row = 0; row < 4; ++row)
        {
            for (size_t column = 0; column < 13; ++column)
            {
                if (wDeck[row][column] == card)
                {
                    printf("%5s of %-8s%c", wFace[column], wSuit[row], card % 2 == 0 ? '\n' : '\t');
                }
            }
        }
    }
}