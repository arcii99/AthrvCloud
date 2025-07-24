//FormAI DATASET v1.0 Category: Computer Biology ; Style: satisfied
// A program to simulate a simplified ecosystem with predator-prey dynamics
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ORGANISMS 200
#define MAX_EPOCHS 100
#define INITIAL_PREY 100
#define INITIAL_PREDATORS 10
#define BIRTH_RATE 0.1
#define DEATH_RATE 0.05
#define PREDATION_RATE 0.02
#define MIN_FITNESS 0.1
#define MAX_FITNESS 1.0

typedef struct organism {
    int id;
    int age;
    char type;
    double fitness;
} Organism;

Organism organisms[MAX_ORGANISMS];
int numOrganisms = 0;

int getCurrentYear() {
    return 2021;
}

double getMeanFitness(char type) {
    double count = 0.0;
    double totalFitness = 0.0;
    for (int i = 0; i < numOrganisms; i++) {
        Organism o = organisms[i];
        if (o.type != type) {
            continue;
        }
        count++;
        totalFitness += o.fitness;
    }
    if (count == 0.0) {
        return 0.0;
    }
    return totalFitness / count;
}

void reproduce(int numOffspring, char type, int age) {
    for (int i = 0; i < numOffspring; i++) {
        Organism o = { .id = numOrganisms + i, .age = age, .type = type, .fitness = (double)rand() / RAND_MAX };
        organisms[numOrganisms + i] = o;
    }
    numOrganisms += numOffspring;
}

void die(int index) {
    Organism dead = organisms[index];
    for (int i = index; i < numOrganisms - 1; i++) {
        organisms[i] = organisms[i + 1];
    }
    numOrganisms--;
    printf("Organism %d (%c) has died at age %d.\n", dead.id, dead.type, dead.age);
}

void simulateEpoch() {
    int numPrey = 0;
    int numPredators = 0;

    // Age and check if organisms survive
    for (int i = 0; i < numOrganisms; i++) {
        Organism *o = &organisms[i];
        o->age++;
        if (o->type == 'P') {
            if (((double)rand() / RAND_MAX) < DEATH_RATE) {
                die(i);
                i--; // Adjust index due to element deletion
                continue;
            }
            numPredators++;
        } else {
            if (((double)rand() / RAND_MAX) < DEATH_RATE) {
                die(i);
                i--; // Adjust index due to element deletion
                continue;
            }
            numPrey++;
        }
    }

    // Reproduce predators
    double meanPredatorFitness = getMeanFitness('P');
    int numPredatorOffspring = (int)(meanPredatorFitness * numPredators * BIRTH_RATE);
    reproduce(numPredatorOffspring, 'P', 0);

    // Reproduce prey
    double meanPreyFitness = getMeanFitness('D');
    int numPreyOffspring = (int)(meanPreyFitness * numPrey * BIRTH_RATE);
    reproduce(numPreyOffspring, 'D', 0);

    // Check for predation
    for (int i = 0; i < numOrganisms; i++) {
        if (organisms[i].type == 'P') {
            continue;
        }
        for (int j = 0; j < numOrganisms; j++) {
            if (i == j || organisms[j].type == 'D') {
                continue;
            }
            if (((double)rand() / RAND_MAX) < PREDATION_RATE) {
                printf("Predator %d has caught prey %d and gains fitness.\n", organisms[i].id, organisms[j].id);
                organisms[i].fitness += 0.1;
                die(j);
                j--; // Adjust index due to element deletion
            }
        }
    }
}

int main() {
    srand(time(NULL));

    // Initialize organisms
    reproduce(INITIAL_PREY, 'D', 0);
    reproduce(INITIAL_PREDATORS, 'P', 0);

    // Simulate ecosystem
    for (int epoch = 0; epoch < MAX_EPOCHS; epoch++) {
        printf("Year %d, Epoch %d\n", getCurrentYear(), epoch);
        simulateEpoch();
    }
  
    return 0;
}