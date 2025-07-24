//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to calculate distance between two points in 3D space
double getDistance(double x1, double y1, double z1, double x2, double y2, double z2) {
    double distance;
    distance = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2) + pow((z1 - z2), 2));
    return distance;
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    
    // Initialize variables
    double x = 0, y = 0, z = 0, speed = 0, distance = 0, time = 0, fuel = 100, fuelBurn = 0, planetX, planetY, planetZ;
    int numPlanets = 5, planetIndex = 0;
    char planets[5][20] = {"Mercury", "Mars", "Jupiter", "Saturn", "Uranus"};
    
    printf("Welcome to the Procedural Space Adventure game!\n");
    printf("You are currently at (%.2f, %.2f, %.2f) in space.\n", x, y, z);
    printf("You have a full tank of fuel to begin your journey.\n");
    
    for(int i=0; i<10; i++) { // Loop for 10 turns
        
        planetIndex = rand() % numPlanets; // Choose a random planet to travel to
        printf("\nTurn %d:\n", i+1);
        printf("Your destination is planet %s!\n", planets[planetIndex]);
        
        planetX = (double) rand() / RAND_MAX * 100; // Generate a random coordinate for the planet
        planetY = (double) rand() / RAND_MAX * 100;
        planetZ = (double) rand() / RAND_MAX * 100;
        printf("The planet is located at (%.2f, %.2f, %.2f).\n", planetX, planetY, planetZ);
        
        distance = getDistance(x, y, z, planetX, planetY, planetZ); // Calculate the distance to the planet
        printf("The distance to the planet is %.2f.\n", distance);
        
        // Calculate the time it will take to travel to the planet
        speed = (double) rand() / RAND_MAX * 10;
        time = distance / speed;
        printf("Your speed is %.2f and it will take %.2f units of time to reach the planet.\n", speed, time);
        
        // Calculate the amount of fuel it will take to travel to the planet
        fuelBurn = distance / (double) rand() / RAND_MAX * 50;
        while(fuelBurn > fuel) { // Check if there is enough fuel
            printf("You don't have enough fuel!\n");
            fuelBurn = distance / (double) rand() / RAND_MAX * 50;
        }
        fuel -= fuelBurn;
        printf("You burned %.2f units of fuel to reach the planet, and you have %.2f units of fuel left.\n", fuelBurn, fuel);
        
        // Move to the planet
        x = planetX;
        y = planetY;
        z = planetZ;
        printf("You have arrived at the planet!\n");
        printf("You are now at (%.2f, %.2f, %.2f).\n", x, y, z);
    }
    
    printf("\nCongratulations, you have completed the Procedural Space Adventure game!");
    return 0;
}