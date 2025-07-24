//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: calm
#include <stdio.h>

int main() {
    int power = 0;
    int altitude = 0;
    int x_pos = 0;
    int y_pos = 0;
    int z_pos = 0;

    while (1) {
        printf("Press P to power on/off the drone\n");
        printf("Press U/D to move the drone up/down\n");
        printf("Press L/R to move the drone left/right\n");
        printf("Press F/B to move the drone forward/backward\n");
        printf("Press Q to quit the program\n");

        char input = getchar();

        switch (input) {
            case 'P':
                power = !power;
                printf("Power: %s\n", power ? "ON" : "OFF");
                break;

            case 'U':
                if (power) {
                    altitude += 10;
                    z_pos += 10;
                    printf("Moving up. Altitude: %d, Position: (%d, %d, %d)\n", altitude, x_pos, y_pos, z_pos);
                } else {
                    printf("Please turn on the drone first\n");
                }
                break;

            case 'D':
                if (power) {
                    altitude -= 10;
                    z_pos -= 10;
                    printf("Moving down. Altitude: %d, Position: (%d, %d, %d)\n", altitude, x_pos, y_pos, z_pos);
                } else {
                    printf("Please turn on the drone first\n");
                }
                break;

            case 'L':
                if (power) {
                    x_pos -= 10;
                    printf("Moving left. Position: (%d, %d, %d)\n", x_pos, y_pos, z_pos);
                } else {
                    printf("Please turn on the drone first\n");
                }
                break;

            case 'R':
                if (power) {
                    x_pos += 10;
                    printf("Moving right. Position: (%d, %d, %d)\n", x_pos, y_pos, z_pos);
                } else {
                    printf("Please turn on the drone first\n");
                }
                break;

            case 'F':
                if (power) {
                    y_pos += 10;
                    printf("Moving forward. Position: (%d, %d, %d)\n", x_pos, y_pos, z_pos);
                } else {
                    printf("Please turn on the drone first\n");
                }
                break;

            case 'B':
                if (power) {
                    y_pos -= 10;
                    printf("Moving backward. Position: (%d, %d, %d)\n", x_pos, y_pos, z_pos);
                } else {
                    printf("Please turn on the drone first\n");
                }
                break;

            case 'Q':
                printf("Quitting the program\n");
                return 0;

            default:
                printf("Invalid input. Please try again\n");
                break;
        }
    }
}