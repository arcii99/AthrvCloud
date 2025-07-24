//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 1000 // define the length of the genome to be sequenced

int main() {
    char genome[GENOME_LENGTH]; // array to hold the genome sequence
    int i;
    srand(time(NULL)); // seed the random number generator

    // randomly generate a genome sequence
    for(i=0; i<GENOME_LENGTH; i++) {
        int nucleotide = rand() % 4; // generate a random number between 0 and 3
        switch(nucleotide) {
            case 0:
                genome[i] = 'A'; // Adenine
                break;
            case 1:
                genome[i] = 'C'; // Cytosine
                break;
            case 2:
                genome[i] = 'G'; // Guanine
                break;
            case 3:
                genome[i] = 'T'; // Thymine
                break;
        }
    }

    printf("Generated genome sequence: ");
    for(i=0; i<GENOME_LENGTH; i++) {
        printf("%c", genome[i]); // print the generated genome sequence
    }

    // simulate sequencing the genome
    int num_reads = 10000; // define the number of reads to be generated
    char read[100]; // array to hold each read
    int read_length = 100; // define the length of each read
    int j, k;

    printf("\n\nSequencing reads:");

    for(i=0; i<num_reads; i++) {
        int start_index = rand() % (GENOME_LENGTH - read_length); // generate a random starting index
        for(j=start_index, k=0; k<read_length; j++, k++) {
            read[k] = genome[j]; // copy the nucleotides from the genome sequence to the read
        }

        printf("\nRead %d: ", i+1);
        for(k=0; k<read_length; k++) {
            printf("%c", read[k]); // print the generated read
        }
    }

    return 0;
}