//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Linus Torvalds
/*
 * C Genome Sequencing Simulator
 *
 * This program simulates the sequencing of genomes using a simple algorithm
 * that generates random DNA sequences.
 *
 * Author: Linus Torvalds
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 1000

char random_base() {
    /* generates a random DNA base: A, C, G, or T */
    int r = rand() % 4;
    switch (r) {
        case 0:
            return 'A';
        case 1:
            return 'C';
        case 2:
            return 'G';
        case 3:
            return 'T';
        default:
            return 'N'; /* shouldn't happen */
    }
}

int main() {
    int length = 0;
    char genome[MAX_LENGTH];

    srand(time(NULL)); /* initialize random seed */

    /* generate random genome */
    while (length < MAX_LENGTH) {
        genome[length++] = random_base();
    }

    /* output genome */
    printf("Generated genome:\n%s\n", genome);

    /* simulate sequencing */
    int num_reads = length / 100;
    int read_length = 100;
    char read[read_length + 1]; /* add 1 for null terminator */
    int i, j;
    for (i = 0; i < num_reads; i++) {
        /* select random starting position */
        int start = rand() % (length - read_length);
        /* extract read */
        for (j = 0; j < read_length; j++) {
            read[j] = genome[start + j];
        }
        read[j] = '\0'; /* add null terminator */
        /* output read */
        printf(">read_%d\n%s\n", i, read);
    }

    return 0;
}