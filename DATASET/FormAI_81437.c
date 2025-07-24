//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Initializing drone variables
    int altitude = 0;
    int forwardSpeed = 0;
    int rightSpeed = 0;

    // Displaying instructions for the user
    printf("Welcome to the Drone Control Center!\n");
    printf("Use the arrow keys to control the drone:\n");
    printf("Up/Down arrow key: Increase/decrease altitude\n");
    printf("Right/Left arrow key: Increase/decrease forward speed\n");
    printf("Page Up/Page Down key: Increase/decrease right speed\n");
    printf("Press Enter to exit the program.\n\n");

    // Infinite loop to receive user input
    while (1) {
        // Updating drone information
        printf("Altitude: %dm\n", altitude);
        printf("Forward Speed: %dkm/h\n", forwardSpeed);
        printf("Right Speed: %dkm/h\n", rightSpeed);

        // Receiving user input
        int c = getchar();

        // Exit program if user presses Enter
        if (c == '\n') {
            printf("Exiting Drone Control Center.\n");
            break;
        }

        // Handle user input for altitude
        if (c == 27 && getchar() == '[') {
            switch(getchar()) {
                case 'A':
                    altitude++;
                    break;
                case 'B':
                    altitude--;
                    if (altitude < 0) {
                        printf("Drone has crashed! Exiting Drone Control Center.\n");
                        break;
                    }
                    break;
                default:
                    break;
            }
        }

        // Handle user input for forward speed
        if (c == 27 && getchar() == '[') {
            switch(getchar()) {
                case 'C':
                    forwardSpeed++;
                    break;
                case 'D':
                    forwardSpeed--;
                    if (forwardSpeed < 0) {
                        forwardSpeed = 0;
                    }
                    break;
                default:
                    break;
            }
        }

        // Handle user input for right speed
        if (c == 27 && getchar() == '[') {
            switch(getchar()) {
                case 53:
                    rightSpeed++;
                    break;
                case 54:
                    rightSpeed--;
                    if (rightSpeed < 0) {
                        rightSpeed = 0;
                    }
                    break;
                default:
                    break;
            }
        }

        // Clear input buffer
        while (getchar() != '\n');
    }

    return 0;
}