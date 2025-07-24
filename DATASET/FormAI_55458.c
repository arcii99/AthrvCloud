//FormAI DATASET v1.0 Category: Robot movement control ; Style: surprised
#include <stdio.h>

int main() {

    printf("Welcome to the Robot Movement Control Program!\n");
    printf("Please enter the starting position of the robot (X,Y): ");

    int x, y;
    scanf("%d,%d", &x, &y);

    printf("The robot is now at position (%d,%d)\n", x, y);
    printf("Please enter a sequence of movements for the robot: ");

    char movement[100];
    scanf("%s", movement);

    int i = 0;
    while (movement[i] != '\0') {
        char direction = movement[i];
        switch (direction) {
            case 'U':
                y += 1;
                printf("Moving up...\n");
                break;
            case 'D':
                y -= 1;
                printf("Moving down...\n");
                break;
            case 'L':
                x -= 1;
                printf("Moving left...\n");
                break;
            case 'R':
                x += 1;
                printf("Moving right...\n");
                break;
            default:
                printf("Invalid movement: %c\n", direction);
                break;  
        }
        i++;
        printf("The robot is now at position (%d,%d)\n", x, y);
        printf("Enter the next movement (or 'q' to quit): ");
    }
    printf("Exiting the program...\n");
    return 0;
}