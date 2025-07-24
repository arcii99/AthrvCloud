//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: unmistakable
#include <stdio.h>

/**
 * This is a C Drone Remote Control program.
 * It allows the user to control the drone using the keyboard keys.
 * It uses printf to display the current status of the drone.
 **/

int main() {
    int altitude = 0;
    int speed = 0;

    printf("Welcome to C Drone Remote Control program!\n\n");
    printf("Use the following keys:\n");
    printf("   - 'q' to increase altitude.\n");
    printf("   - 'a' to decrease altitude.\n");
    printf("   - 'w' to increase speed.\n");
    printf("   - 's' to decrease speed.\n");
    printf("   - 'e' to exit.\n\n");

    char c;
    do {
        printf("Altitude: %d ft, Speed: %d km/h\n", altitude, speed);
        c = getchar();
        if (c == 'q') {
            altitude += 10;
        } else if (c == 'a') {
            altitude -= 10;
        } else if (c == 'w') {
            speed += 10;
        } else if (c == 's') {
            speed -= 10;
        } else if (c == 'e') {
            printf("Exiting...\n");
        } else {
            printf("Invalid key\n");
        }
        // clear input buffer
        while ((c = getchar()) != '\n' && c != EOF) { }
    } while (c != 'e');

    return 0;
}