//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Declare variables
    int fortune;
    char name[20];

    // Get user's name
    printf("Hello there! What's your name?\n");
    scanf("%19s", name);

    // Seed random number generator
    srand(time(NULL));

    // Generate random fortune
    fortune = rand() % 6;

    // Display fortune based on random number generated
    switch(fortune)
    {
        case 0:
            printf("%s, you will have a great day today!\n", name);
            break;
        case 1:
            printf("%s, you will meet someone important to your life.\n", name);
            break;
        case 2:
            printf("%s, you will be blessed with financial abundance.\n", name);
            break;
        case 3:
            printf("%s, you will overcome a difficult obstacle in your life.\n", name);
            break;
        case 4:
            printf("%s, you will travel to a new and exciting place.\n", name);
            break;
        case 5:
            printf("%s, you will find inner peace and happiness.\n", name);
            break;
    }

    // Goodbye
    printf("\nThank you for using the automated fortune teller. Have a great day!\n");

    return 0;
}