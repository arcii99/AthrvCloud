//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: beginner-friendly
#include <stdio.h>

// Initialize drone location
int drone_x = 0;
int drone_y = 0;

// Function to move drone
void move_drone(char direction, int distance) {
    switch(direction) {
        case 'N':
            drone_y += distance;
            break;
        case 'S':
            drone_y -= distance;
            break;
        case 'E':
            drone_x += distance;
            break;
        case 'W':
            drone_x -= distance;
            break;
        default:
            printf("Invalid direction.\n");
            break;
    }
}

int main() {
    char command;
    int distance;
    printf("Enter your command (e.g. 'N 5' to move the drone North by 5 units):\n");
    scanf("%c %d", &command, &distance);
    move_drone(command, distance);
    printf("New location: (%d, %d)", drone_x, drone_y);
    return 0;
}