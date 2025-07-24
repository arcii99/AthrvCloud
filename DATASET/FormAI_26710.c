//FormAI DATASET v1.0 Category: Computer Biology ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

#define ORGANISM_COUNT 1000
#define GENE_COUNT 200
#define MUTATION_RATE 0.01

int organism_matrix[ORGANISM_COUNT][GENE_COUNT];

void initialize_organisms() {
    // Randomly initialize genes for each organism
    for (int i = 0; i < ORGANISM_COUNT; i++) {
        for (int j = 0; j < GENE_COUNT; j++) {
            organism_matrix[i][j] = rand() % 2;
        }
    }
}

int calculate_fitness(int* gene_expression) {
    // Calculate fitness score based on gene expression
    int fitness_score = 0;
    for (int i = 0; i < GENE_COUNT; i++) {
        if (gene_expression[i] == 1) {
            fitness_score++;
        }
    }

    return fitness_score;
}

void mutate_organisms() {
    // Randomly mutate genes for each organism
    for (int i = 0; i < ORGANISM_COUNT; i++) {
        for (int j = 0; j < GENE_COUNT; j++) {
            if ((double) rand() / RAND_MAX < MUTATION_RATE) {
                organism_matrix[i][j] = !organism_matrix[i][j];
            }
        }
    }
}

void breed_organisms() {
    // Create new organisms by breeding the fittest ones
    int offspring_matrix[ORGANISM_COUNT][GENE_COUNT];

    for (int i = 0; i < ORGANISM_COUNT; i++) {
        // Select random parents
        int parent_1_index = rand() % ORGANISM_COUNT;
        int parent_2_index = rand() % ORGANISM_COUNT;

        // Create offspring by randomly selecting genes from parents
        for (int j = 0; j < GENE_COUNT; j++) {
            if (rand() % 2 == 0) {
                offspring_matrix[i][j] = organism_matrix[parent_1_index][j];
            } else {
                offspring_matrix[i][j] = organism_matrix[parent_2_index][j];
            }
        }
    }

    // Replace old organisms with offspring
    for (int i = 0; i < ORGANISM_COUNT; i++) {
        for (int j = 0; j < GENE_COUNT; j++) {
            organism_matrix[i][j] = offspring_matrix[i][j];
        }
    }
}

int main() {
    srand(42); // Set random seed for reproducibility

    // Initialize organisms
    initialize_organisms();

    for (int generation = 0; generation < 100; generation++) {
        // Calculate fitness scores for each organism
        int fitness_scores[ORGANISM_COUNT];
        for (int i = 0; i < ORGANISM_COUNT; i++) {
            fitness_scores[i] = calculate_fitness(organism_matrix[i]);
        }

        // Print average fitness score for this generation
        int total_fitness_score = 0;
        for (int i = 0; i < ORGANISM_COUNT; i++) {
            total_fitness_score += fitness_scores[i];
        }
        double average_fitness_score = (double) total_fitness_score / ORGANISM_COUNT;
        printf("Generation %d: Average fitness score = %.2f\n", generation, average_fitness_score);

        // Mutate organisms
        mutate_organisms();

        // Breed organisms
        breed_organisms();
    }

    return 0;
}