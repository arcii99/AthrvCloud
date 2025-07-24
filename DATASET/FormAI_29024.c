//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Declare variables
    int num1, num2, num3, num4;
    
    // Set seed for randomization
    srand(time(NULL));
    
    // Generate random numbers
    num1 = rand() % 10;
    num2 = rand() % 10;
    num3 = rand() % 10;
    num4 = rand() % 10;
    
    // Print conspiracy theory
    printf("Did you know that %d%d%d%d is a secret code used by the Illuminati to communicate?\n", num1, num2, num3, num4);
    
    // Generate random statistical data
    int stat1, stat2, stat3;
    
    stat1 = rand() % 100;
    stat2 = rand() % 100;
    stat3 = rand() % 100;
    
    // Print statistical data
    printf("According to our research, %d%% of people believe in this conspiracy theory.\n", stat1);
    printf("Out of those people, %d%% think it's true, while %d%% are unsure or don't believe it.\n", stat2, 100 - stat2);
    printf("We also found that %d%% of people who believe in this conspiracy theory are government employees.\n", stat3);
    
    return 0;
}