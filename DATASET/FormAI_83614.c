//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLANETS 10  // Maximum number of planets in the universe
#define MAX_NAME_LEN 20 // Maximum length of planet name

typedef struct {
    char name[MAX_NAME_LEN];
    int distance; // Distance from the starting planet
    int visited;  // Flag to mark whether the planet has been visited or not
} Planet;

void print_planet(Planet *p) {
    printf("%s (Distance: %d)\n", p->name, p->distance);
}

void print_planets(Planet planets[], int num_planets) {
    for (int i = 0; i < num_planets; i++) {
        printf("%d. ", i + 1);
        print_planet(&planets[i]);
    }
}

void generate_planet_name(char *name, int len) {
    const char *letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < len; i++) {
        name[i] = letters[rand() % strlen(letters)];
    }
    name[len] = '\0';
}

void generate_planet_distances(Planet planets[], int num_planets) {
    int max_distance = num_planets * 10;
    for (int i = 0; i < num_planets; i++) {
        planets[i].distance = rand() % max_distance + 1;
    }
}

void initialize_universe(Planet planets[], int num_planets) {
    for (int i = 0; i < num_planets; i++) {
        generate_planet_name(planets[i].name, MAX_NAME_LEN - 1);
        planets[i].visited = 0;
    }
    generate_planet_distances(planets, num_planets);
}

Planet *get_starting_planet(Planet planets[], int num_planets) {
    int i = rand() % num_planets;
    return &planets[i];
}

int get_nearest_planet_index(Planet planets[], int num_planets, int current_index) {
    int min_distance = -1;
    int min_index = -1;
    for (int i = 0; i < num_planets; i++) {
        if (!planets[i].visited && (min_distance == -1 || planets[i].distance < min_distance)) {
            min_distance = planets[i].distance;
            min_index = i;
        }
    }
    return min_index;
}

void travel_to_planet(Planet *current_planet, Planet *destination_planet) {
    printf("Travelling from %s to %s...\n", current_planet->name, destination_planet->name);
    current_planet->visited = 1;
    destination_planet->visited = 1;
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time
    int num_planets = rand() % MAX_PLANETS + 1;
    Planet planets[num_planets];
    initialize_universe(planets, num_planets);
    printf("Welcome to the Procedural Space Adventure!\n");
    printf("Your mission is to travel to each planet in the universe.\n");
    printf("There are %d planets in the universe, and you are starting on:\n", num_planets);
    Planet *current_planet = get_starting_planet(planets, num_planets);
    print_planet(current_planet);
    printf("Let the adventure begin!\n");
    for (int i = 0; i < num_planets - 1; i++) {
        int next_planet_index = get_nearest_planet_index(planets, num_planets, current_planet - planets);
        Planet *next_planet = &planets[next_planet_index];
        travel_to_planet(current_planet, next_planet);
        current_planet = next_planet;
        printf("You have arrived at:\n");
        print_planet(current_planet);
        printf("You have %d more planets to visit.\n", num_planets - i - 2);
    }
    printf("Congratulations! You have visited every planet in the universe!\n");
    return 0;
}