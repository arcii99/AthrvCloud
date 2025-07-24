//FormAI DATASET v1.0 Category: Smart home light control ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define NUM_OF_LIGHTS 5

int main() {

    int lights_status[NUM_OF_LIGHTS] = {0}; // Initialize all lights to off (0)

    while(1) { // Loop forever
        
        // Print current status of lights
        printf("Current light status: ");
        for(int i=0; i<NUM_OF_LIGHTS; i++) {
            if(lights_status[i] == 0) {
                printf("OFF ");
            } else {
                printf("ON ");
            }
        }
        printf("\n");

        // Ask user for light to toggle
        printf("Enter light to toggle (1-%d): ", NUM_OF_LIGHTS);
        int light_num;
        scanf("%d", &light_num);

        if(light_num < 1 || light_num > NUM_OF_LIGHTS) {
            printf("Invalid light number\n");
            continue;
        }

        // Toggle light
        if(lights_status[light_num-1] == 0) {
            lights_status[light_num-1] = 1;
        } else {
            lights_status[light_num-1] = 0;
        }
    }

    return 0;
}