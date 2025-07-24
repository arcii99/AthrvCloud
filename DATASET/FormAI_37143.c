//FormAI DATASET v1.0 Category: Memory Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int arr[], int n)
{
    // shuffle the array using Fisher-Yates algorithm
    for (int i = n - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main()
{
    printf("Welcome to the Happy Memory Game!\n\n");

    // initialize the game board
    int board[16] = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8};

    // shuffle the cards
    srand(time(NULL));
    shuffle(board, 16);

    // initialize the game variables
    int score = 0;
    int first_card = -1, second_card = -1;

    while (score < 8)
    {
        // print the game board
        printf("Current Board: ");
        for (int i = 0; i < 16; i++)
        {
            if (board[i] == -1)
            {
                printf("* ");
            }
            else
            {
                printf("%d ", board[i]);
            }
        }
        printf("\n");

        // get the user's input
        int choice;
        printf("Choose a card (1-16): ");
        scanf("%d", &choice);

        // check if the card is already flipped
        if (board[choice - 1] == -1)
        {
            printf("Sorry, that card is already flipped!\n\n");
            continue;
        }

        // flip the card
        int value = board[choice - 1];
        board[choice - 1] = -1;

        // check if it's the first or second card
        if (first_card == -1)
        {
            first_card = value;
        }
        else
        {
            second_card = value;
            // check if the cards match
            if (first_card == second_card)
            {
                printf("Congratulations! You found a match!\n\n");
                score++;
                first_card = -1;
                second_card = -1;
            }
            else
            {
                printf("Sorry, those cards don't match!\n\n");
                // unflip the cards
                for (int i = 0; i < 16; i++)
                {
                    if (board[i] == -1)
                    {
                        board[i] = 0;
                    }
                }
                board[choice - 1] = value;
                board[first_card - 1] = first_card;
                first_card = -1;
                second_card = -1;
            }
        }
    }

    printf("Congratulations! You won the game with a score of %d!", score);

    return 0;
}