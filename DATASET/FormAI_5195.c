//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BASES "ACGT" // DNA bases

// function to generate random DNA sequence of given length
char* simulate_genome(int length) {
    char* genome = (char*) malloc(sizeof(char) * (length + 1));
    srand(time(NULL)); // set random seed
    // loop through each position and randomly select a base
    for(int i = 0; i < length; i++) {
        genome[i] = BASES[rand() % 4];
    }
    genome[length] = '\0'; // add null terminator to end of string
    return genome;
}

int main() {
    int length;
    printf("Enter length of genome to simulate: ");
    scanf("%d", &length);
    char* genome = simulate_genome(length);
    printf("Simulated genome: %s", genome);
    free(genome); // free dynamically allocated memory
    return 0;
}