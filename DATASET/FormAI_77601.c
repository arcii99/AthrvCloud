//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 1000

int main()
{
    int genome[GENOME_LENGTH];
    int i;

    srand(time(0));

    // Generate random genome
    for (i = 0; i < GENOME_LENGTH; i++) {
        genome[i] = rand() % 6; // 0-5: A, C, G, T, N, -
    }

    // Print genome
    printf("Genome: ");
    for (i = 0; i < GENOME_LENGTH; i++) {
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

            case 4:
                printf("N");
                break;

            case 5:
                printf("-");
                break;
        }
    }
    printf("\n");

    // Mutate genome
    int num_mutations = rand() % (GENOME_LENGTH / 5); // Up to 20% mutations
    for (i = 0; i < num_mutations; i++) {
        int index = rand() % GENOME_LENGTH;
        genome[index] = rand() % 6;
    }

    // Print mutated genome
    printf("Mutated genome: ");
    for (i = 0; i < GENOME_LENGTH; i++) {
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

            case 4:
                printf("N");
                break;

            case 5:
                printf("-");
                break;
        }
    }
    printf("\n");

    return 0;
}