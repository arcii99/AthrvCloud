//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH 10 // Length of the genome
#define BASES 4 // Number of possible bases

int main() {
    srand(time(NULL)); // Seed the random number generator

    // Initialize the genome sequence
    int genome[LENGTH];
    for (int i = 0; i < LENGTH; i++) {
        genome[i] = rand() % BASES; // Assign a random base to each position
    }

    // Print the genome sequence
    printf("Genome sequence: ");
    for (int i = 0; i < LENGTH; i++) {
        int base = genome[i];
        if (base == 0) {
            printf("A");
        } else if (base == 1) {
            printf("C");
        } else if (base == 2) {
            printf("G");
        } else {
            printf("T");
        }
    }
    printf("\n");

    // Determine the most common base in the genome sequence
    int counts[BASES] = {0};
    for (int i = 0; i < LENGTH; i++) {
        counts[genome[i]]++;
    }
    int max_count = 0;
    int max_base = 0;
    for (int i = 0; i < BASES; i++) {
        if (counts[i] > max_count) {
            max_count = counts[i];
            max_base = i;
        }
    }
    printf("Most common base: ");
    if (max_base == 0) {
        printf("A");
    } else if (max_base == 1) {
        printf("C");
    } else if (max_base == 2) {
        printf("G");
    } else {
        printf("T");
    }
    printf("\n");

    // Modify the genome sequence by randomly inserting or deleting bases
    for (int i = 0; i < 3; i++) {
        int choice = rand() % 2;
        if (choice == 0) {
            int position = rand() % LENGTH;
            int base = rand() % BASES;
            for (int j = LENGTH - 1; j > position; j--) {
                genome[j] = genome[j - 1];
            }
            genome[position] = base;
        } else {
            int position = rand() % (LENGTH - 1);
            for (int j = position; j < LENGTH - 1; j++) {
                genome[j] = genome[j + 1];
            }
            genome[LENGTH - 1] = rand() % BASES;
        }
    }

    // Print the modified genome sequence
    printf("Modified genome sequence: ");
    for (int i = 0; i < LENGTH; i++) {
        int base = genome[i];
        if (base == 0) {
            printf("A");
        } else if (base == 1) {
            printf("C");
        } else if (base == 2) {
            printf("G");
        } else {
            printf("T");
        }
    }
    printf("\n");

    return 0;
}