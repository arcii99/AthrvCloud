//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SEQUENCE_LENGTH 100 // Length of simulated genome sequence
#define CHROMOSOME_COUNT 23 // Number of chromosomes in human genome

int main() {
    srand(time(NULL)); // Seed random number generator with current time

    // Initialize arrays to hold genome sequence and chromosome lengths
    int genome[SEQUENCE_LENGTH];
    int chromosome_lengths[CHROMOSOME_COUNT] = { 249250621, 243199373, 198022430, 191154276, 180915260, 
                                                 171115067, 159138663, 146364022, 141213431, 135534747, 
                                                 135006516, 133851895, 115169878, 107349540, 102531392, 
                                                 90354753, 81195210, 78077248, 59128983, 63025520, 
                                                 48129895, 51304566, 155270560 };

    // Generate the simulated genome sequence
    int current_chromosome = 0; // index of current chromosome
    int current_base = 0; // index of current base in chromosome
    int remaining_bases = SEQUENCE_LENGTH; // number of bases remaining to generate
    while (remaining_bases > 0) {
        int bases_to_generate = remaining_bases;
        if (bases_to_generate > chromosome_lengths[current_chromosome] - current_base) {
            bases_to_generate = chromosome_lengths[current_chromosome] - current_base;
        }
        for (int i = 0; i < bases_to_generate; i++) {
            genome[current_base + i] = rand() % 4; // Generate random base (0=A, 1=C, 2=G, 3=T)
        }
        remaining_bases -= bases_to_generate;
        current_base += bases_to_generate;
        if (current_base >= chromosome_lengths[current_chromosome]) {
            current_chromosome++;
            current_base = 0;
        }
    }

    // Print the simulated genome sequence
    for (int i = 0; i < SEQUENCE_LENGTH; i++) {
        char base;
        switch (genome[i]) {
            case 0: base = 'A'; break;
            case 1: base = 'C'; break;
            case 2: base = 'G'; break;
            case 3: base = 'T'; break;
        }
        printf("%c", base);
    }

    return 0;
}