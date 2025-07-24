//FormAI DATASET v1.0 Category: Computer Biology ; Style: grateful
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_SEQUENCE_LENGTH 1000

int main() {
    // Initialize variables
    char name[MAX_NAME_LENGTH];
    char sequence[MAX_SEQUENCE_LENGTH];
    int sequence_length = 0;
    
    // Prompt user for name and sequence
    printf("Hello! Please enter your name: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline character
    
    printf("Hi %s! Please enter your sequence (A, C, G, T only): ", name);
    fgets(sequence, MAX_SEQUENCE_LENGTH, stdin);
    sequence_length = strlen(sequence);
    
    // Remove newline character and non-DNA characters
    for (int i = 0; i < sequence_length; i++) {
        if (sequence[i] == '\n') {
            sequence[i] = '\0';
            sequence_length--;
            break;
        }
        else if (sequence[i] != 'A' && sequence[i] != 'C' && sequence[i] != 'G' && sequence[i] != 'T') {
            for (int j = i; j < sequence_length - 1; j++) {
                sequence[j] = sequence[j+1];
            }
            sequence[sequence_length-1] = '\0';
            sequence_length--;
            i--;
        }
    }
    
    // Count nucleotides
    int numA = 0;
    int numC = 0;
    int numG = 0;
    int numT = 0;
    
    for (int i = 0; i < sequence_length; i++) {
        if (sequence[i] == 'A')
            numA++;
        else if (sequence[i] == 'C')
            numC++;
        else if (sequence[i] == 'G')
            numG++;
        else
            numT++;
    }
    
    // Print results
    printf("\nThank you, %s, for entering your sequence! Here are your statistics:\n", name);
    printf("Total Length: %d\n", sequence_length);
    printf("Nucleotide Counts:\n");
    printf("A: %d\n", numA);
    printf("C: %d\n", numC);
    printf("G: %d\n", numG);
    printf("T: %d\n", numT);
    
    return 0;
}