//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char name[30];

    printf("Welcome to the Automated Fortune Teller Program\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    srand(time(NULL)); //initializing random number generator

    int fortune_number = rand() % 5 + 1; //generating random number between 1-5

    printf("\n\nHello %s, your fortune for the day is: \n\n", name);

    switch(fortune_number)
    {
        case 1:
            printf("You will have a peaceful day, with no worries or concerns.\n");
            break;
        case 2:
            printf("You will experience a significant positive change in your life today.\n");
            break;
        case 3:
            printf("Your hard work and persistence will pay off in your current project.\n");
            break;
        case 4:
            printf("You will encounter a minor obstacle today, but it will be easily overcome.\n");
            break;
        case 5:
            printf("You will receive unexpected good news in the near future.\n");
            break;
        default:
            printf("Oops, something went wrong. Please try again later.\n");
    }

    return 0;
}