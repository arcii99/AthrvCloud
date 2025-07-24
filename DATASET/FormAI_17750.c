//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 1000
#define MUTATION_RATE 0.01

int main(void) {
    char genome[GENOME_LENGTH + 1]; // +1 for null terminator
    srand(time(NULL)); // use current time as seed for random generator
    
    // Generate random genome
    for (int i = 0; i < GENOME_LENGTH; i++) {
        int random_base = rand() % 4; // generate integer between 0 and 3
        switch(random_base) {
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
    genome[GENOME_LENGTH] = '\0'; // add null terminator to end of string
    
    printf("Original genome: %s\n", genome);
    
    // Introduce mutations
    for (int i = 0; i < GENOME_LENGTH; i++) {
        float random_float = (float)rand() / RAND_MAX; // generate float between 0 and 1
        if (random_float < MUTATION_RATE) {
            // mutate base
            int random_base = rand() % 4;
            switch(random_base) {
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
    }
    
    printf("Mutated genome: %s\n", genome);
    
    return 0;
}