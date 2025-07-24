//FormAI DATASET v1.0 Category: Smart home light control ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Happy Smart Home Light Control Program
int main() {
    int numLights = 5;
    int lightStatus[numLights];

    printf("Welcome to your Smart Home Light Control!\n");
    printf("We currently have %d lights connected.\n", numLights);

    // Turning on all lights by default
    for (int i = 0; i < numLights; i++) {
        lightStatus[i] = 1;
        printf("Light %d turned on.\n", i+1);
    }

    // Giving user options to turn on or off lights
    while (1) {
        printf("\nWould you like to turn a light on or off (y/n)? ");
        char input;
        scanf(" %c", &input);

        if (input == 'y' || input == 'Y') {
            printf("Which light would you like to control (1-%d)? ", numLights);
            int lightNum;
            scanf("%d", &lightNum);

            if (lightNum >= 1 && lightNum <= numLights) {
                // Toggling light status
                lightStatus[lightNum-1] = !lightStatus[lightNum-1];

                if (lightStatus[lightNum-1]) {
                    printf("Light %d turned on.\n", lightNum);
                } else {
                    printf("Light %d turned off.\n", lightNum);
                }
            } else {
                printf("Invalid light number!\n");
            }
        } else if (input == 'n' || input == 'N') {
            printf("Goodbye!\n");
            return 0;
        } else {
            printf("Invalid input!\n");
        }
    }
    return 0;
}