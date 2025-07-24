//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char name[20];
    int lucky_number, fortune_number;

    // Getting user input
    printf("Please enter your name: ");
    scanf("%s", name);

    // Generating lucky number
    srand(time(NULL));
    lucky_number = rand() % 10 + 1;

    printf("\nHi %s, your lucky number is %d!\n", name, lucky_number);

    // Generating random fortune number
    fortune_number = rand() % 3 + 1;

    // Displaying fortune based on random fortune number
    switch (fortune_number)
    {
        case 1:
            printf("Your future is bright!\n");
            break;
        case 2:
            printf("You will face some challenges, but you will overcome them!\n");
            break;
        case 3:
            printf("Be cautious in your dealings. Your enemies are watching you.\n");
            break;
        default:
            printf("Error: Invalid fortune number.\n");
    }

    return 0;
}