//FormAI DATASET v1.0 Category: Computer Biology ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("Welcome to our protein analysis program!\n");
    printf("Please enter the size of the protein sequence: ");

    int size;
    scanf("%d", &size);

    char *sequence = (char *) malloc(sizeof(char) * (size + 1)); // Allocates memory for the sequence

    printf("Please enter the protein sequence: ");
    scanf("%s", sequence);

    int i;
    int amino_acids[26] = {0}; // Array to store the frequency of each amino acid

    for (i = 0; i < size; i++) {
        if (sequence[i] >= 'A' && sequence[i] <= 'Z') { // Making sure the sequence contains only capital letters
            amino_acids[sequence[i] - 'A']++;
        } else { // If the sequence contains an invalid character
            printf("Invalid protein sequence!\n");
            free(sequence); // Free the memory allocated for the sequence
            return 0;
        }
    }

    printf("\n---\n");

    printf("Protein Sequence Analysis:\n");
    printf("%-15s%-15s\n", "Amino Acid", "Frequency");

    for (i = 0; i < 26; i++) {
        if (amino_acids[i] > 0) { // Print only the amino acids that have a frequency greater than 0
            printf("%-15c%-15d\n", 'A' + i, amino_acids[i]);
        }
    }

    free(sequence); // Free the memory allocated for the sequence

    printf("---\n\nThanks for using our program!\n");

    return 0;
}