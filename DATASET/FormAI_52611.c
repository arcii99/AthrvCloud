//FormAI DATASET v1.0 Category: System boot optimizer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int boot_time;
    srand(time(0)); //Seed random number generator with current time
    
    printf("Enter the current boot time of your system in seconds: ");
    scanf("%d", &boot_time);
    
    //Simulate a random boot time optimization
    int optimized_time = boot_time - (rand() % 20 + 1); //Randomly subtract 1-20 seconds
    
    printf("\nBoot time optimization complete!\n");
    printf("Original boot time: %d seconds\n", boot_time);
    printf("Optimized boot time: %d seconds\n", optimized_time);
    
    if(optimized_time < boot_time)
    {
        printf("\nCongratulations, your system is now optimized for faster boot times!\n");
    }
    else if(optimized_time == boot_time)
    {
        printf("\nYour system is already optimized for fast boot times.\n");
    }
    else
    {
        printf("\nSorry, boot time optimization failed. Please try again later.\n");
    }
    
    return 0;
}