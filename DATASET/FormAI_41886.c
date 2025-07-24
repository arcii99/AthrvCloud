//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printBingoCard(int card[5][5], char *name)
{
    printf("Bingo Card for %s:\n", name);
    printf("----------------------------------\n");
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i == 2 && j == 2)
            {
                printf("  F ");
            }
            else
            {
                printf("%4d", card[i][j]);
            }
        }
        printf("\n\n");
    }
    printf("----------------------------------\n");
}

int checkForBingo(int card[5][5])
{
    int count = 0;
    int isBingo = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (card[i][j] == -1)
            {
                count++;
            }
        }
        if (count == 5)
        {
            isBingo = 1;
            break;
        }
        count = 0;
    }
    count = 0;
    if (!isBingo)
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (card[j][i] == -1)
                {
                    count++;
                }
            }
            if (count == 5)
            {
                isBingo = 1;
                break;
            }
            count = 0;
        }
    }
    count = 0;
    if (!isBingo)
    {
        for (int i = 0; i < 5; i++)
        {
            if (card[i][i] == -1)
            {
                count++;
            }
        }
        if (count == 5)
        {
            isBingo = 1;
        }
    }
    count = 0;
    if (!isBingo)
    {
        for (int i = 0; i < 5; i++)
        {
            if (card[i][4-i] == -1)
            {
                count++;
            }
        }
        if (count == 5)
        {
            isBingo = 1;
        }
    }
    return isBingo;
}

int main()
{
    int card[5][5];
    char *names[10] = {"Alice", "Bob", "Charlie", "David", "Eva", "Frank", "Gloria", "Helen", "Iris", "John"};
    int nums[75];
    int numCount = 0;
    srand(time(NULL));

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i == 2 && j == 2)
            {
                card[i][j] = -1;
            }
            else
            {
                card[i][j] = -2;
            }
        }
    }

    do
    {
        int num;
        do
        {
            num = rand() % 75 + 1;
        } while (nums[numCount] == num);

        nums[numCount] = num;
        numCount++;
        printf("Next number: %d\n", num);

        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (card[i][j] == num)
                {
                    card[i][j] = -1;
                    break;
                }
            }
        }

        for (int i = 0; i < 10; i++)
        {
            if (checkForBingo(card))
            {
                printf("\nBingo! Winner: %s\n", names[i]);
                return 0;
            }
            else if (i == 9)
            {
                i = -1;
            }
            else
            {
                printf("No winner yet. Next turn: %s\n", names[i+1]);
            }
        }
        printf("\n");
    } while (1);

    return 0;
}