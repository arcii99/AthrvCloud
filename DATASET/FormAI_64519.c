//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    // Initialize Random Seed
    srand(time(NULL));

    // Define DNA Bases
    char dna_bases[] = {'A', 'C', 'G', 'T'};

    // Define Genome Length
    int genome_length = 100;

    // Initialize Genome String
    char genome[genome_length];

    // Generate Random Genome String
    for (int i = 0; i < genome_length; i++){
        int random_index = rand() % 4;
        genome[i] = dna_bases[random_index];
    }

    // Print Generated Genome String
    printf("Generated Genome String: %s\n", genome);

    // Define Sequencing Error Probability
    double sequencing_error_prob = 0.01;

    // Initialize Sequenced Genome String
    char sequenced_genome[genome_length];

    // Simulate Genome Sequencing
    for (int i = 0; i < genome_length; i++){
        double random_prob = (double) rand() / RAND_MAX;
        if (random_prob < sequencing_error_prob){
            int random_index = rand() % 4;
            sequenced_genome[i] = dna_bases[random_index];
        } else {
            sequenced_genome[i] = genome[i];
        }
    }

    // Print Sequenced Genome String
    printf("Sequenced Genome String: %s\n", sequenced_genome);

    return 0;
}