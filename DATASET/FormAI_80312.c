//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seed for random number generation
    int genomeLength = 1000; // Length of genome
    int i, j; // Loop variables
    char nucleotides[] = {'A', 'C', 'G', 'T'}; // Possible nucleotides in genome
    char genome[genomeLength + 1]; // String to represent genome, +1 for null terminator

    // Generate random genome
    for (i = 0; i < genomeLength; i++) {
        int r = rand() % 4; // Random number between 0-3
        genome[i] = nucleotides[r]; // Assign random nucleotide to genome
    }
    genome[genomeLength] = '\0'; // Add null terminator to genome string

    // Print generated genome
    printf("Generated genome: \n%s\n\n", genome);

    // Simulate errors in genome sequencing
    int errorPercentage = 5; // Percentage of errors to simulate
    int numErrors = (genomeLength * errorPercentage) / 100; // Calculate number of errors to simulate
    for (i = 0; i < numErrors; i++) {
        int r = rand() % genomeLength; // Randomly select position in genome
        char originalNucleotide = genome[r]; // Save correct nucleotide before error simulation
        int r2 = rand() % 4; // Randomly select new nucleotide to simulate error
        while (nucleotides[r2] == originalNucleotide) { // Ensure new nucleotide is not the same as original
            r2 = rand() % 4;
        }
        genome[r] = nucleotides[r2]; // Simulate error by replacing nucleotide
    }

    // Print sequenced genome with errors
    printf("Simulated sequencing errors (%d%%): \n%s\n\n", errorPercentage, genome);

    // Correct errors in genome sequencing
    for (i = 0; i < genomeLength; i++) {
        char originalNucleotide = genome[i]; // Save correct nucleotide before correction
        for (j = 0; j < 4; j++) { // Check each possible nucleotide
            if (nucleotides[j] != originalNucleotide) { // Ignore correct nucleotide
                genome[i] = nucleotides[j]; // Assign new nucleotide to simulate corrected error
                // Print corrected genome
                printf("Corrected error at position %d: \n%s\n\n", i + 1, genome);
            }
        }
        genome[i] = originalNucleotide; // Restore original nucleotide
    }

    // Exit program
    return 0;
}