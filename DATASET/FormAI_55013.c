//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Structure for storing the state of the remote control vehicle
struct rc_vehicle {
    int speed;
    char direction;
};

// Function for initializing the vehicle
void init(struct rc_vehicle *vehicle) {
    vehicle->speed = 0;
    vehicle->direction = 'N';
}

int main() {
    // Initializing the vehicle
    struct rc_vehicle vehicle;
    init(&vehicle);

    // Printing welcome message
    printf("Welcome to the Remote Control Vehicle Simulation!\n");

    // Main program loop
    while (1) {
        // Printing the current state of the vehicle
        printf("Current Speed: %d, Current Direction: %c\n", vehicle.speed, vehicle.direction);

        // Getting user input
        printf("Enter a command (s to increase speed, b to decrease speed, l to turn left, r to turn right, q to quit): ");
        char input = getchar();
        while (getchar() != '\n'); // Clearing input buffer

        // Parsing user input
        switch (input) {
            case 's':
                // Increasing speed
                if (vehicle.speed < 5) {
                    vehicle.speed++;
                }
                break;
            case 'b':
                // Decreasing speed
                if (vehicle.speed > 0) {
                    vehicle.speed--;
                }
                break;
            case 'l':
                // Turning left
                switch (vehicle.direction) {
                    case 'N':
                        vehicle.direction = 'W';
                        break;
                    case 'W':
                        vehicle.direction = 'S';
                        break;
                    case 'S':
                        vehicle.direction = 'E';
                        break;
                    case 'E':
                        vehicle.direction = 'N';
                        break;
                }
                break;
            case 'r':
                // Turning right
                switch (vehicle.direction) {
                    case 'N':
                        vehicle.direction = 'E';
                        break;
                    case 'E':
                        vehicle.direction = 'S';
                        break;
                    case 'S':
                        vehicle.direction = 'W';
                        break;
                    case 'W':
                        vehicle.direction = 'N';
                        break;
                }
                break;
            case 'q':
                // Quitting the program
                printf("Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid command!\n");
                break;
        }

        // Slowing down the simulation
        usleep(500000);
    }

    return 0;
}