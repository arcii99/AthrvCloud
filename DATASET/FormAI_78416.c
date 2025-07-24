//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the Automated Fortune Teller!\n");

    char name[20];
    printf("What's your name?\n");
    scanf("%s", name);

    printf("Hi %s, let's see what the cards have in store for you today!\n", name);

    srand(time(NULL));
    int fortune = rand() % 5 + 1;

    switch (fortune)
    {
        case 1:
            printf("Your future is looking bright! Expect great things to happen soon.\n");
            break;
        case 2:
            printf("Luck is on your side today! Take a chance and try something new.\n");
            break;
        case 3:
            printf("Be careful with your finances today. It's not a good day to make big purchases.\n");
            break;
        case 4:
            printf("Your hard work will pay off soon. Keep pushing forward!\n");
            break;
        case 5:
            printf("Your love life is about to get very interesting. Enjoy the ride!\n");
            break;
        default:
            printf("Oops, something went wrong. Try again later.\n");
    }

    printf("Thanks for trying the Automated Fortune Teller. Have a great day!\n");

    return 0;
}