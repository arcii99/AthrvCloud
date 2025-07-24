//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Setup RNG
    srand(time(NULL));

    // Generate Random Genome String
    char genome[51];
    for (int i = 0; i < 50; i++) {
        genome[i] = (rand() % 4) + 'A';
    }
    genome[50] = '\0';

    // Print Genome
    printf("GENOME: %s\n", genome);

    // Setup Sequencer
    int sequence_length = 10;
    int sequence_start = rand() % (50 - sequence_length);
    char sequence[11];
    for (int i = 0; i < sequence_length; i++) {
        sequence[i] = genome[sequence_start + i];
    }
    sequence[sequence_length] = '\0';

    // Print Sequence
    printf("SEQUENCE: %s\n", sequence);

    // Setup Amplifier
    int amplification_factor = rand() % 6;
    char amplified_sequence[sequence_length * (amplification_factor + 1) + 1];
    for (int i = 0; i < sequence_length * (amplification_factor + 1); i++) {
        if (i % sequence_length == 0) {
            amplified_sequence[i] = '-';
        } else {
            amplified_sequence[i] = sequence[i % sequence_length];
        }
    }
    amplified_sequence[sequence_length * (amplification_factor + 1)] = '\0';

    // Print Amplified Sequence
    printf("AMPLIFIED SEQUENCE: %s\n", amplified_sequence);

    return 0;
}