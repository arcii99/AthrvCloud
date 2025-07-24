//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize variables
    char bases[] = {'A', 'C', 'G', 'T'};
    int sequenceLength, numSequences;
    FILE *outputFile;
    
    // Seed the random number generator
    srand(time(NULL));
    
    // Prompt user for input
    printf("Enter the length of each sequence: ");
    scanf("%d", &sequenceLength);
    printf("Enter the number of sequences to generate: ");
    scanf("%d", &numSequences);
    
    // Open output file to write sequences
    outputFile = fopen("sequences.txt", "w");
    
    // Generate sequences and write to output file
    for (int i = 0; i < numSequences; i++) {
        // Generate random sequence
        char sequence[sequenceLength + 1];
        for (int j = 0; j < sequenceLength; j++) {
            sequence[j] = bases[rand() % 4];
        }
        sequence[sequenceLength] = '\0';
        
        // Write sequence to output file
        fprintf(outputFile, ">Sequence%d\n%s\n", i+1, sequence);
    }
    
    // Close output file
    fclose(outputFile);
    
    printf("Sequences have been generated and saved to sequences.txt.\n");
    
    return 0;
}