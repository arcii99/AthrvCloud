//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Struct for vehicle position
typedef struct {
    int x;
    int y;
} Position;

// Struct for vehicle
typedef struct {
    char* name;
    Position position;
} Vehicle;

// Function for moving vehicle
void moveVehicle(Vehicle* vehicle, char direction) {
    switch(direction) {
        case 'U':
            vehicle->position.y += 1;
            break;
        case 'D':
            vehicle->position.y -= 1;
            break;
        case 'L':
            vehicle->position.x -= 1;
            break;
        case 'R':
            vehicle->position.x += 1;
            break;
        default:
            printf("Invalid direction. Please use U, D, L or R.");
    }
}

int main() {
    // Initializing srand() for random number generator in vehicle creation
    srand(time(NULL));

    // Creating array for vehicles (max 10)
    Vehicle vehicles[10];

    // Creating vehicles with random starting positions
    char* vehicleNames[5] = {"Car", "Truck", "Motorcycle", "Bus", "Bicycle"};
    int i;
    for (i = 0; i < 5; i++) {
        // Randomizing starting position
        Position startingPosition;
        startingPosition.x = rand() % 100;
        startingPosition.y = rand() % 100;

        // Creating vehicle with random starting position
        Vehicle newVehicle;
        newVehicle.name = vehicleNames[i];
        newVehicle.position = startingPosition;

        // Adding vehicle to array
        vehicles[i] = newVehicle;
    }

    // User interface for moving vehicles
    char userInput;
    while(1) {
        // Printing vehicle locations
        printf("Current vehicle locations:\n");
        for (i = 0; i < 5; i++) {
            printf("%s at (%d, %d)\n", vehicles[i].name, vehicles[i].position.x, vehicles[i].position.y);
        }
        printf("\n");

        // Getting user input
        printf("Move which vehicle (1-5)? ");
        char input[3];
        fgets(input, 3, stdin);
        int selectedVehicle = atoi(input) - 1;

        printf("Which direction (U, D, L, R)? ");
        scanf(" %c", &userInput);

        // Moving the vehicle
        moveVehicle(&vehicles[selectedVehicle], userInput);

        // Clearing the input buffer
        while ((getchar()) != '\n');

        // Checking if all vehicles have reached destination
        for (i = 0; i < 5; i++) {
            if (vehicles[i].position.x > 100 || vehicles[i].position.y > 100 || vehicles[i].position.x < 0 || vehicles[i].position.y < 0) {
                printf("Vehicle %s has reached its destination!\n", vehicles[i].name);
                return 0;
            }
        }
    }
}