//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 100
#define MUTATION_RATE 0.01

// Function declaration
void generateGenome(char* genome);
void mutateGenome(char* genome);
void printGenome(char* genome);

int main()
{
    char genome[GENOME_LENGTH];
    srand(time(NULL)); // seed for random number generator
    
    // Generate the initial genome
    generateGenome(genome);
    printf("Initial Genome Sequence:\n");
    printGenome(genome);
    
    // Simulate random mutations
    for (int i = 0; i < 10; i++) {
        mutateGenome(genome);
        printf("Mutated Genome Sequence #%d:\n", i+1);
        printGenome(genome);
    }
    
    return 0;
}

// Function to generate a random genome sequence
void generateGenome(char* genome)
{
    for (int i = 0; i < GENOME_LENGTH; i++) {
        int nucleotideIndex = rand() % 4;
        switch(nucleotideIndex) {
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

// Function to simulate a random mutation in the genome sequence
void mutateGenome(char* genome)
{
    for (int i = 0; i < GENOME_LENGTH; i++) {
        double randomNum = (double)rand() / RAND_MAX;
        if (randomNum < MUTATION_RATE) {
            int nucleotideIndex = rand() % 4;
            switch(nucleotideIndex) {
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
}

// Function to print the genome sequence
void printGenome(char* genome)
{
    for (int i = 0; i < GENOME_LENGTH; i++) {
        printf("%c", genome[i]);
    }
    printf("\n");
}