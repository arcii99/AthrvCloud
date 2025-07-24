//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 25

int main()
{
    int bingo[SIZE];
    int numbers[SIZE];
    int used[SIZE];
    int cnt = 0;
    int num, row, col;
    int i, j;
    time_t t;

    /* Initialize arrays */
    for(i = 0; i < SIZE; i++)
    {
        bingo[i] = 0;
        used[i] = 0;
        numbers[i] = i+1;
    }

    /* Seed the random number generator */
    srand((unsigned) time(&t));

    /* Shuffle the numbers array */
    for(i = SIZE-1; i >= 0; i--)
    {
        j = rand() % (i+1);
        num = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = num;
    }

    while(cnt < SIZE)
    {
        /* Print current state of the bingo card */
        printf("   B  I  N  G  O\n");
        for(i = 0; i < 5; i++)
        {
            printf("%2d ", numbers[i*5+0]);
            printf("%2d ", numbers[i*5+1]);
            printf("%2d ", numbers[i*5+2]);
            printf("%2d ", numbers[i*5+3]);
            printf("%2d\n", numbers[i*5+4]);
        }
        printf("\n");

        /* Get a random number */
        num = 1 + rand() % SIZE;

        /* Check if number has already been used */
        if(used[num-1] == 1)
        {
            continue;
        }

        /* Mark the number as used */
        used[num-1] = 1;

        /* Find the row and column of the number */
        if(num <= 5)
        {
            row = 0;
            col = num-1;
        }
        else if(num <= 10)
        {
            row = 1;
            col = num-6;
        }
        else if(num <= 15)
        {
            row = 2;
            col = num-11;
        }
        else if(num <= 20)
        {
            row = 3;
            col = num-16;
        }
        else
        {
            row = 4;
            col = num-21;
        }

        /* Mark the number on the bingo card */
        bingo[row*5+col] = 1;

        /* Check for a bingo */
        if(row == col)
        {
            for(i = 0; i < 5; i++)
            {
                if(bingo[i*5+i] != 1)
                {
                    break;
                }
                if(i == 4)
                {
                    printf("BINGO!\n");
                    return 0;
                }
            }
        }

        if(row == 4-col)
        {
            for(i = 0; i < 5; i++)
            {
                if(bingo[i*5+4-i] != 1)
                {
                    break;
                }
                if(i == 4)
                {
                    printf("BINGO!\n");
                    return 0;
                }
            }
        }

        for(i = 0; i < 5; i++)
        {
            for(j = 0; j < 5; j++)
            {
                if(bingo[i*5+j] != 1)
                {
                    break;
                }
            }
            if(j == 5)
            {
                printf("BINGO!\n");
                return 0;
            }
        }

        for(i = 0; i < 5; i++)
        {
            for(j = 0; j < 5; j++)
            {
                if(bingo[j*5+i] != 1)
                {
                    break;
                }
            }
            if(j == 5)
            {
                printf("BINGO!\n");
                return 0;
            }
        }

        cnt++;
    }

    /* Print final state of the bingo card */
    printf("   B  I  N  G  O\n");
    for(i = 0; i < 5; i++)
    {
        printf("%2d ", numbers[i*5+0]);
        printf("%2d ", numbers[i*5+1]);
        printf("%2d ", numbers[i*5+2]);
        printf("%2d ", numbers[i*5+3]);
        printf("%2d\n", numbers[i*5+4]);
    }
    printf("\n");

    printf("No more numbers, no bingo.\n");

    return 0;
}