//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the Automated Fortune Teller by Linus Torvalds!\n\n");

    srand(time(NULL));

    int fortune = rand() % 5;

    switch(fortune)
    {
        case 0:
            printf("You will achieve great success in your career!\n");
            break;
        case 1:
            printf("Love is in store for you in the near future!\n");
            break;
        case 2:
            printf("Be cautious of those around you, someone may be plotting against you.\n");
            break;
        case 3:
            printf("Your finances will soon experience a significant growth.\n");
            break;
        case 4:
            printf("You will soon embark on a great adventure that will change your life!\n");
            break;
        default:
            printf("Error: Invalid fortune generated. Try again later.\n");
    }

    return 0;
}