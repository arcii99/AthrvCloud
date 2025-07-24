//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int carX = 0, carY = 0, speed = 0, direction = 0;
    char command;
    printf("Welcome to the Remote Control Vehicle Simulation!\n");
    printf("-----------------------------------------------\n");
    printf("Your car is currently at position (%d, %d)\n", carX, carY);
    printf("Enter a command (f = forward, b = backward, l = left, r = right, s = stop): ");

    while (1) {
        scanf(" %c", &command); // space before %c to clear the input buffer
        switch (command) {
            case 'f':
                direction = rand() % 360; // choose a random direction
                speed = rand() % 10 + 1; // choose a random speed between 1 and 10
                carX += (int) (speed * cos(direction * 3.14159 / 180.0)); // update car position based on speed and direction
                carY += (int) (speed * sin(direction * 3.14159 / 180.0));
                printf("Car moved forward to position (%d, %d)\n", carX, carY);
                break;
            case 'b':
                direction = rand() % 360;
                speed = rand() % 10 + 1;
                carX -= (int) (speed * cos(direction * 3.14159 / 180.0));
                carY -= (int) (speed * sin(direction * 3.14159 / 180.0));
                printf("Car moved backward to position (%d, %d)\n", carX, carY);
                break;
            case 'l':
                direction -= 90; // turn left by 90 degrees
                printf("Car turned left to direction %d degrees\n", direction);
                break;
            case 'r':
                direction += 90; // turn right by 90 degrees
                printf("Car turned right to direction %d degrees\n", direction);
                break;
            case 's':
                printf("Car stopped at position (%d, %d)\n", carX, carY);
                exit(0);
            default:
                printf("Invalid command! Please try again.\n");
        }
        printf("Enter a command (f = forward, b = backward, l = left, r = right, s = stop): ");
    }
    return 0;
}