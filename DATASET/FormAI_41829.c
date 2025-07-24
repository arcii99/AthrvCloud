//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
    int fortune = rand() % 7;

    printf("Welcome to the Automated Fortune Teller program!\n\n");
    
    
    switch (fortune)
    {
        case 0:
            printf("You will have a great day today!\n");
            break;
        case 1:
            printf("You will meet someone special soon.\n");
            break;
        case 2:
            printf("Your hard work will pay off in the near future.\n");
            break;
        case 3:
            printf("A disappointment will turn into an opportunity.\n");
            break;
        case 4:
            printf("You will come into money soon.\n");
            break;
        case 5:
            printf("A friend will provide you with some valuable advice.\n");
            break;
        case 6:
            printf("Try something new today. It will lead to growth.\n");
            break;
        default:
            printf("Error. Please try again later.\n");
            break;
    }

    printf("\nThank you for using the Automated Fortune Teller program. Goodbye!\n");

    return 0;
}