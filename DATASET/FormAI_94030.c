//FormAI DATASET v1.0 Category: Robot movement control ; Style: minimalist
#include <stdio.h>

// Define constants for robot movement control
#define MOVE_FORWARD 1
#define MOVE_BACKWARD 2
#define TURN_LEFT 3
#define TURN_RIGHT 4
#define STOP 5

// Define function to control robot movement based on input command
void moveRobot(int command) {
    switch (command) {
        case MOVE_FORWARD:
            printf("Robot moving forward...\n");
            break;
        case MOVE_BACKWARD:
            printf("Robot moving backward...\n");
            break;
        case TURN_LEFT:
            printf("Robot turning left...\n");
            break;
        case TURN_RIGHT:
            printf("Robot turning right...\n");
            break;
        case STOP:
            printf("Robot stopped.\n");
            break;
        default:
            printf("Invalid command.\n");
            break;
    }
}

int main() {
    int input = -1;
    
    // Loop to receive user input and control robot movement
    while (input != STOP) {
        printf("\nEnter command (1=move forward, 2=move backward, 3=turn left, 4=turn right, 5=stop): ");
        scanf("%d", &input);
        moveRobot(input);
    }
    
    return 0;
}