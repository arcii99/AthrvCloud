//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int speed = 0; // initialize speed
    srand(time(NULL)); // seed random number generator

    printf("Remote Control Vehicle Simulation Program\n");

    while(1) { // infinite loop
        printf("Current speed: %d\n", speed);

        printf("Enter a command: ");
        char command = getchar(); // get user input

        if(command == 's') { // stop command
            speed = 0;
            printf("Vehicle stopped.\n");
        }
        else if(command == 'a') { // accelerate command
            int accel = rand() % 11; // generate random acceleration between 0 and 10
            speed += accel;
            printf("Vehicle accelerated by %d to %d.\n", accel, speed);
        }
        else if(command == 'd') { // decelerate command
            int decel = rand() % 11; // generate random deceleration between 0 and 10
            if(decel > speed) { // prevent negative speed
                speed = 0;
            }
            else {
                speed -= decel;
            }
            printf("Vehicle decelerated by %d to %d.\n", decel, speed);
        }
        else { // invalid command
            printf("Invalid command. Try again.\n");
        }

        while(getchar() != '\n'); // clear input buffer
    }

    return 0;
}