//FormAI DATASET v1.0 Category: Random ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num, i, j;
    srand(time(0)); // initializing random seed

    printf("How many random numbers do you want to generate? \n");
    scanf("%d", &num);

    printf("Generating %d random numbers: \n", num);

    for (i = 0; i < num; i++)
    {
        j = rand(); // generate random number
        printf("%d\n", j);
    }

    printf("Random number generation complete. \n");

    return 0;
}