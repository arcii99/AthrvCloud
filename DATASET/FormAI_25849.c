//FormAI DATASET v1.0 Category: Random ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the random number generator program!\n\n");
    printf("Please enter a lower and upper bound for the range of numbers you want to generate.\n");

    int lower, upper;

    printf("\nEnter the lower bound: ");
    scanf("%d", &lower);

    printf("\nEnter the upper bound: ");
    scanf("%d", &upper);

    srand(time(0)); // Seed the random number generator with current time.

    printf("\nGenerating 10 random numbers in the range [%d, %d]:\n\n", lower, upper);

    for(int i=0;i<10;i++) {
        int random_num = (rand() % (upper - lower + 1)) + lower;
        printf("%d\n", random_num);
    }

    printf("\nThanks for using this program!\n");

    return 0;
}