//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the distance between two points
double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    // Initialize variables
    double x1, y1, x2, y2, dist;

    // Ask the user for the starting coordinates
    printf("Enter starting coordinates (x1, y1): ");
    scanf("%lf %lf", &x1, &y1);

    // Ask the user for the destination coordinates
    printf("Enter destination coordinates (x2, y2): ");
    scanf("%lf %lf", &x2, &y2);

    // Calculate the distance traveled
    dist = distance(x1, y1, x2, y2);

    // Initialize remote control variables
    int throttle = 0; // The power of the drone's motor, measured from 0 to 100
    double heading = 0; // The direction that the drone is facing, measured in degrees from 0 to 360
    double altitude = 0; // The height of the drone above the ground, measured in feet
    double speed = 0; // The speed of the drone, measured in feet per second

    // Begin flight
    printf("Flight beginning...\n");

    // Adjust throttle and heading to reach destination
    while (distance(x1, y1, x2, y2) >= 0.1) {
        // Check distance to destination and adjust direction and throttle
        if (x1 < x2) {
            heading = 90;
        } else if (x1 > x2) {
            heading = 270;
        } else {
            heading = 0;
        }

        if (y1 < y2) {
            heading = 0;
        } else if (y1 > y2) {
            heading = 180;
        }

        if (distance(x1, y1, x2, y2) >= 1000) {
            throttle = 100;
        } else if (distance(x1, y1, x2, y2) >= 500) {
            throttle = 75;
        } else if (distance(x1, y1, x2, y2) >= 100) {
            throttle = 50;
        } else {
            throttle = 25;
        }

        // Report current status
        printf("Current status:\n");
        printf("Heading: %.2lf degrees\n", heading);
        printf("Throttle: %d%%\n", throttle);
        printf("Altitude: %.2lf feet\n", altitude);
        printf("Speed: %.2lf feet per second\n", speed);

        // Wait for user input before continuing
        printf("Press ENTER to continue...");
        while (getchar() != '\n');

        // Update position and altitude
        x1 = x1 + (cos(heading) * speed);
        y1 = y1 + (sin(heading) * speed);
        altitude = altitude + (throttle / 10);
        speed = speed + (throttle / 100);

    }

    // Report travel time and distance
    printf("Flight complete!\n");
    printf("Total distance traveled: %.2lf miles\n", dist);
    printf("Time spent in flight: %.2lf minutes\n", (dist / speed) / 60);

    // End program
    return 0;
}