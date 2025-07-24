//FormAI DATASET v1.0 Category: Computer Biology ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 10000 // Maximum length of DNA strand

char* replicate(char* dna) {
    int len = strlen(dna);
    char* result = malloc(len * 2 + 1); // Memory allocation for replicated DNA
    int i, j;

    for (i = 0, j = 0; i < len; i++, j += 2) {
        result[j] = dna[i];
        result[j + 1] = dna[i]; // Replication of each nucleotide
    }

    result[len * 2] = '\0'; // Add terminating null character

    return result;
}

int main() {
    char* dna = "ACGTCTGATCACGGGACTCGGT";
    char* replicated_dna = replicate(dna);

    printf("Original DNA Strand: %s\n", dna);
    printf("Replicated DNA Strand: %s\n", replicated_dna);

    free(replicated_dna); // Free memory allocated for replicated DNA

    return 0;
}