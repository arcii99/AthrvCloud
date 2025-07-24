//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISTANCE 100
#define MAX_ANGLE 360
#define MAX_SPEED 75

int main() {
    srand(time(NULL));

    float current_lat = 0.0f;
    float current_long = 0.0f;
    float desired_lat = 0.0f;
    float desired_long = 0.0f;
    float distance = 0.0f;
    int angle = 0;
    int speed = 0;
    char direction;

    printf("Enter desired latitude: ");
    scanf("%f", &desired_lat);
    printf("Enter desired longitude: ");
    scanf("%f", &desired_long);

    while (distance > 0 || direction != 's') {
        distance = sqrt(pow(desired_lat - current_lat, 2) + pow(desired_long - current_long, 2));
        printf("Distance to destination: %.2f miles\n", distance);

        // randomly change angle and speed
        angle = rand() % MAX_ANGLE;
        speed = rand() % MAX_SPEED;

        // update latitude and longitude based on angle and speed
        current_lat += (speed * sin(angle));
        current_long += (speed * cos(angle));

        // determine direction based on angle
        if (angle >= 0 && angle < 90) {
            direction = 'ne';
        } else if (angle >= 90 && angle < 180) {
            direction = 'se';
        } else if (angle >= 180 && angle < 270) {
            direction = 'sw';
        } else {
            direction = 'nw';
        }

        printf("Current location: %.2f,%.2f, heading %c at %d mph.\n", current_lat, current_long, direction, speed);
    }

    printf("You have arrived at your destination. Goodbye!\n");

    return 0;
}