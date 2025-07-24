//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int numbers[75];
    int count = 0;
    int random;
    srand(time(NULL)); // Seed the random number generator

    // Generate 75 random numbers between 1 and 75
    for (int i = 1; i <= 75; i++)
    {
        numbers[count++] = i;
    }

    // Shuffle the numbers
    for (int i = 0; i < 75; i++)
    {
        random = rand() % 75;
        int temp = numbers[i];
        numbers[i] = numbers[random];
        numbers[random] = temp;
    }

    // Print the shuffled numbers (BINGO card)
    printf(" B  I  N  G  O\n");
    printf("================\n");
    for (int i = 0; i < 5; i++)
    {
        printf("|%2d ", numbers[i]);
    }
    printf("|\n");
    for (int i = 5; i < 10; i++)
    {
        printf("|%2d ", numbers[i]);
    }
    printf("|\n");
    printf("| %2d | %2d | %2d | %2d | %2d |\n", numbers[10], numbers[11], numbers[12], numbers[13], numbers[14]);
    for (int i = 15; i < 20; i++)
    {
        printf("|%2d ", numbers[i]);
    }
    printf("|\n");
    for (int i = 20; i < 25; i++)
    {
        printf("|%2d ", numbers[i]);
    }
    printf("|\n");
    printf("================\n");

    return 0;
}