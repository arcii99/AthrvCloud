//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: realistic
#include <stdio.h>

// Function to control the drone remotely
void control_drone(int num) {
    switch(num) {
        case 1:
            printf("Drone is going up.\n");
            break;
        case 2:
            printf("Drone is going down.\n");
            break;
        case 3:
            printf("Drone is moving forward.\n");
            break;
        case 4:
            printf("Drone is moving backward.\n");
            break;
        case 5:
            printf("Drone is turning left.\n");
            break;
        case 6:
            printf("Drone is turning right.\n");
            break;
        case 7:
            printf("Drone is taking a picture.\n");
            break;
        case 8:
            printf("Drone is landing.\n");
            break;
        default:
            printf("Invalid command.\n");
    }
}

int main() {
    int command = 0;
    printf("Enter a command to control the drone:\n");
    printf("1 - Go up\n2 - Go down\n3 - Move forward\n4 - Move backward\n5 - Turn left\n6 - Turn right\n7 - Take a picture\n8 - Land\n");
    while(command != 8) {
        scanf("%d", &command);
        control_drone(command);
    }
    printf("Drone has landed.\n");
    return 0;
}