//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize random number generator
    srand(time(0));

    // Define the DNA sequence
    char sequence[] = "ACGT";

    // Define the length of the genome and a buffer to store the result
    int length = 50;
    char genome[length+1];

    // Generate the genome sequence
    for (int i = 0; i < length; i++) {
        int r = rand() % 4;
        genome[i] = sequence[r];
    }
    genome[length] = '\0';

    // Print the genome sequence
    printf("Genome sequence:\n%s\n", genome);

    // Determine the GC content of the genome
    int gcCount = 0;
    for (int i = 0; i < length; i++) {
        if (genome[i] == 'G' || genome[i] == 'C') {
            gcCount++;
        }
    }
    float gcContent = ((float)gcCount / length) * 100;

    // Print the GC content
    printf("GC content: %.2f%%\n", gcContent);

    return 0;
}