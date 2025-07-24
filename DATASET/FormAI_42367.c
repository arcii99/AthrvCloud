//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: visionary
// C Remote Control Vehicle Simulation
// by [insert your name here]

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int battery_level = 100;
    int position_x = 0;
    int position_y = 0;
    int speed = 0;
    int direction = 0;
    int distance_traveled = 0;

    srand(time(NULL));

    printf("Welcome to the Remote Control Vehicle Simulation!\n");
    printf("Battery level: %d%%\n", battery_level);

    while (battery_level > 0) {
        int action = rand() % 3; // randomly choose an action: 0 = move forward, 1 = move backward, 2 = change direction

        switch (action) {
            case 0: // move forward
                speed = rand() % 10; // randomly set speed between 0 and 9 mph
                distance_traveled += speed;
                position_x += speed * sin(direction);
                position_y += speed * cos(direction);
                printf("Moving forward at %d mph\n", speed);
                break;

            case 1: // move backward
                if (distance_traveled > 0) {
                    speed = rand() % 5; // randomly set speed between 0 and 4 mph
                    distance_traveled -= speed;
                    position_x -= speed * sin(direction);
                    position_y -= speed * cos(direction);
                    printf("Moving backward at %d mph\n", speed);
                } else {
                    printf("Cannot move backward - already at starting position\n");
                }
                break;

            case 2: // change direction
                direction = rand() % 360; // randomly set direction between 0 and 359 degrees
                printf("Changing direction to %d degrees\n", direction);
                break;
        }

        battery_level -= distance_traveled / 10; // decrease battery level in proportion to distance traveled
        printf("Battery level: %d%%\n", battery_level);
        printf("Position: (%d, %d)\n", position_x, position_y);
    }

    printf("Battery depleted - simulation ended\n");

    return 0;
}