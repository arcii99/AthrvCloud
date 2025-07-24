//FormAI DATASET v1.0 Category: Smart home light control ; Style: intelligent
#include <stdio.h>
#include <stdbool.h>

int main() {
    bool isLightOn = false;
    printf("Welcome to the Smart Home Light Control System!\n");
    while (true) {
        printf("Enter '1' to turn the light on, '0' to turn the light off, or '9' to exit: ");
        int input;
        scanf("%d", &input);
        switch(input) {
            case 0:
                if (isLightOn) {
                    printf("Turning the light off...\n");
                    isLightOn = false;
                }
                else {
                    printf("The light is already off.\n");
                }
                break;
            case 1:
                if (!isLightOn) {
                    printf("Turning the light on...\n");
                    isLightOn = true;
                }
                else {
                    printf("The light is already on.\n");
                }
                break;
            case 9:
                printf("Exiting the Smart Home Light Control System...\n");
                return 0;
            default:
                printf("Invalid input. Please try again.\n");
                break;
        }
    }
}