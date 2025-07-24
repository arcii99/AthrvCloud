//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0)); // Initializing random seed using current system time
    int probability = rand() % 101; // Generating a random number between 0 and 100
    printf("Welcome to the Alien Invasion Probability Calculator!\n\n");
    printf("Based on our advanced calculations, there is a %d%% chance that aliens will invade Earth in the next 5 years.\n\n", probability);
    printf("Don't panic just yet, this is just a prediction based on statistical analysis. There's also a possibility that aliens will never come to Earth or that they have already visited us without us realizing it!\n");
    return 0;
}