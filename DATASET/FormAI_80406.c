//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Create a struct to hold information about planets
typedef struct {
    char name[20];
    int x;
    int y;
    int resources;
} Planet;

// Create a function that generates a random planet
Planet generate_planet() {
    Planet planet;
    char names[10][20] = {"Alpha", "Beta", "Gamma", "Delta", "Epsilon", "Zeta", "Eta", "Theta", "Iota", "Kappa"};
    int rand_idx = rand() % 10;
    sprintf(planet.name, "%s %d", names[rand_idx], rand() % 100);
    planet.x = rand() % 100;
    planet.y = rand() % 100;
    planet.resources = rand() % 1000;
    return planet;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Generate some planets
    Planet planets[5];
    for (int i = 0; i < 5; i++) {
        planets[i] = generate_planet();
    }
    
    // Print out information about the planets
    for (int i = 0; i < 5; i++) {
        printf("Planet %d: Name=%s, X=%d, Y=%d, Resources=%d\n", i+1, planets[i].name, planets[i].x, planets[i].y, planets[i].resources);
    }
    
    return 0;
}