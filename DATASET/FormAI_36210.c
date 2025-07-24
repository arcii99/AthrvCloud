//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

// Constants for directions
#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'

// Struct for Vehicle
struct vehicle {
    int x;
    int y;
};

// Function to display the Vehicle
void displayVehicle(struct vehicle car) {
    system("clear"); // Clearing the console
    printf("\t\tRemote Control Vehicle Simulation\n\n");
    for(int i = 0; i < 20; i++) {
        for(int j = 0; j < 20; j++) {
            if(i == car.y && j == car.x)
                printf("O");
            else
                printf(".");
        }
        printf("\n");
    }
}

int main() {
    struct vehicle car = {10, 10}; // Initializing the vehicle
    bool running = true; // Flag to run the loop
    char input; // To get input from user

    displayVehicle(car); // Displaying the initial state of vehicle

    while(running) {
        input = getchar(); // Getting input

        switch(input) {
            case UP: 
                if(car.y > 0) // Checking boundaries
                    car.y--;
                break;

            case DOWN:
                if(car.y < 19) // Checking boundaries
                    car.y++;
                break;

            case LEFT:
                if(car.x > 0) // Checking boundaries
                    car.x--;
                break;

            case RIGHT:
                if(car.x < 19) // Checking boundaries
                    car.x++;
                break;

            default:
                running = false; // Exit the loop
                break;
        }

        displayVehicle(car); // Displaying the updated state of vehicle
    }

    printf("Simulation ended.\n");

    return 0;
}