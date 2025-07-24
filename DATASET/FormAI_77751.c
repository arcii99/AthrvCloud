//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Structure for holding information about a space ship
struct SpaceShip {
    int fuel;
    int oxygen;
    int health;
    int positionX;
    int positionY;
};

// Function for calculating distance between two points
double calculateDistance(int x1, int y1, int x2, int y2)
{
    double distance = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
    return distance;
}

int main()
{
    // Initialize random seed
    srand(time(NULL));

    // Initialize space ship
    struct SpaceShip spaceShip;
    spaceShip.fuel = 100;
    spaceShip.oxygen = 100;
    spaceShip.health = 100;
    spaceShip.positionX = rand() % 1000;
    spaceShip.positionY = rand() % 1000;

    // Initialize target planet
    int planetX = rand() % 1000;
    int planetY = rand() % 1000;

    // Display mission information
    printf("Welcome to the Space Adventure Game!\n");
    printf("Your mission is to travel to planet (%d, %d)\n", planetX, planetY);
    printf("Your starting position is (%d, %d)\n", spaceShip.positionX, spaceShip.positionY);
    printf("You have 100 units of fuel and oxygen and 100 points of health\n");

    // Start game loop
    while (spaceShip.health > 0 && spaceShip.fuel > 0 && spaceShip.oxygen > 0) {
        // Ask user for next move
        char move;
        printf("Enter your next move (a for left, d for right, w for up, s for down): ");
        scanf(" %c", &move);

        // Update spaceship position
        switch (move) {
            case 'a':
                spaceShip.positionX -= 10;
                break;
            case 'd':
                spaceShip.positionX += 10;
                break;
            case 'w':
                spaceShip.positionY += 10;
                break;
            case 's':
                spaceShip.positionY -= 10;
                break;
            default:
                printf("Invalid move!\n");
                break;
        }

        // Calculate distance between spaceship and target planet
        double distanceToPlanet = calculateDistance(spaceShip.positionX, spaceShip.positionY, planetX, planetY);

        // Calculate fuel and oxygen consumption
        int fuelConsumption = (int)ceil(distanceToPlanet / 10.0);
        int oxygenConsumption = (int)ceil(distanceToPlanet / 20.0);

        // Update fuel, oxygen, and health levels
        spaceShip.fuel -= fuelConsumption;
        spaceShip.oxygen -= oxygenConsumption;
        spaceShip.health -= (int)(distanceToPlanet / 50.0);

        // Display current status of spaceship
        printf("Fuel: %d\n", spaceShip.fuel);
        printf("Oxygen: %d\n", spaceShip.oxygen);
        printf("Health: %d\n", spaceShip.health);
        printf("Current Position: (%d, %d)\n", spaceShip.positionX, spaceShip.positionY);

        // Check if spaceship has reached target planet
        if (distanceToPlanet <= 0.0) {
            printf("Congratulations! You have reached planet (%d, %d)\n", planetX, planetY);
            break;
        }
    }

    // Check reason for game over
    if (spaceShip.fuel <= 0) {
        printf("Game over! You ran out of fuel\n");
    } else if (spaceShip.oxygen <= 0) {
        printf("Game over! You ran out of oxygen\n");
    } else if (spaceShip.health <= 0) {
        printf("Game over! Your spaceship was destroyed\n");
    }

    return 0;
}