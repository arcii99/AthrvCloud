//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define GENE_LENGTH 10 // Length of gene sequence

char* generateRandomGene() {
    char nucleotides[4] = {'A', 'C', 'G', 'T'}; // Possible nucleotides
    char* gene = malloc((GENE_LENGTH + 1) * sizeof(char)); // Allocate memory for gene sequence
    for (int i = 0; i < GENE_LENGTH; i++) {
        int randomIndex = rand() % 4; // Generate random index between 0 and 3
        gene[i] = nucleotides[randomIndex]; // Assign random nucleotide to gene sequence
    }
    gene[GENE_LENGTH] = '\0'; // Add null terminator
    return gene;
}

void printGene(char* gene) {
    printf("%s\n", gene);
}

int main() {
    srand(time(NULL)); // Seed random number generator
    
    int numGenes;
    printf("Enter number of genes to sequence: ");
    scanf("%d", &numGenes);

    char** genes = malloc(numGenes * sizeof(char*)); // Allocate memory for array of gene sequences
    for (int i = 0; i < numGenes; i++) {
        genes[i] = generateRandomGene();
    }

    printf("\nSequencing %d genes...\n\n", numGenes);
    for (int i = 0; i < numGenes; i++) {
        printf("Gene %d:\n", i+1);
        printGene(genes[i]);
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < numGenes; i++) {
        free(genes[i]);
    }
    free(genes);

    return 0;
}