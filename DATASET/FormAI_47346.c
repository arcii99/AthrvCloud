//FormAI DATASET v1.0 Category: Smart home light control ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LIGHTS 10

typedef struct {
    bool on;
    int brightness;
} Light;

int main() {
    Light lights[MAX_LIGHTS];

    for (int i = 0; i < MAX_LIGHTS; i++) {
        lights[i].on = false;
        lights[i].brightness = 0;
    }

    char command[20]; // Buffer to store user input

    while (true) {
        printf("Enter command (e.g. 'on 1', 'off 2', 'dim 3 50'): ");
        fgets(command, sizeof(command), stdin);

        // Parse user input
        char* token = strtok(command, " ");
        int light_num = -1;
        int brightness = -1;

        if (strcmp(token, "on") == 0) {
            token = strtok(NULL, " ");
            sscanf(token, "%d", &light_num);

            if (light_num < 1 || light_num > MAX_LIGHTS) {
                printf("Invalid light number\n");
                continue;
            }

            lights[light_num - 1].on = true;
            printf("Light %d turned on\n", light_num);
        }
        else if (strcmp(token, "off") == 0) {
            token = strtok(NULL, " ");
            sscanf(token, "%d", &light_num);

            if (light_num < 1 || light_num > MAX_LIGHTS) {
                printf("Invalid light number\n");
                continue;
            }

            lights[light_num - 1].on = false;
            printf("Light %d turned off\n", light_num);
        }
        else if (strcmp(token, "dim") == 0) {
            token = strtok(NULL, " ");
            sscanf(token, "%d", &light_num);

            if (light_num < 1 || light_num > MAX_LIGHTS) {
                printf("Invalid light number\n");
                continue;
            }

            token = strtok(NULL, " ");
            sscanf(token, "%d", &brightness);

            if (brightness < 0 || brightness > 100) {
                printf("Invalid brightness percentage\n");
                continue;
            }

            lights[light_num - 1].brightness = brightness;
            printf("Light %d dimmed to %d%% brightness\n", light_num, brightness);
        }
        else {
            printf("Invalid command\n");
        }
    }

    return 0;
}