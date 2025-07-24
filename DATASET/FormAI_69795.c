//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define GENOME_LENGTH 100
#define SEQUENCE_LENGTH 10

char genome[GENOME_LENGTH]; // stores the original genome sequence
char sequence[SEQUENCE_LENGTH]; // stores the sequence to be searched for
int matches[GENOME_LENGTH - SEQUENCE_LENGTH + 1]; // stores the positions where sequence matches genome

void generate_random_genome() {
    // populate genome with random nucleotide bases A, C, G, T
    for (int i = 0; i < GENOME_LENGTH; i++) {
        int r = rand() % 4;
        switch (r) {
            case 0:
                genome[i] = 'A';
                break;
            case 1:
                genome[i] = 'C';
                break;
            case 2:
                genome[i] = 'G';
                break;
            case 3:
                genome[i] = 'T';
                break;
        }
    }
}

void input_sequence_from_user() {
    printf("Enter the sequence to search for (length %d): ", SEQUENCE_LENGTH);
    scanf("%s", sequence);
}

void search_sequence_in_genome() {
    int num_matches = 0;
    for (int i = 0; i <= GENOME_LENGTH - SEQUENCE_LENGTH; i++) {
        int match = 1;
        for (int j = 0; j < SEQUENCE_LENGTH; j++) {
            if (genome[i+j] != sequence[j]) {
                match = 0;
                break;
            }
        }
        if (match) {
            matches[num_matches] = i;
            num_matches++;
        }
    }
    printf("Found %d match(es) at position(s): ", num_matches);
    for (int i = 0; i < num_matches; i++) {
        printf("%d ", matches[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL)); // seed random number generator
    generate_random_genome();
    printf("Generated random genome sequence: %s\n", genome);
    input_sequence_from_user();
    search_sequence_in_genome();
    return 0;
}