//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define GENOME_LEN 1000000
#define NUCLEOTIDES "ACGT"

int main(void) {
    // Initialize variables
    srand(time(NULL));
    char genome[GENOME_LEN + 1];
    memset(genome, '\0', sizeof(genome));
    
    // Generate random genome sequence
    for (int i = 0; i < GENOME_LEN; i++) {
        genome[i] = NUCLEOTIDES[rand() % strlen(NUCLEOTIDES)];
    }
    
    // Display the genome sequence
    printf("Generated genome sequence:\n");
    printf("%s\n", genome);
    
    // Find the longest repeated substring
    int longest_length = 0;
    char longest_substring[GENOME_LEN] = "";
    
    for (int i = 0; i < GENOME_LEN; i++) {
        for (int j = i + 1; j < GENOME_LEN; j++) {
            int k = 0;
            
            while ((i + k < j) && (j + k < GENOME_LEN) && (genome[i+k] == genome[j+k])) {
                k++;
            }
            
            if (k > longest_length) {
                longest_length = k;
                strncpy(longest_substring, &genome[i], longest_length);
                longest_substring[longest_length] = '\0';
            }
        }
    }
    
    // Display the longest repeated substring
    if (longest_length > 0) {
        printf("\nLongest repeated substring:\n");
        printf("%s\n", longest_substring);
    } else {
        printf("\nNo repeated substrings found.\n");
    }
    
    return 0;
}