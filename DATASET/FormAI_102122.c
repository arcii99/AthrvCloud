//FormAI DATASET v1.0 Category: Computer Biology ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char gene_name[20];
    int gene_length;
} Gene;

typedef struct {
    Gene genes[20];
    int num_genes;
} Genome;

void printGenome(Genome genome) {
    printf("Genome:\n");
    for(int i = 0; i < genome.num_genes; i++) {
        printf("Gene Name: %s\n", genome.genes[i].gene_name);
        printf("Gene Length: %d\n", genome.genes[i].gene_length);
    }
}

int main() {
    Genome genome;
    genome.num_genes = 0;
    
    Gene g1;
    strcpy(g1.gene_name, "ATP synthase");
    g1.gene_length = 1500;
    genome.genes[genome.num_genes++] = g1;
    
    Gene g2;
    strcpy(g2.gene_name, "Chlorophyll A-B");
    g2.gene_length = 2000;
    genome.genes[genome.num_genes++] = g2;
    
    Gene g3;
    strcpy(g3.gene_name, "Rubisco");
    g3.gene_length = 1800;
    genome.genes[genome.num_genes++] = g3;
    
    printGenome(genome);
    
    return 0;
}