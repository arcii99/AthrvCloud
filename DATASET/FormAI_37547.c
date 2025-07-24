//FormAI DATASET v1.0 Category: Poker Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // Initialize random seed

    // Shuffle the deck
    char suits[] = {'C', 'D', 'H', 'S'};
    int values[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    int deck[52];
    for (int i = 0; i < 52; i++)
    {
        deck[i] = i;
    }
    for (int i = 0; i < 52; i++)
    {
        int j = rand() % 52;
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }

    // Deal the hands
    int player1[5], player2[5];
    for (int i = 0; i < 5; i++)
    {
        player1[i] = deck[i * 2];
        player2[i] = deck[i * 2 + 1];
    }

    // Evaluate the hands
    int p1score = 0, p2score = 0;
    int p1pairs = 0, p2pairs = 0, p1triples = 0, p2triples = 0;
    for (int i = 0; i < 5; i++)
    {
        if (values[player1[i] % 13] == 14)
        {
            p1score += 10;
        }
        else
        {
            p1score += values[player1[i] % 13];
        }
        for (int j = 0; j < 5; j++)
        {
            if (i != j && player1[i] % 13 == player1[j] % 13)
            {
                if (p1triples && player1[i] % 13 == p1triples)
                {
                    p1score += values[player1[i] % 13];
                }
                else if (p1pairs && player1[i] % 13 == p1pairs)
                {
                    p1score += 2 * values[player1[i] % 13];
                    p1triples = player1[i] % 13;
                }
                else
                {
                    p1score += values[player1[i] % 13];
                    p1pairs = player1[i] % 13;
                }
            }
        }
    }
    for (int i = 0; i < 5; i++)
    {
        if (values[player2[i] % 13] == 14)
        {
            p2score += 10;
        }
        else
        {
            p2score += values[player2[i] % 13];
        }
        for (int j = 0; j < 5; j++)
        {
            if (i != j && player2[i] % 13 == player2[j] % 13)
            {
                if (p2triples && player2[i] % 13 == p2triples)
                {
                    p2score += values[player2[i] % 13];
                }
                else if (p2pairs && player2[i] % 13 == p2pairs)
                {
                    p2score += 2 * values[player2[i] % 13];
                    p2triples = player2[i] % 13;
                }
                else
                {
                    p2score += values[player2[i] % 13];
                    p2pairs = player2[i] % 13;
                }
            }
        }
    }

    // Print the hands and scores
    printf("Player 1's hand: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d%c ", values[player1[i] % 13], suits[player1[i] / 13]);
    }
    printf("Score: %d\n", p1score);
    printf("Player 2's hand: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d%c ", values[player2[i] % 13], suits[player2[i] / 13]);
    }
    printf("Score: %d\n", p2score);

    // Determine the winner
    if (p1score > p2score)
    {
        printf("Player 1 wins!\n");
    }
    else if (p2score > p1score)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("It's a tie!\n");
    }

    return 0;
}