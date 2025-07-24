//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));

    printf("Welcome to the Procedural Space Adventure!\n\n");

    // Generate a random planet name
    char planet[10];
    switch (rand() % 10) {
        case 0:
            sprintf(planet, "Mercury");
            break;
        case 1:
            sprintf(planet, "Venus");
            break;
        case 2:
            sprintf(planet, "Earth");
            break;
        case 3:
            sprintf(planet, "Mars");
            break;
        case 4:
            sprintf(planet, "Jupiter");
            break;
        case 5:
            sprintf(planet, "Saturn");
            break;
        case 6:
            sprintf(planet, "Uranus");
            break;
        case 7:
            sprintf(planet, "Neptune");
            break;
        case 8:
            sprintf(planet, "Pluto");
            break;
        case 9:
            sprintf(planet, "Alpha Centauri");
            break;
    }

    printf("You have arrived on planet %s!\n", planet);

    // Generate a random event
    int eventNum = rand() % 3;
    switch (eventNum) {
        case 0:
            printf("You have discovered a hidden cave system full of precious gems! You collect enough gems to retire on a beach planet.\n");
            break;
        case 1:
            printf("You spot a friendly alien who offers to guide you to the nearest space station. He repairs your ship and gives you a snack.\n");
            break;
        case 2:
            printf("As you investigate a strange signal on the planet's surface, you are ambushed by a group of hostile aliens. You fend them off with your laser gun.\n");
            break;
    }

    printf("Thanks for playing the Procedural Space Adventure!\n");

    return 0;
}