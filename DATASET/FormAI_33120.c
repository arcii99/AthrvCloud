//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // Seed the random number generator with the current time
    int numBases = 1000; // The number of DNA bases in the sequence
    char bases[] = {'A', 'C', 'G', 'T'}; // The possible DNA bases
    int seq[numBases]; // The array to hold the DNA sequence
    
    printf("Generating DNA sequence...\n\n");
    
    // Generate the DNA sequence
    for(int i = 0; i < numBases; i++)
    {
        seq[i] = rand() % 4; // Randomly choose a base
    }
    
    // Print the DNA sequence
    for(int i = 0; i < numBases; i++)
    {
        printf("%c", bases[seq[i]]);
        if((i + 1) % 80 == 0) // Break the line every 80 bases for readability
            printf("\n");
    }
    
    return 0;
}