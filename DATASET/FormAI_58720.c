//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

// Define the gene sequence structure
typedef struct gene_sequence {
    char gene_name[20];
    int dna_seq[1000];
} GeneSequence;

// Generate random gene sequence
void generate_gene_sequence(GeneSequence* gene_seq) {
    int i;
    for (i = 0; i < 1000; i++) {
        gene_seq->dna_seq[i] = rand() % 4;
    }
}

int main() {
    // Initialize gene sequence array
    GeneSequence gene_sequences[10];
    
    // Generate 10 random gene sequences
    int i;
    for (i = 0; i < 10; i++) {
        sprintf(gene_sequences[i].gene_name, "Gene %d", i);
        generate_gene_sequence(&gene_sequences[i]);
    }

    // Print the gene sequences
    for (i = 0; i < 10; i++) {
        printf("Gene Name: %s\n", gene_sequences[i].gene_name);
        printf("DNA Sequence: ");
        int j;
        for (j = 0; j < 1000; j++) {
            printf("%d", gene_sequences[i].dna_seq[j]);
        }
        printf("\n\n");
    }

    return 0;
}