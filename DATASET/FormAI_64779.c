//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: creative
#include <stdio.h>

int main() {
    printf("Welcome to the C Drone Remote Control Program!\n");

    int altitude = 0;
    while (1) {
        printf("\nCurrent altitude: %d meters\n", altitude);
        printf("Enter command: ");
        char command = getchar();
        while (getchar() != '\n'); // clear input buffer

        if (command == '+') {
            altitude += 10;
            if (altitude > 100) {
                printf("WARNING: Altitude over 100 meters!\n");
            }
        } else if (command == '-') {
            altitude -= 10;
            if (altitude < 0) {
                printf("WARNING: Altitude below 0 meters!\n");
            }
        } else if (command == 'f') {
            printf("Moving forward...\n");
        } else if (command == 'b') {
            printf("Moving backward...\n");
        } else if (command == 'l') {
            printf("Turning left...\n");
        } else if (command == 'r') {
            printf("Turning right...\n");
        } else if (command == 'q') {
            printf("Quitting program...\n");
            break;
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }

    printf("\nThank you for using the C Drone Remote Control Program!\n");
    return 0;
}