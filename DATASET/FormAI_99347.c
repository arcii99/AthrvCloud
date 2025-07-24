//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DNA_LENGTH 100

int main() {
    srand(time(NULL));  // initialize random seed

    // generate random DNA sequence
    char dna[DNA_LENGTH + 1];
    for (int i = 0; i < DNA_LENGTH; i++) {
        int rand_num = rand() % 4;  // random number between 0-3
        switch (rand_num) {
            case 0:
                dna[i] = 'A';
                break;
            case 1:
                dna[i] = 'T';
                break;
            case 2:
                dna[i] = 'C';
                break;
            case 3:
                dna[i] = 'G';
                break;
        }
    }
    dna[DNA_LENGTH] = '\0';  // add null terminator

    // print original DNA sequence
    printf("Original DNA sequence:\n%s\n", dna);

    // simulate genome sequencing
    int num_reads = 10;
    int read_length = 10;
    char reads[num_reads][read_length + 1];
    for (int i = 0; i < num_reads; i++) {
        // randomly choose starting index
        int start_index = rand() % (DNA_LENGTH - read_length);

        // extract read from DNA sequence
        for (int j = 0; j < read_length; j++) {
            reads[i][j] = dna[start_index + j];
        }
        reads[i][read_length] = '\0';  // add null terminator

        // introduce errors to read
        int num_errors = rand() % read_length;  // choose number of errors
        for (int j = 0; j < num_errors; j++) {
            int error_index = rand() % read_length;  // choose error index
            int rand_num = rand() % 3;  // random number between 0-2
            switch (rand_num) {
                case 0:
                    reads[i][error_index] = 'A' + (reads[i][error_index] + 1) % 4;  // change base to a random one
                    break;
                case 1:
                    reads[i][error_index] = '-';  // introduce deletion
                    break;
                case 2:
                    reads[i][error_index] = 'A' + (reads[i][error_index] + 1) % 4;  // change base to a random one
                    reads[i][error_index + 1] = '+';  // introduce insertion
                    break;
            }
        }
    }

    // print simulated reads
    printf("Simulated reads:\n");
    for (int i = 0; i < num_reads; i++) {
        printf("%s\n", reads[i]);
    }

    return 0;
}