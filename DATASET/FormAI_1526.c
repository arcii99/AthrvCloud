//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the Automated Fortune Teller! \n\n");
    printf("Think of a question and press enter to reveal your fortune... \n");
    getchar(); // Wait for user to press Enter
    
    // Seed the random number generator
    srand(time(NULL));
    
    // Generate random number between 1 and 5
    int random_num = rand() % 5 + 1;
    
    // Interpret the result of the random number
    switch(random_num)
    {
        case 1:
            printf("Your future looks bright. Expect good news!\n");
            break;
        case 2:
            printf("You will face challenges ahead, but you have the strength to overcome them!\n");
            break;
        case 3:
            printf("Be careful in your financial dealings. Double check everything before making any big decisions.\n");
            break;
        case 4:
            printf("This is a good time for new relationships and friendships to blossom. Open yourself up to new experiences and people.\n");
            break;
        case 5:
            printf("Your hard work will finally pay off. Congratulations on your success!\n");
            break;
        default:
            printf("Hmm, something seems to have gone wrong. Please try again later.\n");
            break;
    }
    
    return 0;
}