//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_PLAYERS 4
#define GENE_LENGTH 100
#define MUTATION_RATE 0.02
#define GENERATIONS 5

void generateRandomGenome(char genome[GENE_LENGTH]){
    int i;
    for(i = 0; i < GENE_LENGTH; i++){
        genome[i] = rand() % 4;
    }
}

void mutateGenome(char genome[GENE_LENGTH]){
    int i;
    for(i = 0; i < GENE_LENGTH; i++){
        if((double)rand()/RAND_MAX < MUTATION_RATE){
            genome[i] = rand() % 4;
        }
    }
}

void printGenome(char genome[GENE_LENGTH]){
    int i;
    for(i = 0; i < GENE_LENGTH; i++){
        printf("%d", genome[i]);
    }
    printf("\n");
}

int calculateFitness(char genome[GENE_LENGTH], char targetGenome[GENE_LENGTH]){
    int i, fitness = 0;
    for(i = 0; i < GENE_LENGTH; i++){
        if(genome[i] == targetGenome[i]){
            fitness++;
        }
    }
    return fitness;
}

int main(){
    char genomes[MAX_PLAYERS][GENE_LENGTH];
    char targetGenome[GENE_LENGTH];
    int i, j, generation = 0;
    srand(time(NULL));

    // Generate random target genome
    generateRandomGenome(targetGenome);

    while(generation < GENERATIONS){
        // Generate random genomes for all players
        for(i = 0; i < MAX_PLAYERS; i++){
            generateRandomGenome(genomes[i]);
        }

        // Allow players to play
        for(i = 0; i < MAX_PLAYERS; i++){
            printf("Player %d's genome: ", i+1);
            printGenome(genomes[i]);
            printf("Player %d's fitness: %d\n", i+1, calculateFitness(genomes[i], targetGenome));
            printf("\n");
        }

        // Calculate fitness and sort players based on fitness
        int fitness[MAX_PLAYERS];
        for(i = 0; i < MAX_PLAYERS; i++){
            fitness[i] = calculateFitness(genomes[i], targetGenome);
        }
        int index[MAX_PLAYERS];
        for(i = 0; i < MAX_PLAYERS; i++){
            index[i] = i;
        }
        int tempIndex, tempFitness;
        for(i = 0; i < MAX_PLAYERS - 1; i++){
            for(j = i+1; j < MAX_PLAYERS; j++){
                if(fitness[i] < fitness[j]){
                    tempFitness = fitness[i];
                    fitness[i] = fitness[j];
                    fitness[j] = tempFitness;

                    tempIndex = index[i];
                    index[i] = index[j];
                    index[j] = tempIndex;
                }
            }
        }

        // Breed top 2 players
        char newGenomes[MAX_PLAYERS-2][GENE_LENGTH];
        for(i = 0; i < GENE_LENGTH; i++){
            // Choose randomly from parents
            int index1 = rand() % 2;
            int index2 = rand() % 2;
            int parent1 = genomes[index[index1]][i];
            int parent2 = genomes[index[index2]][i];

            // Add mutation
            int result = rand() % 100;
            if(result < MUTATION_RATE * 100){
                newGenomes[0][i] = rand() % 4;
            } else if(result < MUTATION_RATE * 100 * 2){
                newGenomes[1][i] = rand() % 4;
            } else {
                // Breed normally
                newGenomes[0][i] = parent1;
                newGenomes[1][i] = parent2;
            }
        }

        // Replace bottom 2 players with new genomes
        for(i = 0; i < GENE_LENGTH; i++){
            genomes[MAX_PLAYERS-2][i] = newGenomes[0][i];
            genomes[MAX_PLAYERS-1][i] = newGenomes[1][i];
        }

        // Mutate all genomes except the top two
        for(i = 2; i < MAX_PLAYERS; i++){
            mutateGenome(genomes[i]);
        }

        printf("Target genome: ");
        printGenome(targetGenome);
        printf("\n");

        generation++;
    }

    return 0;
}