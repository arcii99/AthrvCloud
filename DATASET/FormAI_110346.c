//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: protected
#include <stdio.h>

//Defining structure for the remote control vehicle
struct Vehicle {
    int speed;
    int direction;
};

//Function to move the vehicle
void moveVehicle(struct Vehicle *vehicle) {
    printf("Vehicle moving at a speed of %d km/h and in direction %d degree.\n", vehicle->speed, vehicle->direction);
}

//Function to increase the speed of the vehicle
void accelerate(struct Vehicle *vehicle) {
    vehicle->speed += 10;
    printf("Vehicle speed increased to %d km/h.\n", vehicle->speed);
}

//Function to decrease the speed of the vehicle
void decelerate(struct Vehicle *vehicle) {
    vehicle->speed -= 10;
    printf("Vehicle speed decreased to %d km/h.\n", vehicle->speed);
}

//Function to turn the vehicle left
void turnLeft(struct Vehicle *vehicle) {
    vehicle->direction -= 30;
    printf("Vehicle turned left to direction %d degree.\n", vehicle->direction);
}

//Function to turn the vehicle right
void turnRight(struct Vehicle *vehicle) {
    vehicle->direction += 30;
    printf("Vehicle turned right to direction %d degree.\n", vehicle->direction);
}

//Main function to test the vehicle simulation
int main() {
    struct Vehicle vehicle = {0, 0}; //Initializing the vehicle with speed and direction as 0
    char choice;

    printf("Welcome to the Remote Control Vehicle Simulation Program!\n");
    printf("Press 'm' to move the vehicle.\n");
    printf("Press 'a' to accelerate the vehicle.\n");
    printf("Press 'd' to decelerate the vehicle.\n");
    printf("Press 'l' to turn the vehicle left.\n");
    printf("Press 'r' to turn the vehicle right.\n");

    do {
        printf("\nEnter your choice:");
        scanf(" %c", &choice);

        switch (choice) {
            case 'm':
                moveVehicle(&vehicle);
                break;

            case 'a':
                accelerate(&vehicle);
                break;

            case 'd':
                decelerate(&vehicle);
                break;

            case 'l':
                turnLeft(&vehicle);
                break;

            case 'r':
                turnRight(&vehicle);
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 'q'); //Loop until user enters 'q' to quit

    printf("Exiting the program. Thank you!\n");

    return 0;
}