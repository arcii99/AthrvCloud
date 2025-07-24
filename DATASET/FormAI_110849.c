//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LEN 1000

char getRandomBase() {
    // Function that returns a random DNA base 
    char bases[] = {'A', 'C', 'T', 'G'};
    int index = rand() % 4;
    return bases[index];
}

int main() {
    // Seed the random number generator
    srand(time(0));
    
    // Generate a random genome with length GENOME_LEN
    char genome[GENOME_LEN+1]; // +1 for null termination
    for(int i=0; i<GENOME_LEN; i++) {
        genome[i] = getRandomBase();
    }
    genome[GENOME_LEN] = '\0'; // Null terminate the string

    // Print the genome
    printf("Generated genome:\n%s\n\n", genome);

    // Simulate sequencing errors
    int num_reads = 10; // Number of reads to simulate
    int read_len = 100; // Length of each read
    int error_rate = 5; // Percentage of sequencing errors (e.g. 5%)
    for(int i=0; i<num_reads; i++) {
        // Choose a random starting position for the read
        int start_pos = rand() % (GENOME_LEN - read_len);
        
        // Generate the read
        char read[read_len+1]; // +1 for null termination
        for(int j=0; j<read_len; j++) {
            char base = genome[start_pos+j];
            if(rand() % 100 < error_rate) {
                // Simulate a sequencing error
                base = getRandomBase();
            }
            read[j] = base;
        }
        read[read_len] = '\0'; // Null terminate the string
        
        // Print the read
        printf("Read %d:\n%s\n\n", i+1, read);
    }

    return 0;
}