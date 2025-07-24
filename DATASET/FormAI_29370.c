//FormAI DATASET v1.0 Category: Memory Game ; Style: brave
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ROWS 4
#define COLS 4
#define CARD_COUNT (ROWS * COLS) / 2

int main()
{
    int cards[CARD_COUNT * 2], flipped[CARD_COUNT * 2], count = 0, guesses = 0, flipped_count = 0, matched_count = 0;
    char board[ROWS][COLS], sym;
    srand(time(NULL));

    // populate cards array with random numbers
    for (int i = 0; i < CARD_COUNT * 2; i++)
    {
        cards[i] = rand() % (CARD_COUNT) + 1;
    }

    // shuffle cards array
    for (int i = 0; i < CARD_COUNT * 2; i++)
    {
        int temp = cards[i];
        int random_index = rand() % (CARD_COUNT * 2);
        cards[i] = cards[random_index];
        cards[random_index] = temp;
    }

    // create board
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            board[i][j] = 'X';
        }
    }

    while (matched_count < CARD_COUNT)
    {
        // print board
        printf("Guesses: %d\n", guesses);
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }

        // get guess from user
        int guess;
        printf("Enter row and column: ");
        scanf("%d %d", &guess, &guess);
        int row = guess / COLS;
        int col = guess % COLS;

        if (board[row][col] == 'X')
        {
            board[row][col] = cards[guess];
            flipped[flipped_count++] = guess;

            if (flipped_count == 2)
            {
                int index1 = flipped[0];
                int index2 = flipped[1];

                if (cards[index1] == cards[index2])
                {
                    printf("Match found!\n");
                    matched_count++;
                }
                else
                {
                    printf("No match found.\n");
                    board[index1 / COLS][index1 % COLS] = 'X';
                    board[index2 / COLS][index2 % COLS] = 'X';
                }

                flipped_count = 0;
                guesses++;
            }
        }
    }

    printf("Congratulations! You won the game with %d guesses!", guesses);

    return 0;
}