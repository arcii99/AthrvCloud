//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    printf("Welcome to the Automated Fortune Teller Program\n\n");

    int num = rand() % 5; // generate random number between 0-4
    
    switch(num) {
        case 0:
            printf("Your future looks bright! You will have great success in your career.\n");
            break;
        case 1:
            printf("Be careful of those around you, someone may have ulterior motives.\n");
            break;
        case 2:
            printf("You will meet the love of your life soon, keep your heart open.\n");
            break;
        case 3:
            printf("Take caution in your financial decisions, avoid risky investments.\n");
            break;
        case 4:
            printf("Your health will improve in the near future, keep taking care of yourself.\n");
            break;
        default:
            printf("Error: Invalid number generated.\n");
            break;
    }

    return 0;
}