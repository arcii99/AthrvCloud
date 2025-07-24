//FormAI DATASET v1.0 Category: Smart home light control ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

int main() {
    int lightStatus = 0;
    int brightness = 50;

    printf("Welcome to the Smart Home Light Control Program!\n");
    printf("The light is currently turned off.\n");

    while (1) {
        char input;

        printf("Enter '1' to turn the light on, '2' to turn it off, or '3' to adjust the brightness: ");
        scanf(" %c", &input);

        if (input == '1') {
            if (lightStatus == 0) {
                lightStatus = 1;
                printf("Turning on the light.\n");
            } else {
                printf("The light is already on.\n");
            }
        } else if (input == '2') {
            if (lightStatus == 1) {
                lightStatus = 0;
                printf("Turning off the light.\n");
            } else {
                printf("The light is already off.\n");
            }
        } else if (input == '3') {
            printf("Enter the desired brightness (0-100): ");
            scanf("%d", &brightness);

            if (brightness < 0) {
                brightness = 0;
            } else if (brightness > 100) {
                brightness = 100;
            }

            printf("Setting brightness to %d.\n", brightness);
        } else {
            printf("Invalid input. Try again.\n");
        }
    }

    return 0;
}