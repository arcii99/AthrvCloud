//FormAI DATASET v1.0 Category: Random ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, n;
    time_t t;

    srand((unsigned) time(&t));

    printf("Welcome to the Random Number Generator!\n");
    printf("----------------------------------------\n");
    printf("Please enter the number of random numbers you would like to generate: ");
    scanf("%d", &n);

    printf("\n");
    printf("Your random numbers are: \n");
    printf("----------------------------------------\n");
    for( i = 0 ; i < n ; i++ )
    {
        printf("%d\n", rand() % 1000 + 1);
    }
    printf("----------------------------------------\n");

    printf("Thank you for using the Random Number Generator!\n");

    return 0;
}