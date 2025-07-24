//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    char bases[4] = {'A', 'C', 'G', 'T'}; // the four possible bases
    int sequence_length = 100; // length of the DNA sequence
    char* sequence = (char*) malloc(sequence_length + 1); // allocate memory for sequence

    srand(time(0)); // seed the random number generator with the current time

    // generate the sequence
    for (int i = 0; i < sequence_length; i++) {
        int index = rand() % 4; // choose a random number between 0 and 3
        sequence[i] = bases[index]; // add the corresponding base to the sequence
    }
    sequence[sequence_length] = '\0'; // add null terminator at the end of the sequence

    // print the sequence
    printf("Generated sequence: %s\n", sequence);

    // simulate sequencing errors
    int error_rate = 10; // 10% error rate
    for (int i = 0; i < sequence_length; i++) {
        int r = rand() % 100; // choose a random number between 0 and 99
        if (r < error_rate) { // introduce error
            int index = rand() % 4;
            while (sequence[i] == bases[index]) { // make sure the new base is different from the original one
                index = rand() % 4;
            }
            sequence[i] = bases[index]; // replace the base with the error
        }
    }

    // print the sequence with errors
    printf("Sequenced sequence with %d%% error rate: %s\n", error_rate, sequence);

    free(sequence); // free allocated memory

    return 0;
}