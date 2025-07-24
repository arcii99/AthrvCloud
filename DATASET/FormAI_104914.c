//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // seed the random number generator
    
    char *genome = (char*) malloc(100 * sizeof(char)); // allocate memory for genome string
    
    printf("Generating genome sequence...\n");
    for (int i = 0; i < 100; i++) { // generate 100 random nucleotides
        int rand_num = rand() % 4; // generate random number between 0-3
        
        switch(rand_num) { // map random number to a nucleotide
            case 0:
                genome[i] = 'A';
                break;
            case 1:
                genome[i] = 'T';
                break;
            case 2:
                genome[i] = 'C';
                break;
            case 3:
                genome[i] = 'G';
                break;
            default:
                printf("Error: Invalid nucleotide.\n");
                exit(1);
        }
    }
    
    printf("Genome sequence generated: %s\n\n", genome);
    
    free(genome); // free allocated memory
    
    return 0;
}