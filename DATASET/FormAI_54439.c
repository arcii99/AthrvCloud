//FormAI DATASET v1.0 Category: Robot movement control ; Style: portable
#include <stdio.h>
#include <stdbool.h>

#define FORWARD  1
#define BACKWARD 0
#define LEFT     1
#define RIGHT    0

void move_forward(int speed) {
    // Code to move the robot forward at given speed
    printf("Moving forward at speed: %d\n", speed);
}

void move_backward(int speed) {
    // Code to move the robot backward at given speed
    printf("Moving backward at speed: %d\n", speed);
}

void turn_left(int degrees) {
    // Code to turn the robot left by given degrees
    printf("Turning left by %d degrees\n", degrees);
}

void turn_right(int degrees) {
    // Code to turn the robot right by given degrees
    printf("Turning right by %d degrees\n", degrees);
}

int main(void) {
    bool direction = FORWARD; // Start moving forward by default
    int speed = 50; // Start at a moderate speed
    int degrees = 90; // Turn 90 degrees by default

    // Keep moving until interrupted
    while (true) {
        // Check for user input
        int input = getchar();

        switch (input) {
            case 'f': // Move forward
                move_forward(speed);
                break;
            case 'b': // Move backward
                move_backward(speed);
                break;
            case 'l': // Turn left
                turn_left(degrees);
                break;
            case 'r': // Turn right
                turn_right(degrees);
                break;
            case 'd': // Switch direction (forward/backward)
                direction = !direction;
                printf("Switching direction to %s\n", direction ? "forward" : "backward");
                break;
            case 's': // Decrease speed
                if (speed > 0) {
                    speed -= 10;
                    printf("Decreasing speed to %d\n", speed);
                } else {
                    printf("Already at minimum speed\n");
                }
                break;
            case 'a': // Increase speed
                if (speed < 100) {
                    speed += 10;
                    printf("Increasing speed to %d\n", speed);
                } else {
                    printf("Already at maximum speed\n");
                }
                break;
            case 'c': // Change turn angle (left/right)
                degrees = (degrees == 90) ? 45 : 90;
                printf("Changing turn angle to %d degrees\n", degrees);
                break;
            default:
                printf("Invalid input\n");
                break;
        }
    }

    return 0;
}