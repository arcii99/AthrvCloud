//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void warpDrive() {
    time_t t;
    srand((unsigned) time(&t));
    int random = rand() % 100 + 1;
    if (random <= 25) {
        printf("Warp drive malfunction detected. Initiating emergency shutdown.\n");
        exit(0);
    }
    printf("Warp drive engaged. Bringing systems online.\n");
    // ... more code to engage warp drive
}

void scanPlanet() {
    printf("Scanning nearby planets for signs of life...\n");
    // ... more code to scan planets
}

void fireLasers() {
    printf("Firing lasers to defend against hostile alien ships!\n");
    // ... more code to fire lasers
}

void landOnPlanet() {
    printf("Landing on planet...\n");
    // ... more code to land on planet
}

void takeOff() {
    printf("Taking off from planet...\n");
    // ... more code to take off from planet
}

int main() {
    printf("Welcome to the Procedural Space Adventure!\n");
    printf("Your mission is to explore the galaxy and make new discoveries.\n");
    printf("Let's begin!\n");

    warpDrive();
    scanPlanet();

    printf("Approaching a nearby asteroid belt...\n");
    // ... more code to navigate asteroid belt

    fireLasers();
    scanPlanet();

    printf("Entering a mysterious nebula...\n");
    // ... more code to navigate nebula

    landOnPlanet();

    printf("Exploring the planet...\n");
    // ... more code to explore planet

    takeOff();

    printf("Continuing on to the next destination...\n");
    // ... more code to travel to next destination

    printf("Congratulations! You have successfully completed your mission.\n");
    return 0;
}