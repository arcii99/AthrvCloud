//FormAI DATASET v1.0 Category: Smart home light control ; Style: thoughtful
#include <stdio.h>
#include <stdbool.h>

int main() {
    /* initialize variables */
    int lightLevel = 0;
    bool isLightOn = false;
    bool isAutoMode = false;

    /* prompt user for light level */
    printf("Enter desired light level (0-100): ");
    scanf("%d", &lightLevel);

    /* prompt user for light status */
    printf("Turn on light (1 for yes, 0 for no): ");
    scanf("%d", &isLightOn);

    /* prompt user for auto mode status */
    printf("Auto mode on (1 for yes, 0 for no): ");
    scanf("%d", &isAutoMode);

    /* check if auto mode is on */
    if (isAutoMode) {
        /* automatically adjust light level */
        if (lightLevel < 20) {
            printf("Light level is too low. Increasing to 50.\n");
            lightLevel = 50;
        } else if (lightLevel > 80) {
            printf("Light level is too high. Decreasing to 50.\n");
            lightLevel = 50;
        }
    } else {
        /* manually adjust light level */
        printf("Adjusting light level to %d.\n", lightLevel);
    }

    /* check if light is on */
    if (isLightOn) {
        printf("Light is on.\n");
    } else {
        printf("Light is off.\n");
    }

    return 0;
}