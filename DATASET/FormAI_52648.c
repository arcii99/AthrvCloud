//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Prompt user for input
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Enter your name: ");
    char name[20];
    scanf("%s", name);

    // Generate random number for fortune
    srand(time(NULL));
    int fortune_num = rand() % 5;

    // Assign fortune based on number generated
    char fortune[200];
    if (fortune_num == 0)
    {
        sprintf(fortune, "%s, you will find great success in your future endeavors!", name);
    }
    else if (fortune_num == 1)
    {
        sprintf(fortune, "%s, love is in your near future!", name);
    }
    else if (fortune_num == 2)
    {
        sprintf(fortune, "%s, a large sum of money is coming your way!", name);
    }
    else if (fortune_num == 3)
    {
        sprintf(fortune, "%s, you will encounter a life-changing opportunity soon!", name);
    }
    else if (fortune_num == 4)
    {
        sprintf(fortune, "%s, be prepared for a big change in your life!", name);
    }

    // Print fortune to user
    printf("\nYour fortune is...\n");
    printf("%s\n", fortune);

    return 0;
}