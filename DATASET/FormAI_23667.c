//FormAI DATASET v1.0 Category: Poker Game ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    char suits[4][9] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    char faces[13][6] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    int deck[52];
    int player_hand[5], computer_hand[5];
    int player_sum = 0, computer_sum = 0;
    int i, j, k, m, n, p, q, r, s;

    srand(time(NULL));

    //initialize the deck
    for(i = 0; i < 52; i++)
    {
        deck[i] = i;
    }

    //shuffle the deck
    for(i = 0; i < 52; i++)
    {
        j = rand() % 52;
        k = deck[i];
        deck[i] = deck[j];
        deck[j] = k;
    }

    //deal the cards
    for(i = 0; i < 5; i++)
    {
        player_hand[i] = deck[i];
        computer_hand[i] = deck[i + 5];
    }

    //display the initial hands
    printf("Your hand: ");
    for(i = 0; i < 5; i++)
    {
        printf("%s of %s, ", faces[player_hand[i] % 13], suits[player_hand[i] / 13]);
        player_sum += (player_hand[i] % 13) + 1;
    }
    printf("\n");

    printf("Computer's hand: ");
    for(i = 0; i < 5; i++)
    {
        printf("?, ");
    }
    printf("\n");

    //let the player discard and draw new cards
    printf("How many cards do you want to discard? ");
    scanf("%d", &m);

    if(m > 0)
    {
        printf("Which cards do you want to discard? (enter the position number)\n");
        for(n = 0; n < m; n++)
        {
            scanf("%d", &p);
            player_hand[p-1] = deck[n + 10];
        }
        printf("Your new hand: ");
        for(i = 0; i < 5; i++)
        {
            printf("%s of %s, ", faces[player_hand[i] % 13], suits[player_hand[i] / 13]);
            player_sum += (player_hand[i] % 13) + 1;
        }
        printf("\n");
    }

    //computer's turn
    printf("Computer's turn:\n");

    for(q = 0; q < 3; q++)
    {
        for(r = 0; r < 5; r++)
        {
            if(computer_hand[r] == -1)
            {
                continue;
            }
            else
            {
                computer_sum += (computer_hand[r] % 13) + 1;
            }
        }

        if(computer_sum < 20)
        {
            for(s = 0; s < 5; s++)
            {
                if(computer_hand[s] != -1)
                {
                    computer_hand[s] = deck[q + 15];
                    break;
                }
            }
        }
        else
        {
            break;
        }
    }

    printf("Computer's new hand: ");
    for(i = 0; i < 5; i++)
    {
        printf("%s of %s, ", faces[computer_hand[i] % 13], suits[computer_hand[i] / 13]);
    }
    printf("\n");

    //determine the winner
    if((player_sum > computer_sum && player_sum <= 21) || (computer_sum > 21 && player_sum <= 21))
    {
        printf("Congratulations! You win!\n");
    }
    else if(player_sum == computer_sum && player_sum <= 21)
    {
        printf("It's a tie!\n");
    }
    else
    {
        printf("Sorry, you lose!\n");
    }

    return 0;
}