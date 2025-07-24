//FormAI DATASET v1.0 Category: Smart home light control ; Style: ultraprecise
#include <stdio.h>
#include <stdbool.h>

#define NUM_LIGHTS 4

bool lights[NUM_LIGHTS] = {false, false, false, false};

void toggle_light(int light_num) {
    lights[light_num] = !lights[light_num];
    printf("Light %d is now %s\n", light_num, (lights[light_num] ? "on" : "off"));
}

int main() {
    printf("Welcome to the Smart Home Light Control System!\n");

    while (true) {
        printf("Enter the number of the light you want to control (1-4), or enter 0 to exit: ");
        int light_num;
        scanf("%d", &light_num);

        if (light_num == 0) {
            printf("Exiting...\n");
            break;
        } else if (light_num < 1 || light_num > NUM_LIGHTS) {
            printf("Invalid light number. Please enter a number between 1 and 4.\n");
            continue;
        }

        toggle_light(light_num - 1);
    }

    return 0;
}