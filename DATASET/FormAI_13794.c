//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define nucleotides
#define A 'A'
#define C 'C'
#define G 'G'
#define T 'T'

// define genome length
#define GENOME_SIZE 100

int main() {
    // initialize random seed
    srand(time(NULL));
    
    // create array to hold genome sequence
    char genome[GENOME_SIZE];
    
    // generate random genome sequence
    for (int i = 0; i < GENOME_SIZE; i++) {
        int rand_num = rand() % 4; // generates random number between 0 and 3
        switch(rand_num) {
            case 0:
                genome[i] = A;
                break;
            case 1:
                genome[i] = C;
                break;
            case 2:
                genome[i] = G;
                break;
            case 3:
                genome[i] = T;
                break;
            default:
                printf("Error: invalid number generated!\n");
                exit(1);
        }
    }
    
    // print genome sequence
    printf("Generated Genome Sequence: ");
    for (int i = 0; i < GENOME_SIZE; i++) {
        printf("%c", genome[i]);
    }
    printf("\n");
    
    // simulate genome sequencing process
    printf("Simulating Genome Sequencing Process...\n");
    for (int i = 0; i < GENOME_SIZE; i++) {
        int rand_num = rand() % 100;
        if (rand_num < 10) { // 10% chance of sequencing error
            int rand_num2 = rand() % 3; // generates random number between 0 and 2
            switch(rand_num2) {
                case 0:
                    printf("Error: sequencing error at position %d (A instead of %c)\n", i, genome[i]);
                    genome[i] = A;
                    break;
                case 1:
                    printf("Error: sequencing error at position %d (C instead of %c)\n", i, genome[i]);
                    genome[i] = C;
                    break;
                case 2:
                    printf("Error: sequencing error at position %d (G instead of %c)\n", i, genome[i]);
                    genome[i] = G;
                    break;
                default:
                    printf("Error: invalid number generated!\n");
                    exit(1);
            }
        }
    }
    
    // print the sequenced genome sequence
    printf("Sequenced Genome Sequence:   ");
    for (int i = 0; i < GENOME_SIZE; i++) {
        printf("%c", genome[i]);
    }
    printf("\n");
    
    return 0;
}