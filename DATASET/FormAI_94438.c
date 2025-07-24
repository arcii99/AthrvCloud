//FormAI DATASET v1.0 Category: Random ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the Random Number Generator!\n\n");

    int range, num;
    printf("Enter the range of numbers you want to generate: ");
    scanf("%d", &range);

    printf("How many numbers do you want to generate: ");
    scanf("%d", &num);

    // Initialize the random seed
    srand(time(0));

    // Generate the random numbers
    for(int i=1;i<=num;i++)
    {
        int random_number = rand() % range + 1;
        printf("%d   ", random_number);
    }

    printf("\n\nThank you for using the Random Number Generator!\n");

    return 0;
}