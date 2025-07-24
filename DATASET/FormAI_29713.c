//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random nucleotide base
char random_base() {
    int random_num = rand() % 4;
    switch (random_num) {
        case 0:
            return 'A';
        case 1:
            return 'C';
        case 2:
            return 'G';
        case 3:
            return 'T';
        default:
            return 'X'; // Should never happen!
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    
    int genome_length = 500; // The length of the genome to sequence
    char genome[genome_length+1]; // Add 1 for the null terminator
    for (int i = 0; i < genome_length; i++) {
        genome[i] = random_base(); // Generate a random nucleotide base and add it to the genome
    }
    genome[genome_length] = '\0'; // Add the null terminator
    
    printf("Original Genome:\n");
    printf("%s\n\n", genome);

    // Simulate the sequencing process
    int read_length = 10; // The length of each read
    int num_reads = genome_length / read_length; // The number of reads we need to sequence the entire genome
    char sequenced_genome[genome_length+1];
    int index = 0;
    for (int i = 0; i < num_reads; i++) {
        int start = i * read_length;
        int end = start + read_length;
        for (int j = start; j < end; j++) {
            sequenced_genome[index++] = genome[j];
        }
    }
    sequenced_genome[genome_length] = '\0'; // Add the null terminator
    
    printf("Sequenced Genome:\n");
    printf("%s\n", sequenced_genome);
    
    return 0;
}