//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Set up the initial genome sequence
    char base_pairs[4] = {'A', 'C', 'G', 'T'}; // Adenine, Cytosine, Guanine, Thymine
    char genome[1000];
    srand(time(NULL));
    int i;
    for (i = 0; i < 1000; i++) {
        int random_num = rand() % 4;
        genome[i] = base_pairs[random_num];
    }

    // Random mutations
    int num_mutations = rand() % 10 + 1; // Random between 1 and 10 mutations
    for (i = 0; i < num_mutations; i++) {
        int mutation_pos = rand() % 1000; // Random position in the genome
        int mutation_type = rand() % 3;
        switch(mutation_type) {
            case 0:
                // Insertion
                char new_base = base_pairs[rand() % 4];
                int k;
                for (k = 999; k >= mutation_pos; k--) {
                    genome[k + 1] = genome[k]; // Shift everything to right of mutation position to make room for new base
                }
                genome[mutation_pos] = new_base;
                break;
            case 1:
                // Deletion
                int num_bases_to_delete = rand() % 5 + 1; // Random between 1 and 5 bases to delete
                for (k = mutation_pos; k < mutation_pos + num_bases_to_delete; k++) {
                    genome[k] = genome[k + num_bases_to_delete]; // Shift everything to right of deletion to left
                }
                break;
            case 2:
                // Substitution
                char new_substitute_base = base_pairs[rand() % 4];
                genome[mutation_pos] = new_substitute_base;
                break;
        }
    }

    // Print the modified genome sequence
    for (i = 0; i < 1000; i++) {
        printf("%c", genome[i]);
    }

    return 0;
}