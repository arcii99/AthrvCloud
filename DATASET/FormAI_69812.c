//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));  // seed the random number generator with the current time
    char bases[] = {'A', 'C', 'G', 'T'};
    int sequence_length = 1000;  // set the length of the DNA sequence
    char sequence[sequence_length+1];  // create a character array to hold the DNA sequence
    int i;
    for (i = 0; i < sequence_length; i++) {  // generate a random DNA sequence
        int rand_index = rand() % 4;  // choose a random index between 0 and 3
        sequence[i] = bases[rand_index];  // select a random base
    }
    sequence[sequence_length] = '\0';  // add a null terminator to the end of the sequence

    printf("Original DNA sequence: %s\n", sequence);

    // simulate sequencing errors by randomly changing bases
    int error_rate = 2;  // set the error rate as a percentage
    int num_errors = (double) error_rate * sequence_length / 100;
    for (i = 0; i < num_errors; i++) {  // randomly introduce errors
        int rand_index = rand() % sequence_length;  // choose a random index
        int rand_base = rand() % 3;  // choose a random base index (excluding the original base)
        sequence[rand_index] = bases[(rand_index + rand_base) % 4];  // replace the original base with a different one
    }

    printf("Sequenced DNA sequence: %s\n", sequence);

    return 0;
}