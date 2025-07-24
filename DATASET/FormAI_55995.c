//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    srand(time(0));

    char genome[] = "ATCG";
    char result[100];

    printf("Welcome to the Genome Sequencing Simulator!\n\n");

    // Get user input for genome length
    int length;
    printf("Enter the desired length of the genome (maximum 100): ");
    scanf("%d", &length);

    // Generate random genome sequence
    for(int i=0; i<length; i++) {
        int index = rand() % 4;
        result[i] = genome[index];
    }

    // Print the generated genome sequence
    printf("\nGenerated genome sequence: %s\n", result);

    // Get user input for the number of mutations
    int num_mutations;
    printf("\nEnter the desired number of mutations: ");
    scanf("%d", &num_mutations);

    // Generate random mutations
    for(int i=0; i<num_mutations; i++) {
        int index = rand() % length;
        int mutation = rand() % 3;
        result[index] = genome[mutation];
    }

    // Print the final genome sequence with mutations
    printf("\nFinal genome sequence with mutations: %s\n", result);

    // Exit program
    printf("\nThank you for using the Genome Sequencing Simulator!\n");
    return 0;
}