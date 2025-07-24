//FormAI DATASET v1.0 Category: Smart home light control ; Style: mathematical
#include <stdio.h>

// Function to check if the light is on or off
int isLightOn(int lightStatus) {
    return lightStatus == 1;
}

// Function to switch the light on or off
int switchLight(int lightStatus) {
    return lightStatus == 1 ? 0 : 1;
}

int main() {
    int lightStatus = 0; // 0 represents off, 1 represents on
    int input;

    printf("Enter 1 to switch the light on, 2 to switch the light off, 3 to check if the light is on, and 4 to exit\n");

    while (1) {
        scanf("%d", &input);

        if (input == 1) {
            lightStatus = switchLight(lightStatus);
            printf("Light switched on\n");
        }
        else if (input == 2) {
            lightStatus = switchLight(lightStatus);
            printf("Light switched off\n");
        }
        else if (input == 3) {
            if (isLightOn(lightStatus)) {
                printf("The light is on\n");
            }
            else {
                printf("The light is off\n");
            }
        }
        else if (input == 4) {
            printf("Exiting...\n");
            break;
        }
        else {
            printf("Invalid input\n");
        }
    }

    return 0;
}