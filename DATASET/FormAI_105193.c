//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Alan Touring
#include <stdio.h>

// define the structure of a remote control vehicle
typedef struct {
    int speed;
    int direction;
} rc_vehicle;

// define the main function
int main() {
    // initialize a remote control vehicle with 0 speed and direction
    rc_vehicle my_vehicle = {0, 0};

    // prompt the user to enter a speed and direction
    printf("Enter speed (1-10): ");
    scanf("%d", &my_vehicle.speed);
    printf("Enter direction (0-360): ");
    scanf("%d", &my_vehicle.direction);

    // simulate the movement of the vehicle
    printf("Vehicle moving at speed %d in direction %d degrees.\n", my_vehicle.speed, my_vehicle.direction);
    printf("Press a key to change direction.\n");
    getchar(); // discard the newline character left in the input buffer
    getchar(); // wait for the user to press a key
    printf("Enter new direction (0-360): ");
    scanf("%d", &my_vehicle.direction);
    printf("Vehicle now moving at speed %d in direction %d degrees.\n", my_vehicle.speed, my_vehicle.direction);

    // simulate stopping the vehicle
    printf("Press a key to stop the vehicle.\n");
    getchar(); // discard the newline character left in the input buffer
    getchar(); // wait for the user to press a key
    printf("Vehicle stopped.\n");
    my_vehicle.speed = 0;

    // show the final state of the vehicle
    printf("Vehicle is now at speed %d in direction %d degrees.\n", my_vehicle.speed, my_vehicle.direction);

    // end the program
    return 0;
}