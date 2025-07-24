//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    srand(time(NULL)); // initialize random number generator

    int genome_length = 50; // total length of genome to be sequenced
    char nucleotides[] = {'A', 'C', 'G', 'T'}; // possible nucleotide sequences

    // create the genome sequence
    char genome[genome_length];
    for(int i=0; i<genome_length; i++) {
        int random_index = rand() % 4; // generates random index between 0 and 3
        genome[i] = nucleotides[random_index]; // assigns a random nucleotide to the genome
    }

    // print the original genome sequence
    printf("Original genome sequence: ");
    for(int i=0; i<genome_length; i++) {
        printf("%c", genome[i]);
    }
    printf("\n");

    // then we simulate the sequencing process
    int reads = 100; // number of reads to be generated
    int read_length = 10; // length of each read

    // create the reads
    char read[read_length];
    for(int i=0; i<reads; i++) {
        int random_start = rand() % (genome_length - read_length); // random starting position for the read
        for(int j=0; j<read_length; j++) {
            read[j] = genome[random_start + j]; // generate the read sequence
        }
        printf("Read %d sequence: ", i+1);
        for(int j=0; j<read_length; j++) {
            printf("%c", read[j]);
        }
        printf("\n");
    }

    return 0;
}