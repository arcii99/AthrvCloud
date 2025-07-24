//FormAI DATASET v1.0 Category: Random ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num, i, j;
    int min = 1, max = 100;
    srand(time(NULL));  // Initializing random seed

    printf("Welcome to the Random number generator!\n");
    printf("How many random numbers would you like to generate? ");
    scanf("%d", &num);

    printf("Random numbers between %d and %d are:\n", min, max);
    for(i = 0; i < num; i++)
    {
        j = rand() % (max - min + 1) + min;  // Generating random number
        printf("%d\n", j);
    }

    printf("Thank you for using the Random number generator!\n");
    return 0;
}