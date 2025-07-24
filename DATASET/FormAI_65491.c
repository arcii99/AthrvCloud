//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int genome[100], i;
    srand(time(NULL)); // Initialize the random seed based on current time

    // Generating the genome
    for (i = 0; i < 100; i++) {
        genome[i] = rand() % 4;
        // By default, A=0, C=1, G=2, T=3
    }

    // Showing the generated genome
    printf("Generated genome: ");
    for (i = 0; i < 100; i++) {
        switch (genome[i]) {
            case 0:
                printf("A");
                break;
            case 1:
                printf("C");
                break;
            case 2:
                printf("G");
                break;
            case 3:
                printf("T");
                break;
        }
    }
    printf("\n");

    // Simulating mutations
    int num_mutations = rand() % 10 + 1; // Generate a random number of mutations between 1 and 10

    for (i = 0; i < num_mutations; i++) {
        int pos = rand() % 100; // Generate a random position for the mutation
        int prev_base = genome[pos];
        genome[pos] = rand() % 4; // Generate a random new base
        printf("Mutation at position %d: %c -> ", pos+1, prev_base==0 ? 'A' : prev_base==1 ? 'C' : prev_base==2 ? 'G' : 'T');
        switch (genome[pos]) {
            case 0:
                printf("A");
                break;
            case 1:
                printf("C");
                break;
            case 2:
                printf("G");
                break;
            case 3:
                printf("T");
                break;
        }
        printf("\n");
    }

    // Showing the mutated genome
    printf("\nMutated genome (%d mutations): ", num_mutations);
    for (i = 0; i < 100; i++) {
        switch (genome[i]) {
            case 0:
                printf("A");
                break;
            case 1:
                printf("C");
                break;
            case 2:
                printf("G");
                break;
            case 3:
                printf("T");
                break;
        }
    }
    printf("\n\nSimulation complete.\n");

    return 0;
}