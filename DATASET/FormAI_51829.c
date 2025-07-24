//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_SIZE 100000000 // 100 million base pairs

int main() {
    int genome[GENOME_SIZE];
    int i;

    // Seed random numbers for filling genome
    srand(time(NULL));

    // Fill genome with random base pairs
    for(i = 0; i < GENOME_SIZE; i++) {
        genome[i] = rand() % 4; // There are four possible base pairs
    }

    // Print out first 10 base pairs for demonstration purposes
    printf("First 10 base pairs: ");
    for(i = 0; i < 10; i++) {
        printf("%d ", genome[i]);
    }
    printf("\n");

    // Simulate sequencing errors
    for(i = 0; i < 1000; i++) {
        int index = rand() % GENOME_SIZE; // Choose random index to introduce an error
        int errorType = rand() % 2; // Choose substitution or insertion/deletion error

        if(errorType == 0) { // Substitution error
            int newBasePair = rand() % 4;
            genome[index] = newBasePair;
        } else { // Insertion/deletion error
            int action = rand() % 2; // Choose insertion or deletion
            if(action == 0) { // Insertion
                int newBasePair = rand() % 4;
                int temp = genome[index];
                genome[index] = newBasePair;
                for(int j = index+1; j < GENOME_SIZE; j++) { // Shift everything to the right
                    int temp2 = genome[j];
                    genome[j] = temp;
                    temp = temp2;
                }
                genome[GENOME_SIZE-1] = temp; // Replace the last base pair
            } else { // Deletion
                for(int j = index; j < GENOME_SIZE-1; j++) { // Shift everything to the left
                    genome[j] = genome[j+1];
                }
                genome[GENOME_SIZE-1] = rand() % 4; // Replace the last base pair
            }
        }
    }

    // Print out first 10 base pairs again to show errors
    printf("First 10 base pairs with errors: ");
    for(i = 0; i < 10; i++) {
        printf("%d ", genome[i]);
    }
    printf("\n");

    return 0;
}