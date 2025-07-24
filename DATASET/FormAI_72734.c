//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define GENOME_SIZE 10000
#define BASES "ACGT"

int main() {

    char genome[GENOME_SIZE + 1];

    // Seed the random number generator with current time
    srand(time(NULL));

    // Generate random genome sequence
    for (int i = 0; i < GENOME_SIZE; i++) {
        genome[i] = BASES[rand() % 4];
    }
    genome[GENOME_SIZE] = '\0';

    printf("Generated genome sequence: %s\n\n", genome);

    // Ask user for substring to search for
    char search_str[100];
    printf("Enter a substring to search for: ");
    fgets(search_str, sizeof(search_str), stdin);
    search_str[strcspn(search_str, "\n")] = '\0'; // Strip newline character

    // Search for substring in genome sequence
    int occurrences = 0;
    char *pos = genome;
    while ((pos = strstr(pos, search_str)) != NULL) {
        occurrences++;
        pos += strlen(search_str);
    }

    printf("\nSubstring \"%s\" found %d time(s) in the genome sequence.\n", search_str, occurrences);

    return 0;
}