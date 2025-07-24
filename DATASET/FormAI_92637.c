//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed the random number generator with the current time
    int distance = 0;
    int speed = 0;
    int battery = 100;

    while (1) { // infinite loop for simulation

        // print status update
        printf("Current distance: %d meters\n", distance);
        printf("Current speed: %d m/s\n", speed);
        printf("Battery remaining: %d%%\n", battery);

        // get user input for control
        printf("Enter control command ('f' for forward, 'r' for reverse, 's' for stop): ");
        char command = getchar();
        getchar(); // consume newline character

        // update based on control command
        switch (command) {
            case 'f':
                if (battery > 0) { // check if there's enough battery
                    speed += rand() % 10 + 1; // increase speed randomly between 1-10 m/s
                    distance += speed; // update distance based on speed
                    battery -= speed / 10; // consume battery based on speed
                } else {
                    printf("Out of battery!\n");
                }
                break;
            case 'r':
                if (battery > 0) { // check if there's enough battery
                    speed -= rand() % 10 + 1; // decrease speed randomly between 1-10 m/s
                    distance += speed; // update distance based on speed
                    battery -= speed / 10; // consume battery based on speed
                } else {
                    printf("Out of battery!\n");
                }
                break;
            case 's':
                speed = 0; // stop the vehicle
                break;
            default:
                printf("Invalid command!\n");
                break;
        }

        // check if the vehicle has reached the destination
        if (distance >= 500) {
            printf("Destination reached!\n");
            break; // exit the loop
        }

        // check if battery has run out and stop the vehicle
        if (battery <= 0) {
            printf("Out of battery!\n");
            speed = 0;
        }

        // delay for 1 second to simulate real-time simulation
        sleep(1);
    }

    return 0;
}