//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: Alan Touring
#include <stdio.h>

int main() {
    int altitude = 0;
    int direction = 0;

    while (1) {
        printf("Drone Status: Altitude = %d meters, Direction = %d degrees\n", altitude, direction);
        printf("Enter a command (a = increase altitude, s = decrease altitude, d = turn right, w = turn left): ");
        char command = getchar();

        switch (command) {
            case 'a':
                altitude++;
                break;
            case 's':
                altitude--;
                break;
            case 'd':
                direction += 15;
                break;
            case 'w':
                direction -= 15;
                break;
            default:
                printf("\nInvalid command. Please try again.\n\n");
                break;
        }
        getchar(); // flush the input buffer

        if (altitude < 0) {
            printf("\nDrone has crashed. Game Over.\n");
            break;
        }
    }

    return 0;
}