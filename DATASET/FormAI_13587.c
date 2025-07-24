//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Randomly generate a DNA sequence of length 50
    char dna[50];
    int i;
    for (i = 0; i < 50; i++) {
        int rand_num = rand() % 4;
        if (rand_num == 0) {
            dna[i] = 'A';
        } else if (rand_num == 1) {
            dna[i] = 'C';
        } else if (rand_num == 2) {
            dna[i] = 'G';
        } else {
            dna[i] = 'T';
        }
    }

    // Print the DNA sequence
    printf("DNA Sequence:\n");
    for (i = 0; i < 50; i++) {
        printf("%c", dna[i]);
        if (i % 10 == 9) {
            printf(" ");
        }
    }
    printf("\n\n");

    // Randomly generate 5 medieval names for the genes
    char gene1[10], gene2[10], gene3[10], gene4[10], gene5[10];
    char *gene_names[] = {"Dragonheart", "Sword_of_Justice", "Kingdom_Defender", "Enchanted_Warrior", "Holy_Grail"};

    i = rand() % 5;
    strcpy(gene1, gene_names[i]);

    while (1) {
        i = rand() % 5;
        if (strcmp(gene1, gene_names[i]) != 0) {
            strcpy(gene2, gene_names[i]);
            break;
        }
    }

    while (1) {
        i = rand() % 5;
        if (strcmp(gene1, gene_names[i]) != 0 && strcmp(gene2, gene_names[i]) != 0) {
            strcpy(gene3, gene_names[i]);
            break;
        }
    }

    while (1) {
        i = rand() % 5;
        if (strcmp(gene1, gene_names[i]) != 0 && strcmp(gene2, gene_names[i]) != 0 && strcmp(gene3, gene_names[i]) != 0) {
            strcpy(gene4, gene_names[i]);
            break;
        }
    }

    while (1) {
        i = rand() % 5;
        if (strcmp(gene1, gene_names[i]) != 0 && strcmp(gene2, gene_names[i]) != 0 && strcmp(gene3, gene_names[i]) != 0 && strcmp(gene4, gene_names[i]) != 0) {
            strcpy(gene5, gene_names[i]);
            break;
        }
    }

    // Assign each gene to a random section of the DNA sequence
    int gene1_start = rand() % 40;
    int gene1_end = gene1_start + (rand() % (50 - gene1_start));
    int gene1_len = gene1_end - gene1_start + 1;

    int gene2_start, gene2_end, gene2_len;
    while (1) {
        gene2_start = rand() % 40;
        gene2_end = gene2_start + (rand() % (50 - gene2_start));
        gene2_len = gene2_end - gene2_start + 1;
        if ((gene2_start > gene1_end || gene2_end < gene1_start) && gene2_len >= 5) {
            break;
        }
    }

    int gene3_start, gene3_end, gene3_len;
    while (1) {
        gene3_start = rand() % 40;
        gene3_end = gene3_start + (rand() % (50 - gene3_start));
        gene3_len = gene3_end - gene3_start + 1;
        if ((gene3_start > gene2_end || gene3_end < gene2_start) && (gene3_start > gene1_end || gene3_end < gene1_start) && gene3_len >= 5) {
            break;
        }
    }

    int gene4_start, gene4_end, gene4_len;
    while (1) {
        gene4_start = rand() % 40;
        gene4_end = gene4_start + (rand() % (50 - gene4_start));
        gene4_len = gene4_end - gene4_start + 1;
        if ((gene4_start > gene3_end || gene4_end < gene3_start) && (gene4_start > gene2_end || gene4_end < gene2_start) && (gene4_start > gene1_end || gene4_end < gene1_start) && gene4_len >= 5) {
            break;
        }
    }

    int gene5_start, gene5_end, gene5_len;
    while (1) {
        gene5_start = rand() % 40;
        gene5_end = gene5_start + (rand() % (50 - gene5_start));
        gene5_len = gene5_end - gene5_start + 1;
        if ((gene5_start > gene4_end || gene5_end < gene4_start) && (gene5_start > gene3_end || gene5_end < gene3_start) && (gene5_start > gene2_end || gene5_end < gene2_start) && (gene5_start > gene1_end || gene5_end < gene1_start) && gene5_len >= 5) {
            break;
        }
    }

    // Print the gene names and their respective sections of the DNA sequence
    printf("%s: ", gene1);
    for (i = gene1_start; i <= gene1_end; i++) {
        printf("%c", dna[i]);
    }
    printf("\n");

    printf("%s: ", gene2);
    for (i = gene2_start; i <= gene2_end; i++) {
        printf("%c", dna[i]);
    }
    printf("\n");

    printf("%s: ", gene3);
    for (i = gene3_start; i <= gene3_end; i++) {
        printf("%c", dna[i]);
    }
    printf("\n");

    printf("%s: ", gene4);
    for (i = gene4_start; i <= gene4_end; i++) {
        printf("%c", dna[i]);
    }
    printf("\n");

    printf("%s: ", gene5);
    for (i = gene5_start; i <= gene5_end; i++) {
        printf("%c", dna[i]);
    }
    printf("\n");

    return 0;
}