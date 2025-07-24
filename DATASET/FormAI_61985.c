//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate a random number between min and max (inclusive)
int getRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to display the status of the ship
void displayShipStatus(int fuel, int oxygen, int food, int distance) {
    printf("\n---------------------\n");
    printf("FUEL: %d units\n", fuel);
    printf("OXYGEN: %d units\n", oxygen);
    printf("FOOD: %d units\n", food);
    printf("DISTANCE TRAVELED: %d lightyears\n", distance);
    printf("---------------------\n\n");
}

int main() {
    int fuel = 100;
    int oxygen = 100;
    int food = 100;
    int distance = 0;
    int chanceOfEvent = 25; // Chance of encountering an event (out of 100)
    
    srand(time(NULL)); // Seed the random number generator
    
    printf("WELCOME TO PROCEDURAL SPACE ADVENTURE!\n");
    printf("You are the captain of the Starship Odyssey, on its maiden voyage through the galaxy.\n");
    printf("Your mission is to reach the end of the galaxy without running out of fuel, oxygen, or food.\n\n");
    
    while (fuel > 0 && oxygen > 0 && food > 0 && distance < 1000) {
        displayShipStatus(fuel, oxygen, food, distance);
        
        // Random event
        if (getRandomNumber(1, 100) <= chanceOfEvent) {
            int event = getRandomNumber(1, 5);
            printf("A wild event appears!\n");
            switch (event) {
                case 1: // Asteroid belt
                    printf("You encounter an asteroid belt...\n");
                    printf("Your ship takes some damage, and you lose some fuel and oxygen.\n");
                    fuel -= getRandomNumber(10, 20);
                    oxygen -= getRandomNumber(10, 20);
                    break;
                case 2: // Space pirates
                    printf("You encounter some space pirates...\n");
                    printf("You engage in a battle, and some of your crew members are injured.\n");
                    fuel -= getRandomNumber(5, 10);
                    oxygen -= getRandomNumber(5, 10);
                    break;
                case 3: // Space whales
                    printf("You encounter some space whales...\n");
                    printf("Your crew members are in awe of the majestic creatures.\n");
                    food -= getRandomNumber(5, 10);
                    break;
                case 4: // Black hole
                    printf("You encounter a black hole...\n");
                    printf("You have to navigate carefully to avoid being sucked in.\n");
                    fuel -= getRandomNumber(20, 30);
                    oxygen -= getRandomNumber(20, 30);
                    break;
                case 5: // Alien planet
                    printf("You encounter an alien planet...\n");
                    printf("You decide to land and explore.\n");
                    food -= getRandomNumber(10, 20);
                    break;
            }
        }
        else {
            printf("You continue on your journey through space...\n");
            fuel -= getRandomNumber(5, 15);
            oxygen -= getRandomNumber(5, 15);
            food -= getRandomNumber(5, 15);
            distance += getRandomNumber(50, 100);
        }
        
        // Check if any resources have run out
        if (fuel <= 0 || oxygen <= 0 || food <= 0) {
            printf("Oh no! You have run out of a critical resource.\n");
            printf("Your ship has been lost in space forever...\n");
            break;
        }
        
        // Check if the ship has reached the end of the galaxy
        if (distance >= 1000) {
            printf("Congratulations! You have reached the end of the galaxy.\n");
            printf("Your voyage has been a success!\n");
            break;
        }
        
        // Wait for user to press enter before continuing
        printf("Press enter to continue...\n");
        getchar();
    }
    
    printf("\nThanks for playing PROCEDURAL SPACE ADVENTURE!\n\n");
    
    return 0;
}