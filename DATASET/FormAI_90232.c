//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

int main() {
    int direction; //0 for forward, 1 for backward, 2 for left, 3 for right
    int speed = 0;
    int batteryLife = 100;
    printf("Welcome to Remote Control Vehicle Simulation Program\n");
    printf("Please select direction:\n0 for forwarding\n1 for backwarding\n2 for moving left\n3 for moving right\n");
    scanf("%d", &direction);
    printf("Please enter speed:\n");
    scanf("%d", &speed);
    printf("Your vehicle is moving %d with speed %d\n", direction, speed);
    if (direction == 0) {
        for (int i = 0; i <= speed; i++) {
            printf("%d: Vehicle is moving forward\n", i);
            batteryLife--;
        }
    } else if (direction == 1) {
        for (int i = 0; i <= speed; i++) {
            printf("%d: Vehicle is moving backward\n", i);
            batteryLife--;
        }
    } else if (direction == 2) {
        for (int i = 0; i <= speed; i++) {
            printf("%d: Vehicle is moving left\n", i);
            batteryLife--;
        }
    } else if (direction == 3) {
        for (int i = 0; i <= speed; i++) {
            printf("%d: Vehicle is moving right\n", i);
            batteryLife--;
        }
    } else {
        printf("Invalid direction selected\n");
    }
    printf("Your vehicle's battery life is at %d%%\n", batteryLife);
    return 0;
}