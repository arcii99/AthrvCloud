//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10000 // Maximum number of nucleotides in the sequence

int main(){

    char nucleotides[4] = {'A', 'C', 'G', 'T'}; // All possible nucleotides
    char sequence[N]; // Stores the generated sequence
    int n; // Desired number of nucleotides in the sequence
    int i; // Loop variable
    
    // Seed the random number generator with the current time
    srand(time(NULL));
    
    // Ask the user for the desired number of nucleotides
    printf("Enter the desired number of nucleotides: ");
    scanf("%d", &n);
    
    // Generate the sequence by randomly selecting nucleotides
    for(i = 0; i < n; i++){
        int index = rand() % 4; // Randomly select an index from 0 to 3
        sequence[i] = nucleotides[index]; // Add the selected nucleotide to the sequence
    }
    
    // Print the generated sequence
    printf("Generated sequence: %s\n", sequence);
    
    return 0;
}