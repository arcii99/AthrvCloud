//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main()
{
    printf("--- Automated Fortune Teller ---\n\n");
    printf("Think of a question and press enter to continue...\n\n");
    getchar();
    
    srand(time(NULL)); // Seed the random number generator
    
    int fortune = rand() % 5; // Generate a random number between 0-4
    
    switch(fortune)
    {
        case 0:
            printf("Your future looks bright!\n");
            break;
            
        case 1:
            printf("You will face challenges, but you will overcome them.\n");
            break;
            
        case 2:
            printf("Be cautious in the near future, it may be wise to hold back.\n");
            break;
            
        case 3:
            printf("A great opportunity is on the horizon, keep your eyes open!\n");
            break;
            
        case 4:
            printf("Love may be in your future, keep an open heart.\n");
            break;
            
        default:
            printf("Uh-oh, something went wrong...\n");
            break;
    }
    
    return 0;
}