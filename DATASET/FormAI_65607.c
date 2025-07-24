//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PLANETS 10
#define MAX_NAME_LENGTH 20

// struct to hold information about each planet
struct planet {
    char name[MAX_NAME_LENGTH];
    int x_coord;
    int y_coord;
};

// initialize the array of planets
struct planet planets[MAX_PLANETS] = {
    {"Terra", 10, 5},
    {"Zion", -5, 12},
    {"New Tokyo", -8, -3},
    {"Neo Mumbai", 2, -6},
    {"Hyperspace Station", 0, 0},
    {"Barsoom", -15, 8},
    {"Nexus", 3, 9},
    {"Avalon", -4, 5},
    {"Gaia", 10, 20},
    {"Rapture", -12, -10}
};

// function to print the available planets
void print_planets() {
    printf("Available planets:\n");
    for (int i=0; i<MAX_PLANETS; i++) {
        printf("%d. %s\n", i+1, planets[i].name);
    }
}

// function to check if a planet exists
bool planet_exists(char* name) {
    for (int i=0; i<MAX_PLANETS; i++) {
        if (strcmp(planets[i].name, name) == 0) {
            return true;
        }
    }
    return false;
}

// function to calculate the distance between two planets
float distance_between(struct planet planet1, struct planet planet2) {
    int x_diff = planet1.x_coord - planet2.x_coord;
    int y_diff = planet1.y_coord - planet2.y_coord;
    return sqrt(x_diff*x_diff + y_diff*y_diff);
}

int main() {

    int choice;

    printf("Welcome to CyberSpace!\n");
    printf("You are the captain of the spaceship Tycho Brahe.\n");
    printf("What would you like to do?\n");

    do {
        printf("\n1. List available planets\n");
        printf("2. Travel to a planet\n");
        printf("3. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            // List available planets
            case 1:
                print_planets();
                break;

            // Travel to a planet
            case 2:
                char destination[MAX_NAME_LENGTH];
                printf("Enter the name of the planet you want to travel to: ");
                scanf("%s", destination);

                if (!planet_exists(destination)) {
                    printf("Planet not found.\n");
                } else {
                    for (int i=0; i<MAX_PLANETS; i++) {
                        if (strcmp(planets[i].name, destination) == 0) {
                            float distance = distance_between(planets[i], planets[MAX_PLANETS-1]);
                            printf("Traveling to %s...\n", destination);
                            printf("Arrived at %s after traveling %.2f units of distance.\n", destination, distance);
                        }
                    }
                }
                break;

            // Quit
            case 3:
                printf("Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    } while (true);

    return 0;
}