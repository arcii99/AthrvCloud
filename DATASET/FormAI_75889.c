//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: invasive
// Welcome to my Genome Sequencing Simulator!
// This invasive program will generate a random DNA sequence and simulate a sequencing process.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the DNA alphabet and its size
#define DNABASES "ACGT"
#define DNABASES_SIZE 4

// Define the read length and number of reads
#define READ_LEN 10
#define NUM_READS 5

int main()
{
    srand(time(0)); // Seed the random generator with the current time

    // Generate a random DNA sequence of length 100
    char dna[101];
    for (int i = 0; i < 100; i++) {
        dna[i] = DNABASES[rand() % DNABASES_SIZE];
    }
    dna[100] = '\0'; // Terminate the string with a null character

    printf("Generated DNA sequence: %s\n", dna);

    // Simulate the sequencing process by generating random reads from the DNA sequence
    for (int i = 0; i < NUM_READS; i++) {
        int read_start = rand() % (100 - READ_LEN + 1); // Generate a random starting position for the read
        char read[READ_LEN + 1];
        for (int j = 0; j < READ_LEN; j++) {
            read[j] = dna[read_start + j]; // Extract the bases from the DNA sequence
        }
        read[READ_LEN] = '\0'; // Terminate the string with a null character

        printf("Read %d: %s\n", i + 1, read);
    }

    return 0;
}