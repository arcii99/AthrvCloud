//FormAI DATASET v1.0 Category: Robot movement control ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Set random seed
    srand(time(NULL));

    // Print welcome message
    printf("Hello there, I am the cheerful C robot!\n");

    // Generate random movement commands
    int movement_command1 = rand() % 6;
    int movement_command2 = rand() % 6;

    // Declare and initialize position variables
    int x = 0;
    int y = 0;

    // Print starting position
    printf("Starting position: (%d, %d)\n", x, y);

    // Execute movement commands
    switch (movement_command1) {
        case 0:
            printf("Moving north!\n");
            y++;
            break;
        case 1:
            printf("Moving south!\n");
            y--;
            break;
        case 2:
            printf("Moving east!\n");
            x++;
            break;
        case 3:
            printf("Moving west!\n");
            x--;
            break;
        case 4:
            printf("Turning left!\n");
            break;
        case 5:
            printf("Turning right!\n");
            break;
        default:
            printf("Invalid movement command!\n");
            break;
    }

    switch (movement_command2) {
        case 0:
            printf("Moving north!\n");
            y++;
            break;
        case 1:
            printf("Moving south!\n");
            y--;
            break;
        case 2:
            printf("Moving east!\n");
            x++;
            break;
        case 3:
            printf("Moving west!\n");
            x--;
            break;
        case 4:
            printf("Turning left!\n");
            break;
        case 5:
            printf("Turning right!\n");
            break;
        default:
            printf("Invalid movement command!\n");
            break;
    }

    // Print final position
    printf("Final position: (%d, %d)\n", x, y);

    // Print goodbye message
    printf("Thank you for playing with me, have a great day!\n");

    return 0;
}