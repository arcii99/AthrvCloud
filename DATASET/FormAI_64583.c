//FormAI DATASET v1.0 Category: Smart home light control ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isLightsOn = false;

int main() {
    printf("Welcome to Smart Home Light Control Program!\n");
    printf("Enter 1 to turn on lights, 0 to turn off lights, and -1 to exit program.\n");
    while (true) {
        int input;
        scanf("%d", &input);
        if (input == 1) {
            if (!isLightsOn) {
                printf("Turning on lights...\n");
                isLightsOn = true;
            } else {
                printf("Lights are already on.\n");
            }
        } else if (input == 0) {
            if (isLightsOn) {
                printf("Turning off lights...\n");
                isLightsOn = false;
            } else {
                printf("Lights are already off.\n");
            }
        } else if (input == -1) {
            printf("Exiting program...\n");
            break;
        } else {
            printf("Invalid input. Please enter 1, 0, or -1.\n");
        }
    }
    return 0;
}