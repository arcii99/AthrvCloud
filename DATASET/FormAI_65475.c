//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define GENOME_LENGTH 1000000
#define BASES "AGCT"

int main(void) {
    srand(time(NULL)); // Seed the random number generator
    bool genome[GENOME_LENGTH] = {false}; // Initialize the genome with all zeroes (false)
    
    // Randomly generate the genome
    for (int i = 0; i < GENOME_LENGTH; i++) {
        int random_base = rand() % 4; // Generate a random number between 0 and 3
        genome[i] = (BASES[random_base] == 'C'); // Set the corresponding genome element to true if the random base is 'C'
    }
    
    // Find the longest run of 'C's in the genome
    int longest_run = 0;
    int current_run = 0;
    for (int i = 0; i < GENOME_LENGTH; i++) {
        if (genome[i]) { // If the current element is true (i.e. a 'C')
            current_run++;
        } else {
            if (current_run > longest_run) {
                longest_run = current_run;
            }
            current_run = 0;
        }
    }
    if (current_run > longest_run) { // Check the final run length in case it was the longest
        longest_run = current_run;
    }
    
    printf("Simulated genome:\n");
    for (int i = 0; i < GENOME_LENGTH; i++) {
        printf("%c", BASES[(int) genome[i]]);
    }
    printf("\n");
    printf("Longest run of 'C's: %d\n", longest_run);
    
    return 0;
}