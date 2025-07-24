//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Define variables
    char seq[100];
    int seq_length, i;
    float gc_content = 0, at_content = 0;

    // Get user input
    printf("Enter DNA sequence: ");
    scanf("%s", &seq); 
    seq_length = strlen(seq);

    // Calculate GC and AT content
    for (i = 0; i < seq_length; i++) {
        if (seq[i] == 'G' || seq[i] == 'C') {
            gc_content++;
        } else if (seq[i] == 'A' || seq[i] == 'T') {
            at_content++;
        }
    }
    gc_content = gc_content / seq_length;
    at_content = at_content / seq_length;

    // Output results
    printf("\nLength of sequence: %d", seq_length);
    printf("\nGC content: %.2f%%", gc_content * 100);
    printf("\nAT content: %.2f%%", at_content * 100);

    return 0;
}