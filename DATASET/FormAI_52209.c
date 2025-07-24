//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_PLANETS 10

// Define Planet struct
typedef struct Planet {
    char name[20];
    int distance;
} Planet;

// Function to randomly generate planets
void generate_planets(Planet planets[]) {
    char planet_names[MAX_PLANETS][20] =
        {"Mercury", "Venus", "Earth", "Mars", "Jupiter",
         "Saturn", "Uranus", "Neptune", "Pluto", "Exoplanet"};
    int distances[MAX_PLANETS] =
        {25, 50, 75, 100, 150, 200, 250, 300, 400, 500};

    // Shuffle planet names
    for (int i = 0; i < MAX_PLANETS; i++) {
        int random_index = rand() % MAX_PLANETS;
        char temp[20];
        strcpy(temp, planet_names[i]);
        strcpy(planet_names[i], planet_names[random_index]);
        strcpy(planet_names[random_index], temp);
    }

    // Assign planet info
    for (int i = 0; i < MAX_PLANETS; i++) {
        strcpy(planets[i].name, planet_names[i]);
        planets[i].distance = distances[i];
    }
}

int main() {
    srand(time(NULL));

    int current_planet = 0;
    Planet planets[MAX_PLANETS];
    generate_planets(planets);

    printf("Welcome to Procedural Space Adventure!\n");
    printf("Your current location is planet %s, which is %d light years away.\n",
            planets[current_planet].name, planets[current_planet].distance);

    while (1) {
        int choice;
        printf("What do you want to do?\n");
        printf("1. Travel to another planet\n");
        printf("2. Quit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int destination_planet;
            do {
                destination_planet = rand() % MAX_PLANETS;
            } while (destination_planet == current_planet);

            printf("Travelling from planet %s to planet %s...\n\n",
                    planets[current_planet].name, planets[destination_planet].name);
            current_planet = destination_planet;
            printf("You have arrived at planet %s, which is %d light years away.\n",
                    planets[current_planet].name, planets[current_planet].distance);
        }
        else if (choice == 2) {
            printf("Goodbye! Thanks for playing Procedural Space Adventure.\n");
            break;
        }
        else {
            printf("Invalid input. Please try again.\n");
        }
    }

    return 0;
}