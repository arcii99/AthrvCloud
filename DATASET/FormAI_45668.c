//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 100                      // Length of genome sequence
#define MUTATION_RATE 0.05                     // Probability of mutation

char randomBase() {                             // Returns a random base from A, C, G, T
    int index = rand() % 4;
    char bases[] = {'A', 'C', 'G', 'T'};
    return bases[index];
}

void printGenome(char genome[]) {               // Prints the genome
    for(int i=0; i<GENOME_LENGTH; i++) {
        printf("%c", genome[i]);
    }
    printf("\n");
}

void mutate(char genome[]) {                    // Mutates the genome
    for(int i=0; i<GENOME_LENGTH; i++) {
        if((double)rand()/RAND_MAX <= MUTATION_RATE) {
            genome[i] = randomBase();
        }
    }
}

int main() {
    srand(time(NULL));                          // Seed the random number generator

    char genome[GENOME_LENGTH];
    
    // Initialize genome with random bases
    for(int i=0; i<GENOME_LENGTH; i++) {
        genome[i] = randomBase();
    }

    printf("Starting genome: ");
    printGenome(genome);

    // Mutate the genome 10 times and print the mutated genome each time
    for(int i=1; i<=10; i++) {
        mutate(genome);
        printf("Mutated genome %d: ", i);
        printGenome(genome);
    }

    return 0;
}