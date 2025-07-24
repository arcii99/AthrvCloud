//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 100000
#define MIN_LENGTH 1000
#define MAX_BASES 4

char bases[] = {'A', 'C', 'G', 'T'};

/* Generate a random sequence of base pairs */
char* generate_sequence(int length) {
    char *sequence = malloc(length * sizeof(char));
    for (int i = 0; i < length; i++) {
        int random_index = rand() % MAX_BASES;
        sequence[i] = bases[random_index];
    }
    return sequence;
}

/* Simulate a genome sequencing experiment */
char* sequence_genome(char *genome, double error_rate) {
    int length = strlen(genome);
    char *sequence = malloc(length * sizeof(char));
    for (int i = 0; i < length; i++) {
        double random_num = (double) rand() / RAND_MAX;
        if (random_num > error_rate) { // no error, copy base pair as is
            sequence[i] = genome[i];
        } else { // simulate sequencing error
            int random_index = rand() % MAX_BASES;
            sequence[i] = bases[random_index];
        }
    }
    return sequence;
}

int main() {
    srand(time(NULL)); // seed random number generator

    int genome_length = rand() % (MAX_LENGTH - MIN_LENGTH + 1) + MIN_LENGTH;
    char *genome = generate_sequence(genome_length);
    printf("Generated genome: %s\n", genome);

    double error_rate = (double) (rand() % 50) / 100; // generate error rate between 0 and 0.5
    char *sequence = sequence_genome(genome, error_rate);
    printf("Simulated sequence with %f error rate: %s\n", error_rate, sequence);

    free(genome);
    free(sequence);

    return 0;
}