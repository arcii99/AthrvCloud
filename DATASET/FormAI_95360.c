//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TOTAL_BLOCKS 100
#define MAX_SIGNAL_STRENGTH 256
#define MIN_SIGNAL_STRENGTH -256

int main()
{
    int signal_strength[TOTAL_BLOCKS]; // Array to store signal strengths
    int average_strength = 0; // Variable to store overall average strength
    int blocks_above_average = 0; // Variable to store number of blocks above average strength
    int blocks_below_average = 0; // Variable to store number of blocks below average strength
    int max_strength = MIN_SIGNAL_STRENGTH; // Variable to store maximum signal strength
    int min_strength = MAX_SIGNAL_STRENGTH; // Variable to store minimum signal strength

    // Random signal strengths generation
    for(int i = 0; i < TOTAL_BLOCKS; i++)
    {
        signal_strength[i] = rand() % (MAX_SIGNAL_STRENGTH - MIN_SIGNAL_STRENGTH + 1) + MIN_SIGNAL_STRENGTH;
    }

    // Calculating average signal strength
    for(int i = 0; i < TOTAL_BLOCKS; i++)
    {
        average_strength += signal_strength[i];
    }
    average_strength /= TOTAL_BLOCKS;

    // Calculating blocks above/below average signal strength
    for(int i = 0; i < TOTAL_BLOCKS; i++)
    {
        if(signal_strength[i] > average_strength) blocks_above_average++;
        else if(signal_strength[i] < average_strength) blocks_below_average++;
    }

    // Finding maximum and minimum signal strengths
    for(int i = 0; i < TOTAL_BLOCKS; i++)
    {
        if(signal_strength[i] > max_strength) max_strength = signal_strength[i];
        if(signal_strength[i] < min_strength) min_strength = signal_strength[i];
    }

    // Printing analysis report
    printf("Wi-Fi signal strength analyzer\n");
    printf("----------------------------------------------\n");
    printf("Number of blocks: %d\n", TOTAL_BLOCKS);
    printf("Average signal strength: %d\n", average_strength);
    printf("Number of blocks above average: %d\n", blocks_above_average);
    printf("Number of blocks below average: %d\n", blocks_below_average);
    printf("Maximum signal strength: %d\n", max_strength);
    printf("Minimum signal strength: %d\n", min_strength);

    return 0;
}