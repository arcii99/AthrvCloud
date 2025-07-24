//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ALIEN_TYPES 3 // Three types of aliens: Grays, Reptilians, and Insectoids
#define MILITARY_STRENGTH 10 // Maximum military strength on a scale of 1 to 10
#define PROBABILITY_THRESHOLD 0.5 // Maximum acceptable probability of alien invasion
#define PLANET_POPULATION 7000000000 // Current human population on Earth

// Structure to hold alien type, military strength, and invasion probability
typedef struct {
    char* type;
    int military_strength;
    double invasion_probability;
} Alien;

// Function to calculate invasion probability based on alien type and military strength
double calculate_invasion_prob(int alien_type, int military_strength) {
    double base_prob;
    switch(alien_type) {
        case 1: // Grays
            base_prob = 0.8;
            break;
        case 2: // Reptilians
            base_prob = 0.6;
            break;
        case 3: // Insectoids
            base_prob = 0.4;
            break;
        default:
            printf("Invalid alien type!\n");
            exit(1);
    }
    // Calculate final invasion probability based on military strength
    return base_prob * (double)military_strength / (double)MILITARY_STRENGTH;
}

int main() {
    srand(time(NULL)); // Initialize random number generator
    Alien aliens[ALIEN_TYPES]; // Array to hold all alien types
    aliens[0].type = "Grays";
    aliens[1].type = "Reptilians";
    aliens[2].type = "Insectoids";

    // Generate random military strengths for each alien type
    int i;
    for (i = 0; i < ALIEN_TYPES; i++) {
        aliens[i].military_strength = rand() % MILITARY_STRENGTH + 1;
    }

    // Calculate invasion probability for each alien type
    for (i = 0; i < ALIEN_TYPES; i++) {
        aliens[i].invasion_probability = calculate_invasion_prob(i+1, aliens[i].military_strength);
    }

    // Print out alien types, military strengths, and invasion probabilities
    printf("Alien Types\t|\tMilitary Strength\t|\tInvasion Probability\n");
    printf("----------------------------------------------------------------\n");
    for (i = 0; i < ALIEN_TYPES; i++) {
        printf("%s\t|\t%d\t\t\t|\t%.2f\n", aliens[i].type, aliens[i].military_strength, aliens[i].invasion_probability);
    }

    // Calculate overall invasion probability by taking the average of all alien probabilities
    double overall_prob = 0;
    for (i = 0; i < ALIEN_TYPES; i++) {
        overall_prob += aliens[i].invasion_probability;
    }
    overall_prob /= ALIEN_TYPES;

    printf("Overall invasion probability: %.2f\n", overall_prob);

    // Determine if alien invasion is likely based on overall probability
    if (overall_prob > PROBABILITY_THRESHOLD) {
        printf("Alien invasion is likely!\n");
        // Calculate how many humans would survive the invasion
        int survivors = PLANET_POPULATION * (1 - overall_prob);
        printf("Approximately %d humans would survive the invasion.\n", survivors);
    } else {
        printf("Alien invasion is not likely.\n");
    }

    return 0;
}