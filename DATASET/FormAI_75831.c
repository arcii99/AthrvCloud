//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLANETS 10
#define MAX_NAME_LENGTH 20
#define MAX_DISTANCE 10000

struct Planet {
    char name[MAX_NAME_LENGTH];
    int distance;
};

typedef struct Planet Planet;

void initPlanets(Planet *planets) {
    char *names[MAX_PLANETS] = {"Vulcan", "Orion", "Tatooine", "Pandora", "Alderaan", "Mars", "Jupiter", "Saturn", "Neptune", "Pluto"};

    for (int i = 0; i < MAX_PLANETS; i++) {
        planets[i].distance = rand() % MAX_DISTANCE;
        strcpy(planets[i].name, names[i]);
    }
}

void displayPlanets(Planet *planets) {
    printf("List of planets:\n");

    for (int i = 0; i < MAX_PLANETS; i++) {
        printf("%d. %s - %d light years away\n", i+1, planets[i].name, planets[i].distance);
    }
}

void travelToPlanet(char *name, Planet *planets) {
    int found = 0;

    for (int i = 0; i < MAX_PLANETS; i++) {
        if (strcmp(name, planets[i].name) == 0) {
            printf("Traveling to planet %s...\n", planets[i].name);
            printf("Arrived at planet %s (%d light years away)!\n", planets[i].name, planets[i].distance);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Planet not found. Try again.\n");
    }
}

int main() {
    srand(time(NULL));
    
    Planet planets[MAX_PLANETS];
    initPlanets(planets);
    displayPlanets(planets);

    printf("Enter planet name to travel to: ");
    char input[MAX_NAME_LENGTH];
    fgets(input, MAX_NAME_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0';

    travelToPlanet(input, planets);

    return 0;
}