//FormAI DATASET v1.0 Category: Smart home light control ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Smart Home Light Control Example Program */
/* Made by an Energetic Chatbot */

int main() {
    int brightness = 0;
    char command[20];

    printf("Welcome to the Smart Home Light Control Program!\n");
    printf("Please enter 'on' to turn the light on, 'off' to turn it off, and 'brighten' or 'dim' to adjust brightness:\n");

    while (1) {
        scanf("%s", command);
        if (strcmp(command, "on") == 0) {
            brightness = 100;
            printf("Light is turned on!\n");
        } else if (strcmp(command, "off") == 0) {
            brightness = 0;
            printf("Light is turned off!\n");
        } else if (strcmp(command, "brighten") == 0) {
            brightness += 10;
            if (brightness > 100) {
                brightness = 100;
            }
            printf("Light is brightened to %d%%\n", brightness);
        } else if (strcmp(command, "dim") == 0) {
            brightness -= 10;
            if (brightness < 0) {
                brightness = 0;
            }
            printf("Light is dimmed to %d%%\n", brightness);
        } else {
            printf("Invalid command! Please enter 'on', 'off', 'brighten', or 'dim'.\n");
        }
    }

    return 0;
}

/* End of Smart Home Light Control Program */