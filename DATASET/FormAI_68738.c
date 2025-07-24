//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0)); // Seed the random number generator with current time

    int fortune_num = rand() % 7; // Generate a random number between 0 and 6
    // There are 7 fortune telling phrases in total

    printf("Welcome to the automated fortune teller program.\n");

    switch (fortune_num)
    {
        case 0:
            printf("Your future is a mystery, much like the mysteries I solve.\n");
            break;
        case 1:
            printf("The next chapter of your life holds great adventure and excitement.\n");
            break;
        case 2:
            printf("The universe is in your favor, luck is on your side.\n");
            break;
        case 3:
            printf("Be wary of those around you, for not everyone has your best interests at heart.\n");
            break;
        case 4:
            printf("The key to your success lies in your own hands.\n");
            break;
        case 5:
            printf("Beware of a dark haired woman, for she may bring trouble.\n");
            break;
        case 6:
            printf("The answer to your biggest problem lies in the details.\n");
            break;
        default: 
            printf("Hmm...something seems to have gone wrong. Try again later.\n");
            return 1; // Exit program with error
    }

    printf("Thank you for using the automated fortune teller program. May your future be bright and your mysteries be solved.\n");

    return 0; // Exit program without error
}