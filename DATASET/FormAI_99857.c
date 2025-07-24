//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to return random number between two integers
int getRandomNumber(int min, int max) {
    srand(time(NULL));
    int randomNumber = rand() % (max - min + 1) + min;
    return randomNumber;
}

// Function to print spaceship thrusters firing
void fireThrusters() {
    printf("       _\n");
    printf("     //|\n");
    printf("    // |\n");
    printf("   //  |\n");
    printf("  //   |\n");
    printf(" //    |\n");
    printf("//____|\n");
}

// Function to print spaceship
void printSpaceship() {
    printf("    __\n");
    printf(" __/\\_\\__\n");
    printf("/_/ | \\_\\_\\\n");
    printf("| \\_|_/ | |\n");
    printf("\\____\\/__/|\n");
    printf("|_/ \\/ \\/\n");
    printf("\\_\\|_\n");
}

int main() {
    printf("Welcome to Procedural Space Adventure!\n\n");

    // Generate random planet distance and enemy ship distance
    int planetDistance = getRandomNumber(100, 500);
    int enemyDistance = getRandomNumber(50, 200);

    printf("Planet Distance: %d Light Years\n", planetDistance);
    printf("Enemy Ship Distance: %d Light Years\n", enemyDistance);

    // Print spaceship
    printSpaceship();
    printf("\n");

    // Fire thrusters to start journey
    fireThrusters();
    printf("Initiating travel to planet...\n\n");

    // Calculate travel time based on distance
    int travelTime = planetDistance / 10;

    // Simulate travel time by sleeping for travelTime seconds
    printf("Traveling through space...\n");
    for (int i = 0; i < travelTime; i++) {
        printf(".");
        fflush(stdout);
        sleep(1);
    }
    printf("\n\n");
    printf("Arrived at planet!\n\n");

    // Print spaceship
    printSpaceship();
    printf("\n");

    // Fire thrusters to land on planet
    fireThrusters();
    printf("Landing on planet...\n\n");

    // Generate alien encounter chance
    int alienChance = getRandomNumber(0, 10);

    if (alienChance < 3) {
        // Alien encounter occurs
        printf("Alien spacecraft detected!\n");
        printf("Entering Battle Mode...\n\n");

        // Simulate battle by sleeping for 3 seconds
        printf("Firing lasers!\n");
        sleep(1);
        printf("Firing missiles!\n");
        sleep(1);
        printf("Enemy destroyed!\n\n");
    } else {
        printf("No alien spacecraft detected. Planet is safe.\n\n");
    }

    printf("Exploring planet...\n\n");
    printf("Collecting samples...\n");
    printf("Analyzing environment...\n\n");

    printf("Mission complete! Returning to Earth...\n\n");

    // Fire thrusters to take off from planet
    printSpaceship();
    printf("\n");
    fireThrusters();
    printf("Liftoff!\n\n");

    // Calculate travel time based on distance
    travelTime = planetDistance / 10;

    // Simulate travel time by sleeping for travelTime seconds
    printf("Traveling through space...\n");
    for (int i = 0; i < travelTime; i++) {
        printf(".");
        fflush(stdout);
        sleep(1);
    }
    printf("\n\n");
    printf("Enemy Ship Detected!\n");
    printf("Evading enemy...\n\n");

    // Calculate travel time based on enemy distance
    travelTime = enemyDistance / 5;

    // Simulate travel time by sleeping for travelTime seconds
    printf("Enemy evaded!\n");
    printf("Traveling through space...\n");
    for (int i = 0; i < travelTime; i++) {
        printf(".");
        fflush(stdout);
        sleep(1);
    }
    printf("\n\n");

    printf("Arrived back on Earth!\n");
    printf("Mission successful!\n");

    return 0;
}