//FormAI DATASET v1.0 Category: Poker Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int deck[52];
int top_card = 0;

void shuffle()
{
    int i, j, temp;

    for (i = 0; i < 52; i++)
    {
        deck[i] = i;
    }

    for (i = 0; i < 52; i++)
    {
        j = rand() % 52;
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

int deal_card()
{
    int card;

    if (top_card == 52)
    {
        shuffle();
        top_card = 0;
    }

    card = deck[top_card];
    top_card++;

    return card;
}

void print_card(int card)
{
    char *ranks[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    char *suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};

    printf("%s of %s\n", ranks[card % 13], suits[card / 13]);
}

int main()
{
    int card1 = deal_card();
    int card2 = deal_card();

    printf("Your cards are:\n");
    print_card(card1);
    print_card(card2);

    return 0;
}