//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SPEED 100 // maximum speed of the vehicle
#define MAX_TURN_ANGLE 45 // maximum angle the vehicle can turn
#define MIN_DISTANCE 0.5 // minimum distance the vehicle can travel
#define MAX_DISTANCE 2.0 // maximum distance the vehicle can travel

int main() {
    int speed = 0; // current speed of the vehicle
    int angle = 0; // current angle of the vehicle
    double distance = 0.0; // current distance traveled by the vehicle

    printf("Remote Control Vehicle Simulator\n");
    printf("------------------------------\n\n");

    while (1) {
        // display current status of the vehicle
        printf("Speed: %d\nAngle: %d\nDistance: %.2f\n\n", speed, angle, distance);

        // ask for user input
        printf("Enter command (F=forward, B=backward, L=left, R=right, Q=quit): ");
        char input = getchar();

        // clear input buffer
        while (getchar() != '\n');

        // check user input
        switch (input) {
            case 'F':
            case 'f':
                // generate random distance between MIN_DISTANCE and MAX_DISTANCE
                distance += ((double)rand() / (double)RAND_MAX) * (MAX_DISTANCE - MIN_DISTANCE) + MIN_DISTANCE;
                // update speed
                speed = rand() % (MAX_SPEED + 1);
                break;
            case 'B':
            case 'b':
                // generate random distance between MIN_DISTANCE and MAX_DISTANCE
                distance -= ((double)rand() / (double)RAND_MAX) * (MAX_DISTANCE - MIN_DISTANCE) + MIN_DISTANCE;
                // update speed
                speed = -(rand() % (MAX_SPEED + 1));
                break;
            case 'L':
            case 'l':
                // generate random turn angle between -MAX_TURN_ANGLE and MAX_TURN_ANGLE
                angle += rand() % (2 * MAX_TURN_ANGLE + 1) - MAX_TURN_ANGLE;
                break;
            case 'R':
            case 'r':
                // generate random turn angle between -MAX_TURN_ANGLE and MAX_TURN_ANGLE
                angle -= rand() % (2 * MAX_TURN_ANGLE + 1) - MAX_TURN_ANGLE;
                break;
            case 'Q':
            case 'q':
                // exit program
                printf("Exiting program...\n");
                return 0;
            default:
                // invalid input, do nothing
                break;
        }

        // make sure angle is within 0-359 range
        angle = (((angle % 360) + 360) % 360);

        // make sure distance is non-negative
        distance = distance < 0.0 ? 0.0 : distance;
    }

    return 0;
}