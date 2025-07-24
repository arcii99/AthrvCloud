//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_PLANETS 10

// Define struct for planet
typedef struct Planet {
    char name[20];
    int distance;
    bool visited;
} Planet;

// Function to initialize planets with random values
void initialize_planets(Planet planets[]) {
    for (int i = 0; i < MAX_PLANETS; i++) {
        sprintf(planets[i].name, "Planet %d", i+1);
        planets[i].distance = rand() % 1000 + 1;
        planets[i].visited = false;
    }
}

// Function to print planet information
void print_planet_info(Planet planet) {
    printf("Name: %s\tDistance: %d km\tVisited: %s\n", planet.name, planet.distance, planet.visited ? "Yes" : "No");
}

// Function to print all planet information
void print_all_planets(Planet planets[]) {
    printf("\n------------------\n");
    printf("All Planets\n");
    printf("------------------\n");
    for (int i = 0; i < MAX_PLANETS; i++) {
        print_planet_info(planets[i]);
    }
}

// Function to find the closest unvisited planet
Planet find_closest_planet(Planet planets[]) {
    int min_distance = 1000;
    int index = 0;
    for (int i = 0; i < MAX_PLANETS; i++) {
        if (!planets[i].visited && planets[i].distance < min_distance) {
            min_distance = planets[i].distance;
            index = i;
        }
    }
    planets[index].visited = true;
    return planets[index];
}

int main() {
    Planet planets[MAX_PLANETS];
    
    // Initialize planets
    initialize_planets(planets);
    
    // Print all planet information
    print_all_planets(planets);
    
    // Start the space adventure!
    printf("\nStarting Space Adventure!\n");
    printf("You are currently on Earth\n");
    Planet current_planet = planets[0];
    print_planet_info(current_planet);
    
    // Loop until all planets have been visited
    for (int i = 0; i < MAX_PLANETS-1; i++) {
        Planet next_planet = find_closest_planet(planets);
        printf("Traveling to %s...\n", next_planet.name);
        current_planet = next_planet;
        print_planet_info(current_planet);
    }
    
    // End the space adventure
    printf("\nCongratulations! You have completed your space adventure!\n");
    printf("All planets have been visited.\n");
    
    return 0;
}