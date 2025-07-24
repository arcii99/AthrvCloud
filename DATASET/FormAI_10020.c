//FormAI DATASET v1.0 Category: Computer Biology ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>

struct gene {
    int id;
    float expression;
};

void print_gene(struct gene g) {
    printf("Gene ID: %d\nExpression Level: %f\n\n", g.id, g.expression);
}

int main() {
    int n;
    printf("Enter the number of genes: ");
    scanf("%d", &n);
    struct gene *genes = malloc(n * sizeof(struct gene));

    // Populate genes with random data
    srand(42);
    for(int i = 0; i < n; i++) {
        genes[i].id = i+1;
        genes[i].expression = rand() / (float)RAND_MAX;
    }

    // Print all genes
    printf("All Genes:\n");
    for(int i = 0; i < n; i++) {
        print_gene(genes[i]);
    }

    // Find the gene with the highest expression level
    struct gene max_gene = genes[0];
    for(int i = 1; i < n; i++) {
        if(genes[i].expression > max_gene.expression) {
            max_gene = genes[i];
        }
    }
    printf("The gene with the highest expression level is:\n");
    print_gene(max_gene);

    free(genes);
    return 0;
}