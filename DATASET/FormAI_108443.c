//FormAI DATASET v1.0 Category: Robot movement control ; Style: scalable
#include <stdio.h>

// function to move forward
void moveForward(int speed) {
    printf("Moving forward with speed %d\n", speed);
}

// function to move backward
void moveBackward(int speed) {
    printf("Moving backward with speed %d\n", speed);
}

// function to turn left
void turnLeft(int angle) {
    printf("Turning left by %d degrees\n", angle);
}

// function to turn right
void turnRight(int angle) {
    printf("Turning right by %d degrees\n", angle);
}

int main() {
    int speed = 50; // set initial speed
    int angle = 90; // set initial angle
    int choice = 0; // variable to store user's choice

    while (1) {
        printf("Choose an option:\n");
        printf("1. Move forward\n");
        printf("2. Move backward\n");
        printf("3. Turn left\n");
        printf("4. Turn right\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter speed: ");
                scanf("%d", &speed);
                moveForward(speed);
                break;
            case 2:
                printf("Enter speed: ");
                scanf("%d", &speed);
                moveBackward(speed);
                break;
            case 3:
                printf("Enter angle: ");
                scanf("%d", &angle);
                turnLeft(angle);
                break;
            case 4:
                printf("Enter angle: ");
                scanf("%d", &angle);
                turnRight(angle);
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
}