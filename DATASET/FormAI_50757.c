//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    // Initialize random seed
    srand(time(NULL));

    // Welcome message
    printf("Welcome to the Post-Apocalyptic Fortune Teller!\n");

    // Ask for user's name
    char name[20];
    printf("What is your name? ");
    scanf("%s", name);

    printf("\nHello, %s! Let's begin...\n\n", name);

    // Generate random number between 1 and 5
    int num = rand() % 5 + 1;

    // Use switch statement to display fortune
    switch(num)
    {
        case 1:
            printf("The future is bleak, %s. You will face many trials and hardships in the coming days.\n", name);
            break;
        case 2:
            printf("You have a chance for survival, %s. But it will not come easy.\n", name);
            break;
        case 3:
            printf("Beware of those around you, %s. Not everyone has your best interests at heart.\n", name);
            break;
        case 4:
            printf("There is hope for you yet, %s. Keep pushing forward and never give up.\n", name);
            break;
        case 5:
            printf("Your path is yours to choose, %s. But be warned, every decision has consequences.\n", name);
            break;
        default:
            printf("Error: Something went wrong.\n");
    }

    return 0;
}