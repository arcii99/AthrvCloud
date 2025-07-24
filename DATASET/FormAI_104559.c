//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main() {

    // Declare and initialize variables for remote control vehicle simulation
    int speed = 0; // Speed of vehicle in mph
    int direction = 0; // Direction of vehicle in degrees
    int batteryLife = 100; // Percentage of battery life remaining
    char power = 'on'; // Power status of vehicle
    char input; // User input for controlling vehicle

    // Display welcome message and initial vehicle information
    printf("Welcome to the remote control vehicle simulation!\n\n");
    printf("Current vehicle information:\n");
    printf("Speed: %d mph\n", speed);
    printf("Direction: %d degrees\n", direction);
    printf("Battery life: %d%%\n", batteryLife);
    printf("Power status: %c\n\n", power);

    // Loop through user input for controlling vehicle
    while (power == 'on') {
        printf("Enter a command (w = increase speed, s = decrease speed, a = turn left, d = turn right, x = power off): ");
        scanf("%c", &input);

        // Check user input and change vehicle parameters accordingly
        switch(input) {
            case 'w':
                if (speed + 10 > 60) {
                    printf("Max speed reached!\n");
                    speed = 60;
                } else {
                    speed += 10;
                    printf("Speed increased to %d mph.\n", speed);
                }
                break;
            case 's':
                if (speed - 10 < 0) {
                    printf("Vehicle stopped.\n");
                    speed = 0;
                } else {
                    speed -= 10;
                    printf("Speed decreased to %d mph.\n", speed);
                }
                break;
            case 'a':
                direction = (direction - 15) % 360;
                printf("Vehicle turned left to %d degrees.\n", direction);
                break;
            case 'd':
                direction = (direction + 15) % 360;
                printf("Vehicle turned right to %d degrees.\n", direction);
                break;
            case 'x':
                power = 'off';
                printf("Vehicle powered off.\n");
                break;
            default:
                printf("Invalid command.\n");
                break;
        }

        // Calculate battery life based on vehicle speed and display new vehicle information
        batteryLife -= speed / 10;
        if (batteryLife <= 0) {
            printf("Battery dead! Vehicle powered off.\n");
            power = 'off';
        } else {
            printf("Current vehicle information:\n");
            printf("Speed: %d mph\n", speed);
            printf("Direction: %d degrees\n", direction);
            printf("Battery life: %d%%\n", batteryLife);
            printf("Power status: %c\n\n", power);
        }
        
        // Clear input buffer
        fflush(stdin);
    }

    return 0;

}