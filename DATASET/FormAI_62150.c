//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 10000
#define MUTATION_RATE 0.01

void generateGenome(char *genome) {
    for (int i = 0; i < GENOME_LENGTH; i++) {
        int randNum = rand() % 4;
        switch (randNum) {
            case 0:
                genome[i] = 'A';
                break;
            case 1:
                genome[i] = 'G';
                break;
            case 2:
                genome[i] = 'C';
                break;
            case 3:
                genome[i] = 'T';
                break;
        }
    }
}

void mutateGenome(char *genome) {
    for (int i = 0; i < GENOME_LENGTH; i++) {
        double randNum = (double) rand() / RAND_MAX;
        if (randNum < MUTATION_RATE) {
            int randNum2 = rand() % 3;
            switch (randNum2) {
                case 0:
                    genome[i] = 'A';
                    break;
                case 1:
                    genome[i] = 'G';
                    break;
                case 2:
                    genome[i] = 'C';
                    break;
                case 3:
                    genome[i] = 'T';
                    break;
            }   
        }
    }
}

int main() {
    srand(time(NULL));
    char genome[GENOME_LENGTH];
    int numSimulations = 10000;
    int numMutations = 0;
    double mutationPercent = 0.0;

    for (int i = 0; i < numSimulations; i++) {
        generateGenome(genome);
        mutateGenome(genome);

        // Count number of mutations in genome
        for (int j = 0; j < GENOME_LENGTH; j++) {
            if (genome[j] != 'A' && genome[j] != 'G' && genome[j] != 'C' && genome[j] != 'T') {
                printf("Error: Invalid character detected in genome.\n");
                return 1;
            }
            if (genome[j] != 'A') {
                numMutations++;
            }
            if (genome[j] != 'G') {
                numMutations++;
            }
            if (genome[j] != 'C') {
                numMutations++;
            }
            if (genome[j] != 'T') {
                numMutations++;
            }
        }
        mutationPercent += (double) numMutations / (4 * GENOME_LENGTH);

        numMutations = 0;
    }

    mutationPercent /= (double) numSimulations;
    printf("Average percent of genome mutations: %f\n", mutationPercent);

    return 0;
}