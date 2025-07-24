//FormAI DATASET v1.0 Category: Memory Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4

void shuffle(int arr[]);
void printBoard(int board[][SIZE], int revealed[]);

int main()
{
    int board[SIZE][SIZE] = {{0}};
    int revealed[SIZE * SIZE] = {0};
    int choices[2] = {0};
    int matches = 0;
    int moves = 0;

    // Set up board with pairs of numbers
    for (int i = 1; i <= SIZE * SIZE / 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            int row, col;
            do
            {
                row = rand() % SIZE;
                col = rand() % SIZE;
            } while (board[row][col] != 0);
            board[row][col] = i;
        }
    }

    shuffle(board[0]);

    printf("Welcome to the Memory Game!\n");
    printf("Find all matching pairs.\n\n");

    // Main game loop
    while (matches < SIZE * SIZE / 2)
    {
        printf("Moves: %d\n", moves);
        printBoard(board, revealed);

        printf("Enter two coordinates to reveal a box (e.g. 1 2): ");
        scanf("%d %d", &choices[0], &choices[1]);

        choices[0]--, choices[1]--;
        int idx = choices[0] * SIZE + choices[1];

        if (revealed[idx] == 1)
        {
            printf("That box is already revealed!\n\n");
            continue;
        }

        revealed[idx] = 1;
        printBoard(board, revealed);

        if (board[choices[0]][choices[1]] == 0)
        {
            printf("Oops, that's a bomb! Game over...\n");
            break;
        }

        if (matches % 2 == 1)
        {
            if (board[choices[0]][choices[1]] == board[choices[0]][choices[1] - 1])
            {
                printf("Match found!\n");
                matches++;
            }
            else
            {
                printf("Oops, try again.\n");
                revealed[idx] = 0;
                revealed[choices[0] * SIZE + choices[1] - 1] = 0;
            }
        }

        moves++;
    }

    printf("Congratulations, you found all the matches in %d moves!\n", moves);

    return 0;
}

void shuffle(int arr[])
{
    srand(time(NULL));
    for (int i = SIZE * SIZE - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void printBoard(int board[][SIZE], int revealed[])
{
    printf("\n  ");
    for (int i = 0; i < SIZE; i++)
        printf("%d ", i + 1);
    printf("\n");

    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", i + 1);
        for (int j = 0; j < SIZE; j++)
            printf("%c ", revealed[i * SIZE + j] ? (board[i][j] == 0 ? '*' : board[i][j] + '0') : '-');
        printf("\n");
    }
    printf("\n");
}