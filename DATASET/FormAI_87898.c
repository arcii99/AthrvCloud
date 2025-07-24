//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: Alan Touring
#include <stdio.h>

#define MAX_DISTANCE 100
#define MIN_DISTANCE 0
#define MAX_HEIGHT 50
#define MIN_HEIGHT 0

int main() {
    int distance = MIN_DISTANCE;
    int height = MIN_HEIGHT;

    printf("Welcome to the Drone Remote Control program!\n");
    printf("Use the arrow keys to move the drone.\n");
    printf("Press Q to quit.\n");

    while (1) {
        char c = getchar();

        if (c == 'q' || c == 'Q') {
            printf("Exiting program...");
            break;
        } else if (c == 'w' || c == 'W') {
            // Move forward
            if (distance < MAX_DISTANCE) {
                distance++;
                printf("Moving forward. Distance: %d\n", distance);
            } else {
                printf("Maximum distance reached.\n");
            }
        } else if (c == 's' || c == 'S') {
            // Move backward
            if (distance > MIN_DISTANCE) {
                distance--;
                printf("Moving backward. Distance: %d\n", distance);
            } else {
                printf("Minimum distance reached.\n");
            }
        } else if (c == 'a' || c == 'A') {
            // Move left
            printf("Moving left.\n");
        } else if (c == 'd' || c == 'D') {
            // Move right
            printf("Moving right.\n");
        } else if (c == 'u' || c == 'U') {
            // Increase height
            if (height < MAX_HEIGHT) {
                height++;
                printf("Increasing height. Height: %d\n", height);
            } else {
                printf("Maximum height reached.\n");
            }
        } else if (c == 'j' || c == 'J') {
            // Decrease height
            if (height > MIN_HEIGHT) {
                height--;
                printf("Decreasing height. Height: %d\n", height);
            } else {
                printf("Minimum height reached.\n");
            }
        }
    }

    return 0;
}