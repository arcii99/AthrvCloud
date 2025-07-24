//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_BASEPAIRS 1000000 // Set the length of the genome sequence

int main() {
    char * genome = malloc(NUM_BASEPAIRS); // Allocate memory for the genome sequence
    
    // Generate a random genome sequence using A, C, G, T base pairs
    srand(time(NULL)); // Seed the random number generator with the current time
    for (int i = 0; i < NUM_BASEPAIRS; i++) {
        int r = rand() % 4; // Generate a random number between 0 and 3
        switch (r) {
            case 0:
                genome[i] = 'A';
                break;
            case 1:
                genome[i] = 'C';
                break;
            case 2:
                genome[i] = 'G';
                break;
            case 3:
                genome[i] = 'T';
                break;
        }
    }
    
    // Output the genome sequence
    for (int i = 0; i < NUM_BASEPAIRS; i++) {
        printf("%c", genome[i]);
    }
    printf("\n");
    
    free(genome); // Release the memory allocated for the genome sequence
    
    return 0;
}