//FormAI DATASET v1.0 Category: Computer Biology ; Style: synchronous
#include <stdio.h>

int main() {
    int num_of_genes;
    printf("Enter the number of genes: ");
    scanf("%d", &num_of_genes);

    int genes[num_of_genes];

    printf("Enter the IDs of %d genes separated by spaces: ", num_of_genes);
    for (int i = 0; i < num_of_genes; i++) {
        scanf("%d", &genes[i]);
    }

    printf("\nEnter the ID of the gene you want to search for: ");
    int search_gene;
    scanf("%d", &search_gene);

    int found_index = -1;
    for (int i = 0; i < num_of_genes; i++) {
        if (genes[i] == search_gene) {
            found_index = i;
            break;
        }
    }

    if (found_index == -1) {
        printf("\nThe gene with ID %d was not found.\n", search_gene);
    }
    else {
        printf("\nThe gene with ID %d was found at index %d.\n", search_gene, found_index);
    }

    return 0;
}