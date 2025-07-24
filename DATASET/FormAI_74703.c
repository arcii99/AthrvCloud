//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the Automated Fortune Teller!\n\n");

    // Seed the random number generator with the current time
    srand(time(0));

    // Generate a random number between 1 and 5
    int fortune = rand() % 5 + 1;

    // Display the corresponding fortune depending on the random number generated
    switch (fortune)
    {
        case 1:
            printf("You will receive unexpected wealth in the near future.\n");
            break;
        case 2:
            printf("A journey you have been planning will be successful.\n");
            break;
        case 3:
            printf("You will find love in an unexpected place.\n");
            break;
        case 4:
            printf("A project or task you have been working on will be successful.\n");
            break;
        case 5:
            printf("You will overcome a difficult challenge and emerge stronger than ever.\n");
            break;
        default:
            printf("ERROR: Invalid fortune number generated.\n");
            break;
    }

    printf("\nThank you for using the Automated Fortune Teller!\n");

    return 0;
}