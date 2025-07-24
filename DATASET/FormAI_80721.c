//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // seed the random number generator with the current time

    int fortune = rand() % 5; // generate a random number between 0 and 4 (inclusive)

    printf("Welcome to the Automated Fortune Teller!\n");

    switch (fortune)
    {
        case 0:
            printf("Your future looks bright!\n");
            break;
        case 1:
            printf("You will face some challenges, but you will overcome them.\n");
            break;
        case 2:
            printf("Your love life will flourish in the near future.\n");
            break;
        case 3:
            printf("You will receive some unexpected news, but it will ultimately be positive.\n");
            break;
        case 4:
            printf("Beware of making impulsive decisions, they may lead to regret.\n");
            break;
        default:
            printf("Error: Something went wrong in the fortune-telling process.\n");
            break;
    }

    return 0;
}