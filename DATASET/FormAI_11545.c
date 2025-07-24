//FormAI DATASET v1.0 Category: Computer Biology ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Define a DNA sequence to analyze
    char dna[] = "AGTCGATCAGTACGTAGCTGATCAGTCA";
    int dna_length = strlen(dna);

    // Define a hashtable to store the frequency of each nucleotide
    int hashtable[4] = {0};

    // Loop through the DNA sequence, counting the frequency of each nucleotide
    for (int i = 0; i < dna_length; i++) {
        if (dna[i] == 'A') {
            hashtable[0]++;
        } else if (dna[i] == 'C') {
            hashtable[1]++;
        } else if (dna[i] == 'G') {
            hashtable[2]++;
        } else if (dna[i] == 'T') {
            hashtable[3]++;
        }
    }

    // Output the results
    printf("Frequency of nucleotide A: %d\n", hashtable[0]);
    printf("Frequency of nucleotide C: %d\n", hashtable[1]);
    printf("Frequency of nucleotide G: %d\n", hashtable[2]);
    printf("Frequency of nucleotide T: %d\n", hashtable[3]);

    // Calculate the GC content of the DNA sequence
    int gc_count = hashtable[1] + hashtable[2];
    double gc_content = ((double)gc_count / dna_length) * 100;

    // Output the GC content
    printf("GC content of DNA sequence: %.2f%%\n", gc_content);

    return 0;
}