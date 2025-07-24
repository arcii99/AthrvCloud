//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 50
#define MAX_PLANET_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char planet[MAX_PLANET_LENGTH];
    int age;
} SpaceExplorer;

void printStatus(SpaceExplorer explorer) {
    printf("%s from planet %s has an age of %d\n", explorer.name, explorer.planet, explorer.age);
}

void travelToPlanet(SpaceExplorer* explorer, char* planet) {
    strcpy(explorer->planet, planet);
    printf("%s traveled to planet %s!\n", explorer->name, planet);
}

void exploreSpace() {
    SpaceExplorer explorer;
    printf("Enter your name: ");
    scanf("%s", explorer.name);
    printf("Enter your planet of origin: ");
    scanf("%s", explorer.planet);
    printf("Enter your age: ");
    scanf("%d", &explorer.age);
    printf("Welcome %s from planet %s with an age of %d!\n", explorer.name, explorer.planet, explorer.age);

    // Travel to different planets
    travelToPlanet(&explorer, "Mars");
    travelToPlanet(&explorer, "Jupiter");
    travelToPlanet(&explorer, "Saturn");

    // Final status update
    printStatus(explorer);
}

int main() {
    printf("Starting space adventure...\n");
    exploreSpace();
    return 0;
}