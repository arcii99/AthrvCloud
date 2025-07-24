//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // seed the random number generator with current time

    char bases[] = {'A', 'C', 'G', 'T'}; // declare an array of nucleotide bases
    int length = rand() % 100 + 1; // generate a random sequence length between 1 and 100
    char sequence[length + 1]; // create a character array to store the sequence

    printf("Simulating genome sequencing...\n\n");
    printf("Generating random sequence length: %d\n", length);

    // loop through each position in the sequence and randomly assign a base
    for (int i = 0; i < length; i++) {
        int index = rand() % 4; // generate a random index between 0 and 3
        sequence[i] = bases[index]; // assign the base at that index to the current position in the sequence
    }

    sequence[length] = '\0'; // terminate the character array with a null character

    printf("Random sequence generated: %s\n\n", sequence);

    // print the sequence in groups of 10 bases for easier reading
    printf("Sequence breakdown:\n");

    for (int i = 0; i < length; i++) {
        printf("%c", sequence[i]);

        if ((i + 1) % 10 == 0) {
            printf(" ");
        }
    }

    printf("\n\nSimulation complete.\n");

    return 0;
}