//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants for space adventure
#define MAX_PLANETS 10
#define MAX_ENEMIES 5

// Define structures for planets and enemies
struct planet {
    char name[20];
    int size;
};

struct enemy {
    char type[20];
    int strength;
};

// Declare arrays for planets and enemies
struct planet planets[MAX_PLANETS];
struct enemy enemies[MAX_ENEMIES];

// Define function to randomly generate a planet
struct planet generate_planet() {
    struct planet p;

    // Generate a random planet name
    char planet_names[MAX_PLANETS][20] = {"Alderaan", "Tatooine", "Naboo", "Coruscant", "Dagobah", "Hoth", "Endor", "Bespin", "Yavin", "Kashyyyk"};
    int index = rand() % MAX_PLANETS;
    strcpy(p.name, planet_names[index]);

    // Generate a random planet size
    p.size = rand() % 10000;

    return p;
}

// Define function to randomly generate an enemy
struct enemy generate_enemy() {
    struct enemy e;

    // Generate a random enemy type
    char enemy_types[MAX_ENEMIES][20] = {"Stormtrooper", "Darth Vader", "Boba Fett", "Droid Army", "Sith Lord"};
    int index = rand() % MAX_ENEMIES;
    strcpy(e.type, enemy_types[index]);

    // Generate a random enemy strength
    e.strength = rand() % 100;

    return e;
}

// Main function to run the space adventure
int main() {
    srand(time(NULL)); // Seed random number generator

    // Generate random planets and enemies
    for (int i = 0; i < MAX_PLANETS; i++) {
        planets[i] = generate_planet();
    }

    for (int i = 0; i < MAX_ENEMIES; i++) {
        enemies[i] = generate_enemy();
    }

    // Print out the generated planets and enemies
    printf("Planets:\n");
    for (int i = 0; i < MAX_PLANETS; i++) {
        struct planet p = planets[i];
        printf("%s (size: %d)\n", p.name, p.size);
    }

    printf("\nEnemies:\n");
    for (int i = 0; i < MAX_ENEMIES; i++) {
        struct enemy e = enemies[i];
        printf("%s (strength: %d)\n", e.type, e.strength);
    }

    // Begin the space adventure
    printf("\nWelcome to the space adventure!\n");
    printf("You are traveling through space in your spaceship, searching for new planets to explore.\n\n");

    // Ask the user where they want to go
    printf("Where do you want to go?\n");
    for (int i = 0; i < MAX_PLANETS; i++) {
        printf("%d - %s\n", i+1, planets[i].name);
    }

    int choice;
    scanf("%d", &choice);

    struct planet destination = planets[choice-1];

    printf("\nYou have chosen to travel to %s.\n", destination.name);
    printf("It will take %d days to get there.\n\n", destination.size/100);

    // Encounter enemies on the journey
    int days_remaining = destination.size / 100;
    int enemies_encountered = 0;

    while (days_remaining > 0) {
        int roll = rand() % 100;

        if (roll < 20) {
            struct enemy enemy = generate_enemy();
            printf("You have encountered a %s!\n", enemy.type);
            printf("It has a strength of %d.\n", enemy.strength);

            int strength_needed = destination.size/100 - days_remaining + 10;

            if (enemy.strength > strength_needed) {
                printf("You lose the space battle!\n");
                break;
            } else {
                printf("You win the space battle!\n");
                enemies_encountered++;
            }
        }

        days_remaining--;
    }

    // Arrive at destination planet
    if (days_remaining == 0) {
        printf("\nYou arrive at %s!\n", destination.name);

        if (enemies_encountered > 0) {
            printf("You encountered %d enemies on your journey.\n", enemies_encountered);
        } else {
            printf("You had a safe journey with no enemies encountered.\n");
        }
    }

    return 0;
}